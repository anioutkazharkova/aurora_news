#ifndef LOADNEWSREQUEST_H
#define LOADNEWSREQUEST_H
#include "QObject"
#include "restapitypes.h"

struct LoadNewsRequest : public RestApiRequest {
    QString _endpoint ="everything";
    QString query = "";

    RestReqType reqType() const override { return RestReqType::GET; };

    void fill(QJsonObject &) const override {};

    explicit LoadNewsRequest(QString query) {
        this->query = query;
    };

public:
    QString endpoint() const override {
        return _endpoint +"?q=" + query;
    };
};

#endif // LOADNEWSREQUEST_H
