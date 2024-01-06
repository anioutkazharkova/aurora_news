#ifndef NEWSLISTVM_H
#define NEWSLISTVM_H

#include <QObject>
#include "QAbstractListModel"
#include "newsservice.h"
#include "QQmlListProperty"
class NewsListVM : public QAbstractListModel
{
    Q_OBJECT
  //  Q_PROPERTY(QObject * parent READ parent WRITE setParent)
    //Q_PROPERTY(QQmlListProperty<NewsItem> data READ getList NOTIFY listChanged)

    NewsService *service;
public:
    explicit NewsListVM(QObject *parent = nullptr);
// QQmlListProperty<NewsItem> getList();
    vector<NewsItem> newsItems;
    enum Roles {
        Title = Qt::UserRole + 1,
        Content = Qt::UserRole + 2,
        Description = Qt::UserRole + 3,
        ImageUrl = Qt::UserRole + 4,
        Date = Qt::UserRole + 5,
        Url = Qt::UserRole + 6,
        Author = Qt::UserRole + 7
    };
    Q_ENUM(Roles)
int rowCount(const QModelIndex &) const override { return newsItems.size(); }
QVariant data(const QModelIndex &index, int role) const override {
    auto item = newsItems[index.row()];
    switch (role) {
    case Title: {
        return QVariant(item.title.has_value() ? item.title.value() : ""); break;
    }
    case Url: {
        return QVariant(item.url.has_value() ? item.url.value() : ""); break;
    }
    case ImageUrl: {
        return QVariant(item.urlToImage.has_value() ? item.urlToImage.value() : ""); break;
    }
    case Content: {
        return QVariant(item.content.has_value() ? item.content.value() : ""); break;
    }
    case Author: {
        return QVariant(item.author.has_value() ? item.author.value() : ""); break;
    }
    case Date: {
        return QVariant(item.publishedAt.has_value() ? item.publishedAt.value() : ""); break;
    }
    }
    return QVariant();
};
QHash<int, QByteArray> roleNames() const override {
    QHash<int, QByteArray> roles;
    roles[Title] = "title";
    roles[Url] = "url";
    roles[ImageUrl] = "urlToImage";
    roles[Date] = "publishedAt";
    roles[Content] = "content";
    roles[Author] = "author";
    return roles;
}

    ~NewsListVM(){}
public slots:
    void loadNews(QString query);
private:
    QList<NewsItem *> *_data;
signals:
    void responseReceived(const NewsList &response);
    void errorOccurred(const RestError &errorMessage);
    void listChanged();
void openNewsItem(QObject *item);
};

#endif // NEWSLISTVM_H
//Q_DECLARE_METATYPE(QList<NewsItem>)
//Q_DECLARE_METATYPE(QQmlListProperty<NewsItem>)
