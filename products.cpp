#include "products.h"
#include "ui_products.h"
#include <QFile>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QIODevice>
#include <QTextStream>
#include <QCoreApplication>



products::products(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::products)
{
    ui->setupUi(this);
}

products::~products()
{
    delete ui;
}

