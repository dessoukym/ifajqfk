#ifndef PRODUCTMANAGEMENT_H
#define PRODUCTMANAGEMENT_H

#include <QDialog>

namespace Ui {
class productmanagement;
}

class productmanagement : public QDialog
{
    Q_OBJECT

public:
    explicit productmanagement(QWidget *parent = nullptr);
    ~productmanagement();

private slots:
    void on_pushButtonadd_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_delete_clicked();

private:
    Ui::productmanagement *ui;
};

#endif // PRODUCTMANAGEMENT_H
