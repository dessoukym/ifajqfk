#include "edititems.h"
#include "ui_edititems.h"

edititems::edititems(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::edititems)
{
    ui->setupUi(this);
}

edititems::~edititems()
{
    delete ui;
}
