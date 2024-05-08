#include "productmanagement.h"
#include "ui_productmanagement.h"
#include "additem.h"

productmanagement::productmanagement(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::productmanagement)
{
    ui->setupUi(this);
}

productmanagement::~productmanagement()
{
    delete ui;
}

void productmanagement::on_pushButtonadd_clicked()
{
    hide();
    addItem* a= new addItem;
    a->show();

}


void productmanagement::on_pushButton_edit_clicked()
{
    hide();
    addItem* a= new addItem;
    a->changebutton("Edit");
    a->show();

}


void productmanagement::on_pushButton_delete_clicked()
{
    hide ();
    addItem* m= new addItem;
    m->changebutton("Delete");
    m->show();
}

