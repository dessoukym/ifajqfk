#include "newuserlogin.h"
#include "QString"
#include "ui_newuserlogin.h"
#include "login.h"
#include "admin.cpp"
#include <QFile>
#include <QVector>

QVector <user> users;
QVector <user> newusers;
QFile userdata("C:\\Users\\Malak\\Documents\\labproj\\userdata");
QString newuserlogin::encryptpass(QString text){
    QString returned=text;
    for (QChar& c:returned){
        c=static_cast<char>(c.unicode()+3);
    }
    return returned;
}

newuserlogin::newuserlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newuserlogin)
{
    ui->setupUi(this);
    ui->label_noname->setVisible(0);
    ui->label_nopass->setVisible(0);
    ui->label_norepass->setVisible(0);
    ui->label_error->setVisible(0);
    ui->label_alrexits->setVisible(0);
    ui->label_shortpass->setVisible(0);
    userdata.open(QIODevice::ReadWrite);
    QTextStream in(&userdata);
    while (!in.atEnd()){
        user a;
        QString string= in.readLine();
        QStringList parts=string.split(" ");
        a.username=parts[0];
        a.password=parts[1];
       users.push_back(a);
    }
}

newuserlogin::~newuserlogin()
{
    QTextStream out(&userdata);
    for (int i=0; i<newusers.size(); i++){
        out << newusers[i].username << " " << newusers[i].password << Qt::endl;
    }
    userdata.close();
    delete ui;
}

void newuserlogin::on_pushButton_clicked()
{
    ui->label_noname->setVisible(0);
    ui->label_nopass->setVisible(0);
    ui->label_norepass->setVisible(0);
    ui->label_error->setVisible(0);
    ui->label_alrexits->setVisible(0);
    ui->label_shortpass->setVisible(0);


    QString usernameentered=ui->lineEditusername->text();
    QString passentered= ui->lineEdit_pass->text();
    QString repass= ui->lineEdit_repass->text();
    if (usernameentered==""){
        ui->label_noname->setVisible(1);
    }
    if(passentered==""){
        ui->label_nopass->setVisible(1);
    }
    if (repass==""){
        ui->label_norepass->setVisible(1);
    }
    if (passentered!=repass){
        ui->label_error->setVisible(1);
    }
    if (passentered.length()<9){
        ui->label_shortpass->setVisible(1);
    }
    for (int i=0; i<users.size(); i++){
        if (usernameentered==users[i].username){
            ui->label_alrexits->setVisible(1);
        }
    }
    if (ui->label_nopass->isVisible()==0 && ui->label_alrexits->isVisible()==0 &&  ui->label_error->isVisible()==0 && ui->label_norepass->isVisible()==0 && ui->label_noname->isVisible()==0 && ui->label_shortpass->isVisible()==0){
        user u;
        u.username=usernameentered;
        u.password= encryptpass(passentered);
        newusers.push_back(u);
        login* l= new login;
        l->show();
        delete this;
    }

}

