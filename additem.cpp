#include "additem.h"
#include "ui_additem.h"
#include "adminfunctions.h"
#include <QFile>
#include <QString>
#include <QVector>
#include <QMessageBox>
#include <QIODevice>
#include <QTextStream>
#include <QCoreApplication>
#include <item.h>

QFile menu(":/itemsmenu");
QVector <item> items;
QVector <item> newitems;
QVector <item> edited;
QVector<QString> deleted;
QTextStream in(&menu);
addItem::addItem(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addItem)
{
    ui->setupUi(this);
    ui->label_nodes->setVisible(0);
    ui->label_noname->setVisible(0);
    ui->label_alrexists->setVisible(0);
    ui->label_doesnotexist->setVisible(0);
    ui->label_nocat->setVisible(0);
    menu.open(QIODevice::ReadWrite);
    while (!in.atEnd()){
        item a;
        QString string= in.readLine();
        QStringList parts=string.split(";");
        a.name=parts[0];
        a.description=parts[1];
        a.quantity=parts[2].toInt();
        a.category=parts[3];
        a.price=parts[4].toInt();
        items.push_back(a);
    }
}


addItem::~addItem()
{
    menu.open(QIODevice::Append | QIODevice::Text);
    QTextStream out(&menu);
    if(ui->pushButtonAdd->text()=="Add"){
    for (int i=0; i<newitems.size(); i++){
            out << newitems[i].name <<";" << newitems[i].description << ";" <<newitems[i].quantity <<";" <<newitems[i].category<<";" <<newitems[i].price<<Qt::endl;
    }
    }
    else if (ui->pushButtonAdd->text()=="Edit") {
        QStringList lines;
        QString line;
        QTextStream in2(&menu);
        for (int i=0; i<edited.size(); i++){
            in2.seek(0);
            lines.clear();
        while (!in2.atEnd()) {
             line = in2.readLine();
            if (line.contains(edited[i].name)) {
                continue;
            }
            lines.append(line);
        }
        }
        menu.resize(0);
        for (const QString& line : lines) {
            out << line << "\n";
        }
        for (int i=0; i<edited.size(); i++){
            out << edited[i].name << ";" << edited[i].description << ";" << edited[i].quantity<<";" << edited[i].category<< ";"<<edited[i].price <<Qt::endl;
        }
    }
    else{
        QStringList lines;
        QString line;
        QTextStream in3(&menu);
        for (int i=0; i<deleted.size(); i++){
            in3.seek(0);
            lines.clear();
            while (!in3.atEnd()){
                line=in3.readLine();
                if (line.contains(deleted[i])){
                    continue;
                }
             lines.append(line);
            }
        }
        QTextStream out(&menu);
        menu.resize(0);
        for (const QString& line : lines) {
            out << line << "\n";
        }
    }
    menu.close();
    delete ui;

 }
void addItem::changebutton(QString text){
    ui->pushButtonAdd->setText(text);
}
void addItem::on_pushButtonAdd_clicked()
{
    ui->label_nodes->setVisible(0);
    ui->label_noname->setVisible(0);
    ui->label_alrexists->setVisible(0);
    ui->label_doesnotexist->setVisible(0);
    ui->label_nocat->setVisible(0);
    QString nameentered=ui->lineditName->text();
    QString desentered=ui->lineEditDescribtion->text();
    QString cat= ui->comboBox->currentText();
    int quant=ui->spinBox->value();
    int price1=ui->spinBox_price->value();
    if (nameentered=="")
        ui->label_noname->setVisible(1);
    if (desentered=="")
        ui->label_nodes->setVisible(1);
    if (cat=="")
        ui->label_nocat->setVisible(1);
    else if (ui->pushButtonAdd->text()=="Add"){
        for (int i=0; i<items.size(); i++){
            if (nameentered==items[i].name){
                ui->label_alrexists->setVisible(1);
                break;
            }
            if (i==items.size()-1){
                item u;
                u.name=nameentered;
                u.description=desentered;
                u.quantity=quant;
                u.category=cat;
                u.price=price1;
                newitems.push_back(u);
                QMessageBox::information(this, "New item added", nameentered+" " +desentered+" quantity: " + QString::number(quant)+ "Price: " + QString::number(price1));
                adminfunctions* l= new adminfunctions;
                l->show();
                delete this;
            }
        }
    }
    else if (ui->pushButtonAdd->text()=="Edit") {
        int x=-1;
        for (int i=0; i<items.size(); i++){
            if (nameentered==items[i].name){
                x=i;
                break;
            }
            if (i==items.size()-1)
                ui->label_doesnotexist->setVisible(1);
        }
        if (x!=-1){
            item u;
            u.name=nameentered;
            u.description=desentered;
            u.quantity=quant;
            u.price=price1;
            u.category=cat;
            edited.push_back(u);
            QMessageBox::information(this, "Item edited", nameentered+" " +desentered+" quantity: " + QString::number(quant));
            adminfunctions* l= new adminfunctions;
            l->show();
            delete this;
        }
    }
    else {
        int y=-1;
        for (int i=0; i<items.size(); i++){
            if (nameentered==items[i].name){
                y=i;
                break;
            }
            if (i==items.size()-1){
                ui->label_doesnotexist->setVisible(1);
            }
        }
        if (y!=-1){
            deleted.push_back(nameentered);
            QMessageBox::information(this, "Item deleted: ", nameentered);
            adminfunctions* l= new adminfunctions;
            l->show();
            delete this;
        }
    }
 }

