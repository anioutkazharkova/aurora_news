#ifndef DI_H
#define DI_H
#include "QObject"
#include "newsitemvm.h"
#include "newslistvm.h"
#include "data/NewsItem.h"

class DIProvider :  public QObject
{
    Q_OBJECT
public:
    explicit DIProvider(QObject *parent = nullptr): QObject(parent) {

    }
   ~DIProvider(){}
    Q_INVOKABLE NewsListVM* getNewsListVM() {
        return new NewsListVM();
    }
    Q_INVOKABLE NewsItemVM* getNewsItemVM(const QObject *item) {
        auto *model = new NewsItemVM(nullptr, new NewsItem(item));
        return model;
    }
};
#endif // DI_H
