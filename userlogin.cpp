#include "userlogin.h"
#include "ui_userlogin.h"

userlogin::userlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userlogin)
{
    ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}
