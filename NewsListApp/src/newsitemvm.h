#ifndef NEWSITEMVM_H
#define NEWSITEMVM_H

#include <QObject>
#include "data/NewsItem.h"
using namespace std;

class NewsItemVM : public QObject
{
    Q_OBJECT
    Q_PROPERTY(NewsItem * data READ data WRITE setData)
    Q_PROPERTY(QString title READ title)
    Q_PROPERTY(QString urlToImage READ urlToImage)
    Q_PROPERTY(QString content READ content)
    Q_PROPERTY(QString url READ url)
    Q_PROPERTY(QString publishedAt READ publishedAt)
public:
    explicit NewsItemVM(QObject *parent = nullptr, NewsItem *data = nullptr);

    QString title() const {return item->title.has_value() ? item->title.value() : "";};
    QString url() const {return item->url.has_value() ? item->url.value() : "";};
    QString urlToImage() const {return item->urlToImage.has_value() ? item->urlToImage.value() : "";};
    QString content() const {return item->content.has_value() ? item->content.value() : "";};
    QString publishedAt() const {return item->publishedAt.has_value() ? item->publishedAt.value() : "";};

    NewsItem *item;
    NewsItem* data() const  {return item;};
    void setData(NewsItem *data) {
        item = data;
    };
signals:
    void newsItemLoaded(NewsItem *item);
public slots:
    void start();
};

#endif // NEWSITEMVM_H
