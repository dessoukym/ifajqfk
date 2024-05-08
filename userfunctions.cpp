#include "userfunctions.h"
#include "ui_userfunctions.h"
#include "products.h"

userfunctions::userfunctions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userfunctions)
{
    ui->setupUi(this);
}

userfunctions::~userfunctions()
{
    delete ui;
}
void userfunctions:: setValues(QString text){
    ui->label->setText("Hello " + text);
}


