#ifndef CUSTOMCPPCLASSES_H
#define CUSTOMCPPCLASSES_H

#endif // CUSTOMCPPCLASSES_H
#include <QtQuick>
#include "newsservice.h"
#include "networkclient.h"
#include "newslistvm.h"
#include "newsitemvm.h"
#include "QQmlListProperty"
#include "DI.h"

Q_DECLARE_METATYPE(NewsItem)
namespace CustomCppClasses {
    void registerModuleInQml() {
        qmlRegisterType<DIProvider>("CustomCppClasses.Module", 1, 0, "DIProvider");
        qmlRegisterType<NewsService>("CustomCppClasses.Module", 1, 0, "NewsService");
        qmlRegisterType<NetworkClient>("CustomCppClasses.Module", 1, 0, "NetworkClient");
        qmlRegisterType<NewsListVM>("CustomCppClasses.Module", 1, 0, "NewsListVM");
        qmlRegisterType<NewsItemVM>("CustomCppClasses.Module", 1, 0, "NewsItemVM");
    }
}
