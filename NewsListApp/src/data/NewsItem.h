#ifndef NEWSITEM_H
#define NEWSITEM_H

#include "QString"
#include "QJsonObject"
#include <stdlib.h>
#include <experimental/optional>
#include <optional>
#include "QObject"
#include <QVariant>
using namespace std;

struct NewsItem {
   optional<QString> author;
    optional<QString> title;
    optional<QString> description;
    optional<QString> url;
   optional<QString> urlToImage;
    optional<QString> publishedAt;
  optional<QString> content;

  // default constructor to make it work with variant
  explicit NewsItem()
      : author { "" }
      , title { "" }
      , description { "" }
      , url { "" }
      , urlToImage {""}
      , publishedAt {""}
      , content {""}
  {};

  explicit NewsItem(QJsonObject const & json)
      : author { json["author"].toString() }
      , title { json["title"].toString() }
      , description { json["description"].toString() }
      , url { json["url"].toString() }
      , urlToImage {json["urlToImage"].toString()}
      , publishedAt {json["publishedAt"].toString()}
      , content { json["content"].toString()}
  {};

  explicit NewsItem(const QObject *object)
      :author {
      object->property("author").toString()
}, title {
        object->property("title").toString()
}, url {
        object->property("url").toString()
}, urlToImage {
        object->property("urlToImage").toString()
}, publishedAt {
        object->property("publishedAt").toString()
},  content {
        object->property("content").toString()
}
  {};
};

#endif // NEWSITEM_H
