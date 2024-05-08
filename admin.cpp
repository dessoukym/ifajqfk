#include "admin.h"
#include "ui_admin.h"
#include "adminfunctions.h"
#include "userfunctions.h"
#include "usermanagement.h"
#include <QString>
#include <QVector>
struct user{
    QString username;
    QString password;
};
QVector <user> admins;
QVector <user> useraccounts;
admin::admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::admin)
{
    ui->setupUi(this);
    ui->label_nousername->setVisible(0);
    ui->label_nopass->setVisible(0);
    ui->label_error->setVisible(0);
    QFile admindata(":/admindatalol");
    admindata.open(QIODevice::ReadOnly);
    QTextStream in(&admindata);
    while (!in.atEnd()){
        user a;
        QString string= in.readLine();
        QStringList parts=string.split(" ");
        a.username=parts[0];
        a.password=parts[1];
        admins.push_back(a);
    }
    QFile userdata(":/userdata");
    userdata.open(QIODevice::ReadOnly);
    QTextStream i(&userdata);
    while (!i.atEnd()){
        user a;
        QString s=i.readLine();
        QStringList parts=s.split(" ");
        a.username=parts[0];
        a.password=parts[1];
        useraccounts.push_back(a);
    }
    admindata.close();
    userdata.close();
}

admin::~admin()
{
    delete ui;
}
QString admin::decryptpass(QString text){
    QString returned=text;
    for (QChar& c: returned){
        c=static_cast<char>(c.unicode()-3);
    }
    return returned;
}
void admin::on_pushButtonlogin_clicked(){
    ui->label_nousername->setVisible(0);
    ui->label_nopass->setVisible(0);
    ui->label_error->setVisible(0);
    QString usernameentered=ui->lineEditUsername->text();
    QString passwordentered= ui->lineEditpassword->text();
    if (usernameentered==""){
        ui->label_nousername->setVisible(1);
    }
    if(passwordentered==""){
        ui->label_nopass->setVisible(1);
    }
    else{
    user b;
    b.username=usernameentered;
    b.password=passwordentered;
    for (int i=0; i<admins.size(); i++){
        if (b.username==admins[i].username && b.password==admins[i].password){
            usermanagement* u= new usermanagement;
            u->setadmin(usernameentered);
            hide();
            adminfunctions* a= new adminfunctions(this);
            a->setValues(usernameentered);
            a->show();
        }
    }
    for (int i=0; i<useraccounts.size(); i++){
        if (b.username==useraccounts[i].username && b.password==decryptpass(useraccounts[i].password)){
            hide();
            userfunctions* f= new userfunctions;
            f->setValues(usernameentered);
            f->show();

        }
        if (i==useraccounts.size()-1){
            ui->label_error->setVisible(1);
        }
    }
}
}

