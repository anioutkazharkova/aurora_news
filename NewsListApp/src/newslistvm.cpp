#include "newslistvm.h"
#include "data/restapitypes.h"
#include "data/LoadNewsResponse.h"
#include "QQmlListProperty"
NewsListVM::NewsListVM(QObject *parent) : QAbstractListModel(parent), service{new NewsService(this)}
{

}

void NewsListVM::loadNews(QString query) {
    auto response = [=](NewsList newsList) {
        beginResetModel();
       newsItems = move(newsList.articles);
      emit this->responseReceived(newsList);
        endResetModel();
      /*for(int i=0;i<newsItems.size();i++) {
        _data->append(&newsItems[i]);
        }*/
        emit listChanged();
};
    service->loadNews(query, this, response, {});
};
/*
QQmlListProperty<NewsItem> NewsListVM::getList(){
    return QQmlListProperty(this, *_data);
}
*/
