#ifndef ITEMM_H
#define ITEMM_H
#include <QString>

class item
{
public:
    item();
    QString name;
    QString description;
    QString category;
    int quantity;
    int price;
};

#endif // ITEMM_H
