#ifndef ADMINFUNCTIONS_H
#define ADMINFUNCTIONS_H

#include <QDialog>

namespace Ui {
class adminfunctions;
}

class adminfunctions : public QDialog
{
    Q_OBJECT

public:
    explicit adminfunctions(QWidget *parent = nullptr);
    void setValues(QString);
    ~adminfunctions();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::adminfunctions *ui;
};

#endif // ADMINFUNCTIONS_H
