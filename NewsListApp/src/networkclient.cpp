#include "networkclient.h"
#include "QNetworkReply"
#include "QJsonDocument"
#include "QtConcurrent/QtConcurrent"


NetworkClient::NetworkClient(QObject *parent) : QObject(parent), manager { new QNetworkAccessManager(this) }
{

}
