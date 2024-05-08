#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H
#include <QDialog>
#include <QString>
#include "newuserlogin.h"

namespace Ui {
class usermanagement;
}

class usermanagement : public QDialog
{
    Q_OBJECT

public:
    explicit usermanagement(QWidget *parent = nullptr);
    ~usermanagement();
    void setadmin(QString);
    QString encryptpass(QString);

private slots:
    void on_pushButton_clicked();



private:
    Ui::usermanagement *ui;
};

#endif // USERMANAGEMENT_H
