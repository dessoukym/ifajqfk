#ifndef NEWUSERLOGIN_H
#define NEWUSERLOGIN_H
#include <QString>

#include <QDialog>

namespace Ui {
class newuserlogin;
}

class newuserlogin : public QDialog
{
    Q_OBJECT

public:
    explicit newuserlogin(QWidget *parent = nullptr);
    QString encryptpass(QString);
    ~newuserlogin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newuserlogin *ui;
};

#endif // NEWUSERLOGIN_H
