#ifndef USERFUNCTIONS_H
#define USERFUNCTIONS_H

#include <QDialog>

namespace Ui {
class userfunctions;
}

class userfunctions : public QDialog
{
    Q_OBJECT

public:
    explicit userfunctions(QWidget *parent = nullptr);
    ~userfunctions();
    void setValues (QString);

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::userfunctions *ui;
};

#endif // USERFUNCTIONS_H
