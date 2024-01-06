#ifndef NEWSLIST_H
#define NEWSLIST_H
#include "NewsItem.h"
#include "QVector"
#include "QJsonArray"

struct NewsList {
    vector <NewsItem> articles;

    explicit NewsList() {
        articles.reserve(0);
    }

    explicit NewsList(QJsonObject const & json){
       QJsonArray data = json["articles"].toArray();
       articles.reserve(data.size());
       int index = 0;
       foreach (const QJsonValue & value, data) {
           QJsonObject obj = value.toObject();
           articles.insert(articles.end(),NewsItem(obj));
           index += 1;
       }
    };
};
#endif // NEWSLIST_H
