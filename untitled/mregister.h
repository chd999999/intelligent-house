#ifndef MREGISTER_H
#define MREGISTER_H

#include <QWidget>
#include "database.h"

namespace Ui {
class mregister;
}

class mregister : public QWidget
{
    Q_OBJECT

public:
    explicit mregister(QWidget *parent = 0);
    ~mregister();
signals:
    void comfirmposition_closed();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::mregister *ui;
    database *regdb;
};

#endif // MREGISTER_H
