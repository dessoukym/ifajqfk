#ifndef ADDITEM_H
#define ADDITEM_H
#include <QString>
#include <QDialog>

namespace Ui {
class addItem;
}

class addItem : public QDialog
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = nullptr);
    void changebutton(QString);
    ~addItem();

private slots:
    void on_pushButtonAdd_clicked();

private:
    Ui::addItem *ui;
};

#endif // ADDITEM_H
