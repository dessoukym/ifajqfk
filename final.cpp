#include "final.h"
#include "ui_final.h"
#include <QFile>

final::final(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::final)
{
    ui->setupUi(this);
}

final::~final()
{
    delete ui;

    QFile j("/Users/ali/ifajqfk-main/cartdata");
    if (j.open(QIODevice::WriteOnly | QIODevice::Text)) {
        j.close();
    }
}
