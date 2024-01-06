#include "newsitemvm.h"

NewsItemVM::NewsItemVM(QObject *parent, NewsItem *data): QObject(parent), item {data} {

};
void NewsItemVM::start() {
   emit newsItemLoaded(this->item);
};
