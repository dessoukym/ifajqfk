#ifndef ADMIN_H
#define ADMIN_H
#include <QDialog>
#include <QFile>
#include <QString>
namespace Ui {
class admin;
}

class admin : public QDialog
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = nullptr);
    QString decryptpass(QString);
    ~admin();

private slots:
    void on_pushButtonlogin_clicked();

private:
    Ui::admin *ui;
};

#endif // ADMIN_H
