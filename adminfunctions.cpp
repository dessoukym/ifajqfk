#include "adminfunctions.h"
#include "ui_adminfunctions.h"
#include "usermanagement.h"
#include "productmanagement.h"
#include <QString>

adminfunctions::adminfunctions(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminfunctions)
{
    ui->setupUi(this);
}
void adminfunctions::setValues(QString text){
    ui->label_hello->setText("Hello "+text);
}

adminfunctions::~adminfunctions()
{
    delete ui;
}

void adminfunctions::on_pushButton_clicked()
{
    hide();
    usermanagement* u= new usermanagement(this);
    u->show();
}
void adminfunctions::on_pushButton_2_clicked()
{
    hide();
    productmanagement* p= new productmanagement(this);
    p->show();
}

