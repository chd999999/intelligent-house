#ifndef CLW_H
#define CLW_H

#include <QDialog>
#include "jm.h"
#include "database.h"
#include "mregister.h"

namespace Ui {
class clw;
}

class clw : public QDialog
{
    Q_OBJECT

public:
    explicit clw(QWidget *parent = 0);
    ~clw();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::clw *ui;
    jm *mymain;
    database *mdatabase;
    mregister *mreg;
};

#endif // CLW_H
