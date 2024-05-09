#include "checkout.h"
#include "ui_checkout.h"
#include <QString>
#include <QFile>
#include <QMap>
#include "final.h"

struct check {
    QString name;
    int quantity;
    int price;
};

QMap<QString, check> chMap;
QFile j("/Users/ali/ifajqfk-main/cartdata");

checkout::checkout(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::checkout)
{
    ui->setupUi(this);
    int total = 0;
    ui->label_3->setVisible(0);

    if (j.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream zz(&j);

        while (!zz.atEnd()) {
            check p;
            QString line = zz.readLine();
            QStringList parts = line.split(" ");

            if (parts.size() == 3) {
                p.name = parts[0];
                p.quantity = parts[2].toInt();
                p.price = parts[1].toInt();
                chMap[p.name] = p;
            }
        }

        j.close();
    }

    if (j.open(QIODevice::WriteOnly | QIODevice::Text)) {
        j.close();
    }


    ui->tableWidget->setRowCount(chMap.size());
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Quantity", "Price"});

    int row = 0;
    for (auto it = chMap.constBegin(); it != chMap.constEnd(); ++it) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(it.value().name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(it.value().quantity)));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(it.value().price)));
        row++;
    }

    for (auto it = chMap.constBegin(); it != chMap.constEnd(); ++it) {
        total = total + ( it.value().price * it.value().quantity);
    }

    ui->label_price->setText(QString::number(total));
}

checkout::~checkout()
{
    delete ui;
}

void checkout::on_pushButton_clicked()
{
    if (j.open(QIODevice::WriteOnly | QIODevice::Text)) {
        j.close();
    }

    ui->label_3->setVisible(0);

    if (ui->lineEdit->text().isEmpty() || ui->lineEdit_3->text().isEmpty() || ui->lineEdit_2->text().isEmpty()) {
        ui->label_3->setVisible(1);
    } else {
        hide();
        final *f = new final;
        f->show();
    }


}
