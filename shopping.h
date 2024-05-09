#ifndef SHOPPING_H
#define SHOPPING_H

#include <QDialog>

namespace Ui {
class shopping;
}

class shopping : public QDialog
{
    Q_OBJECT

public:
    explicit shopping(QWidget *parent = nullptr);
    ~shopping();

private slots:
    void on_pushButtonsearch_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_checkout_clicked();

    void on_pushButtonsearch_2_clicked();

private:
    Ui::shopping *ui;
};

#endif // SHOPPING_H
