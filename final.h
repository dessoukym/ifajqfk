#ifndef FINAL_H
#define FINAL_H

#include <QDialog>

namespace Ui {
class final;
}

class final : public QDialog
{
    Q_OBJECT

public:
    explicit final(QWidget *parent = nullptr);
    ~final();

private:
    Ui::final *ui;
};

#endif // FINAL_H
