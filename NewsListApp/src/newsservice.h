#ifndef NEWSSERVICE_H
#define NEWSSERVICE_H

#include <QObject>
#include "networkclient.h"
#include "QFutureWatcher"
#include "data/restapitypes.h"
#include "data/LoadNewsResponse.h"
#include "data/LoadNewsRequest.h"
#include "functional"

using namespace std;

class NewsService : public QObject
{
    Q_OBJECT
    NetworkClient* networkClient;
public:
    explicit NewsService(QObject *parent = nullptr);
    void loadNews(QString query, QObject * lifecycle, std::function<void(NewsList)> onResult, std::function<void(RestError)> onError);
};

#endif // NEWSSERVICE_H
