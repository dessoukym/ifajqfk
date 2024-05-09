#include "shopping.h"
#include "ui_shopping.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "item.h"
#include "checkout.h"

QVector<item> it;
QFile f("/Users/ali/ifajqfk-main/itemsmenu");

QVector<item> cart;
QFile c("/Users/ali/ifajqfk-main/cartdata");



shopping::shopping(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::shopping)
{
    ui->setupUi(this);
    ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);



    if (f.open(QIODevice::ReadWrite)) {

        QTextStream x(&f);

        while (!x.atEnd()) {
            item o;
            QString str = x.readLine();
            QStringList p = str.split(";");

            if (p.size() == 5) {
                o.name = p[0];
                o.description = p[1];
                o.quantity = p[2].toInt();
                o.category = p[3];
                o.price = p[4].toInt();
                it.append(o);
            }
        }
        f.close();
    }

    ui->tableWidget->setRowCount(it.size());
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Description", "Quantity", "Category", "Price"});

    for (int i = 0; i < it.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it[i].description));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(it[i].quantity)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(it[i].category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(it[i].price)));
    }
}

shopping::~shopping()
{




    delete ui;
}

void shopping::on_pushButtonsearch_clicked()
{
    QString x = ui->lineEditsearch->text();
    QVector<item> match;
    ui->tableWidget->clear();

    for(int i = 0 ; i<it.size();i++){
        if(it[i].name.contains(x)||it[i].description.contains(x)){

            match.push_back(it[i]);
        }
    }

    ui->tableWidget->setRowCount(match.size());
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Description", "Quantity", "Category", "Price"});

    for (int i = 0; i < match.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(match[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(match[i].description));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(match[i].quantity)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(match[i].category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(match[i].price)));
    }

}


void shopping::on_pushButton_add_clicked()
{
    QString x = ui->lineEdit_name->text();
    QString q = ui->lineEdit_quant->text();
    int z = q.toInt();
    ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);


    for(int i = 0 ; i < it.size();i++){
        ui->label_3->setVisible(0);
        ui->label_4->setVisible(0);

        bool u = false;

        if(x == it[i].name){

            u = true;

        }else{
            ui->label_3->setVisible(1);
        }

        if(u && z<=it[i].quantity){

            ui->label_3->setVisible(0);
            ui->label_4->setVisible(0);
            int temp = it[i].quantity;
            it[i].quantity = z;
            cart.push_back(it[i]);
            it[i].quantity = temp - z;
        }else{
            ui->label_4->setVisible(1);
        }
    }



    ui->tableWidget_2->setRowCount(cart.size());
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels({"Name", "Quantity",  "Price"});
    for (int i = 0; i < cart.size(); ++i) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(cart[i].name));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(cart[i].quantity)));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::number(cart[i].price)));
    }
    for (int i = 0; i < it.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it[i].description));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(it[i].quantity)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(it[i].category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(it[i].price)));
    }






}


void shopping::on_pushButton_del_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString z = ui->lineEdit_quant->text();
    int x = z.toInt();
    int index = -1;

   ui->label_3->setVisible(0);
    ui->label_4->setVisible(0);

    for (int i = 0; i < cart.size(); ++i) {
        if (name == cart[i].name) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        if (x <= cart[index].quantity) {
            if (x == cart[index].quantity) {
                cart.removeAt(index);


                for(int i = 0; i<it.size();i++){
                    if(name==it[i].name){

                      it[i].quantity += x;
                    }
                }



            } else {
                cart[index].quantity -= x;
                for(int i = 0; i<it.size();i++){
                    if(name==it[i].name){

                        it[i].quantity += x;
                    }
                }
            }

            ui->label_3->setVisible(0);
            ui->label_4->setVisible(0);
        } else {
            ui->label_4->setVisible(1);
        }
    } else {
        ui->label_3->setVisible(1);
    }

    ui->tableWidget_2->setRowCount(cart.size());
    ui->tableWidget_2->setColumnCount(3);
    ui->tableWidget_2->setHorizontalHeaderLabels({"Name", "Quantity", "Price"});
    for (int i = 0; i < cart.size(); ++i) {
        ui->tableWidget_2->setItem(i, 0, new QTableWidgetItem(cart[i].name));
        ui->tableWidget_2->setItem(i, 1, new QTableWidgetItem(QString::number(cart[i].quantity)));
        ui->tableWidget_2->setItem(i, 2, new QTableWidgetItem(QString::number(cart[i].price)));
    }

    for (int i = 0; i < it.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(it[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(it[i].description));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(it[i].quantity)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(it[i].category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(it[i].price)));
    }
}

void shopping::on_pushButton_checkout_clicked()
{
    c.open(QIODevice::Append | QIODevice::Text);
    QTextStream co(&c);
    for(int i = 0 ; i<cart.size();i++){
        co<<cart[i].name<<" "<<cart[i].price<<" "<<cart[i].quantity<<Qt::endl;
    }

    c.close();

    hide();
    checkout* l = new checkout;
    l->show();
    delete this;
}


void shopping::on_pushButtonsearch_2_clicked()
{

    QVector<QString> s;
    if(ui->checkBoxfood->isChecked()){
        s.push_back(ui->checkBoxfood->text());
    }

    if(ui->checkBox_candy->isChecked()){
        s.push_back(ui->checkBox_candy->text());
    }

    if(ui->checkBox_drinks->isChecked()){
        s.push_back(ui->checkBox_drinks->text());
    }

    if(ui->checkBox_pets->isChecked()){
        s.push_back(ui->checkBox_pets->text());
    }

    if(ui->checkBox_ele->isChecked()){
        s.push_back(ui->checkBox_ele->text());
    }

    if(ui->checkBox_cle->isChecked()){
        s.push_back(ui->checkBox_cle->text());
    }
QVector<item> temp;

    for(int i = 0 ; i<it.size();i++){
        for(int j = 0 ; j<s.size();j++){
            if(it[i].category == s[j])
            temp.push_back(it[i]);
        }



    }

    ui->tableWidget->clear();

    for (int i = 0; i < temp.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(temp[i].name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(temp[i].description));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(temp[i].quantity)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(temp[i].category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(temp[i].price)));
    }


}

