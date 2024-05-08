#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include "newuserlogin.h"
#include <QPixmap>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap pix ("C:\\Users\\Malak\\OneDrive\\R.jpeg");
    int w= ui->label4pic->width();
    int h= ui->label4pic->height();
    ui->label4pic->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));
}

login::~login()
{

    delete ui;
}

void login::on_pushButtonAdmin_clicked()
{
    hide();
    admin* adminWindow= new admin(this);
    adminWindow->show();

}


void login::on_pushButtonUser_clicked()
{
    hide();
    admin* uslog= new admin;
    uslog->show();
}


void login::on_pushButtonNewUser_clicked()
{
    hide();
    newuserlogin* newuslog=new newuserlogin;
    newuslog->show();
}

