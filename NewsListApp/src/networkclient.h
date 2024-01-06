#ifndef NETWORKCLIENT_H
#define NETWORKCLIENT_H
#include "QObject"
#include "QNetworkAccessManager"
#include "data/restapitypes.h"
#include "QJsonDocument"
#include "QNetworkRequest"
#include "QNetworkReply"
#include "QtConcurrent/QtConcurrent"
using namespace std;

class NetworkClient : public QObject {
    Q_OBJECT
    QNetworkAccessManager *manager;
    QString endpoint = "https://newsapi.org/v2/";
    QString apiKey = "5b86b7593caa4f009fea285cc74129e2";
public:
    explicit NetworkClient(QObject *parent = nullptr);

    template<class T, typename=enable_if_t<is_base_of<RestApiResponse,T>::value>>
    RestResultWatcher<T> * executeRequest(RestApiRequest const & request) {
        QNetworkRequest networkRequest;
            auto header = apiKey.toUtf8();
            networkRequest.setRawHeader("X-Api-Key", header);
        networkRequest.setUrl(endpoint + request.endpoint());
        networkRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    RestResultWatcher<T> *watcher = new RestResultWatcher<T>();
        QNetworkReply *reply;
        switch (request.reqType()) {
        case RestReqType::GET:
            reply = manager->get(networkRequest);
            break;
        case RestReqType::POST:
            QJsonObject obj;
            request.fill(obj);
            QJsonDocument doc(obj);
            QByteArray data = doc.toJson();
            reply = manager->post(networkRequest, data);
            break;
        }

        connect(reply, &QNetworkReply::finished, this, [watcher, reply]() {
            QByteArray content = reply->readAll();
            auto jdReply = QJsonDocument::fromJson(content);
            if (jdReply.isNull()) {
                auto f = QtConcurrent::run([](){
                    return RestResult<T>(RestError::NullResponse);
                });
                watcher->setFuture(f);
                return;
            }

            if (jdReply.isEmpty()) {
                auto f = QtConcurrent::run([](){
                    return RestResult<T>(RestError::EmptyJsonResponse);
                });
                watcher->setFuture(f);
                return;
            }

            auto f = QtConcurrent::run([](QJsonDocument const &jd){
                    // TODO: probably mem usage might be imporved here with ptrs or refs
                    auto model = T();
                    auto result = model.parse(jd);
                    if (result) {
                        return RestResult<T>(model);
                    } else {
                        qDebug() << model.error();
                        return RestResult<T>(RestError::JsonParsingError);
                    }
            }, jdReply);

            watcher->setFuture(f);
        });

        connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), this, [reply, watcher](){
            qDebug() << "request error: " << reply->errorString();
            auto f = QtConcurrent::run([](){
                return RestResult<T>(RestError::NetworkError);
            });
            watcher->setFuture(f);
        });

        connect(reply, &QNetworkReply::sslErrors, this, [reply, watcher]() {
            qDebug() << "request sslErrors: " << reply->errorString();
            auto f = QtConcurrent::run([](){
                return RestResult<T>(RestError::SslError);
            });
            watcher->setFuture(f);
        });

        return watcher;
    }

    ~NetworkClient() {
        delete manager;
    }
};

#endif // NETWORKCLIENT_H
