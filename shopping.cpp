#include "shopping.h"
#include "ui_shopping.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include "item.h"


QVector<item> it;
QFile f(":/itemsmenu");

shopping::shopping(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::shopping)
{
    ui->setupUi(this);


    if (f.open(QIODevice::ReadOnly)) {
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

