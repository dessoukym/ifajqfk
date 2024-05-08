#ifndef PRODUCTS_H
#define PRODUCTS_H
#include "additem.cpp"
#include <QVector>
#include <QDialog>

namespace Ui {
class products;
}

class products : public QDialog
{
    Q_OBJECT

public:
    explicit products(QWidget *parent = nullptr);
    ~products();


private:
    Ui::products *ui;
};

#endif // PRODUCTS_H
