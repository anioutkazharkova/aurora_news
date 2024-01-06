#ifndef LOADNEWSRESPONSE_H
#define LOADNEWSRESPONSE_H
#include "restapitypes.h"
#include "NewsList.h"
#include "QJsonDocument"

struct LoadNewsResponse: public RestApiResponse {
    NewsList newsList;
    QString errorMsg = "";

    // required to make it work with variant
    explicit LoadNewsResponse() {};

    bool parse(const QJsonDocument &jd) override {
        auto jo = jd.object();
        if (jo.isEmpty()) { return false; }
        if (jo.contains("error")) {
            errorMsg = jo["error"].toString();
            return false;
        }
        newsList = NewsList(jo);
        return true;
    }

    QString const & error() const override { return errorMsg; }
};
#endif // LOADNEWSRESPONSE_H
