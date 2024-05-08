#ifndef EDITITEMS_H
#define EDITITEMS_H

#include <QDialog>

namespace Ui {
class edititems;
}

class edititems : public QDialog
{
    Q_OBJECT

public:
    explicit edititems(QWidget *parent = nullptr);
    ~edititems();

private:
    Ui::edititems *ui;
};

#endif // EDITITEMS_H
