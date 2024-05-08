#include "item.h"

Item::Item() {}
void Item:: AddItem(QString n, QString descript, int x ){
    name=n;
    description= descript;
    quantity=x;
}
