#include "usermanagement.h"
#include "ui_usermanagement.h"
#include "login.h"
#include <QFile>
#include <QString>
#include <QVector>
#include <QRandomGenerator>
#include <QMessageBox>
QString usermanagement::encryptpass(QString text){
    QString returned=text;
    for (QChar& c:returned){
        c=static_cast<char>(c.unicode()+3);
    }
    return returned;
}


QString currentadmin;
struct account{
    QString username;
    QString password;
};
QVector <account> existed;
QVector <account> added;
QFile handled(":/adminuserhandling");
QFile old(":/userdata");
usermanagement::usermanagement(QWidget *parent)
    :QDialog(parent)
    , ui(new Ui::usermanagement)
{
    ui->setupUi(this);
    ui->checkBoxdeletion->setVisible(0);
    ui->labelnewuser->setVisible(1);
    ui->labeluseralrexits->setVisible(0);
    ui->labelemptyusername->setVisible(0);
    old.open(QIODevice::ReadWrite);
    QTextStream in(&old);
    while (!in.atEnd()){
        account a;
        QString string= in.readLine();
        QStringList parts=string.split(" ");
        a.username=parts[0];
        a.password=parts[1];
        existed.push_back(a);
    }
}
void usermanagement::setadmin(QString text){
    currentadmin=text;
}
usermanagement::~usermanagement()
{
    handled.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&handled);
    for (int i=0; i<added.size(); i++){
        out << added[i].username <<" " << added[i].password <<" added by " <<currentadmin<< Qt::endl;
    }
   handled.close();
   old.open(QIODevice::Append| QIODevice::Text);
   QTextStream outlol(&old);
   for (int i=0;i<added.size(); i++ ){
       outlol <<added[i].username<< " " <<added[i].password << Qt::endl;
   }
   old.close();
    delete ui;
}

void usermanagement::on_pushButton_clicked()
{
    ui->checkBoxdeletion->setVisible(0);
    ui->labeluseralrexits->setVisible(0);
    ui->labelemptyusername->setVisible(0);
    ui->labelnewuser->setVisible(1);

    QString username= ui->lineEditusername->text();
    if (username==""){
        ui->labelemptyusername->setVisible(1);
    }
    else {
    for (int i=0; i<existed.size(); i++){
            if (username==existed[i].username){
            ui->labeluseralrexits->setVisible(1);
             break;
         }
          else {
            if (i==existed.size()-1){
             int x= QRandomGenerator::global()->bounded(10000000, 1000000000);
             QString password=QString::number(x);
             ui-> lineEdit_password->setText(password);
             account m;
             m.password=encryptpass(password);
             m.username=username;
             added.push_back(m);
             QMessageBox::information(this, "New User Created","New username: "+m.username+ " Password: "+ password);
             login* l= new login;
             l->show();
              delete this;
         }
         }
    }
    }
}




