#ifndef JM_H
#define JM_H

#include <QWidget>
#include "mvserial.h"
#include "weather.h"

namespace Ui {
class jm;
}

class jm : public QWidget
{
    Q_OBJECT

public:
    explicit jm(QWidget *parent = 0);
    ~jm();

private slots:
    void on_pushButton_10_clicked();//连接串口

    void on_pushButton_4_clicked();//天气预报

    void on_pushButton_5_clicked();//显示温度

    void on_pushButton_clicked();//LED1

    void on_pushButton_2_clicked();//蜂鸣器

    void on_pushButton_3_clicked();//LED2

    void on_pushButton_7_clicked();//电风扇

    void on_pushButton_6_clicked();//显示温度
    void showtemhumi();//温湿度显示框




private:
    Ui::jm *ui;
    mvserial *ser;
    QByteArray ba;
    weather *mymaintwo;
};

#endif // JM_H
