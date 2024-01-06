#include "newsservice.h"
#include "data/LoadNewsRequest.h"
#include "data/NewsList.h"
#include "data/LoadNewsResponse.h"
#include "data/restapitypes.h"
NewsService::NewsService(QObject *parent) : QObject(parent), networkClient {
                                                                new  NetworkClient(this)
                                                                 }
{
qDebug();
}

void NewsService::loadNews(QString query, QObject * lifecycle, std::function<void(NewsList)> onResult, std::function<void(RestError)> onError) {

  auto resultResponse = networkClient ->executeRequest<LoadNewsResponse>(LoadNewsRequest(query));
  resOrErr(resultResponse, lifecycle, [=](LoadNewsResponse *response) {
      qDebug() << "response";
      qDebug() << response;
onResult(response->newsList);
  }, [=](auto *error){
      qDebug() << error;
  }
  );
};
