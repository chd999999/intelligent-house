#include "jm.h"
#include "ui_jm.h"

jm::jm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::jm)
{
    ui->setupUi(this);

    ser = new mvserial();
    ui->comboBox->addItems(ser->serialportname());
    connect(ser->mserial,SIGNAL(readyRead()),this,SLOT(showtemhumi()));
    ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/images/灯(1).png);border:none;color:rgb(255,255,255);}");
    ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(:/images/灯(1).png);border:none;color:rgb(255,255,255);}");
    ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/images/家电_蜂鸣器.png);border:none;color:rgb(255,255,255);}");
    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/images/温度.png);border:none;color:rgb(255,255,255);}");
    ui->pushButton_7->setStyleSheet("QPushButton{border-image: url(:/images/风扇.png);border:none;color:rgb(255,255,255);}");
    ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(:/images/湿度.png);border:none;color:rgb(255,255,255);}");



}

jm::~jm()
{
    delete ui;
}

void jm::on_pushButton_10_clicked()
{
    QString PortName;
    PortName = ui->comboBox->currentText();
    ser->configserialport(PortName);
    if(ser->openserialport())
    {
        qDebug() << "open serialport is successful";
      }
                    else
    {
         qDebug() << "open serialport is failed";
      }
}

void jm::on_pushButton_4_clicked()
{
   mymaintwo = new weather;
   this->close();
   mymaintwo->show();
}

void jm::on_pushButton_clicked()//LED1控制函数
{
    ba.resize(1);
    static int i = 0;
     if(i==0)//LED灭
    {
         ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/images/灯.png);border:none;color:rgb(255,255,255);}");
         i = 1;
         ba[0]='1';
         ser->mserial->write(ba);
     }
     else if(i==1){//LED亮
         ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/images/灯(1).png);border:none;color:rgb(255,255,255);}");
         i = 0;
         ba[0] = '2';
         ser->mserial->write(ba);

     }

}

void jm::on_pushButton_2_clicked()
{
    ba.resize(1);
    static int i = 0;
     if(i==0)
    {
         ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/images/蜂鸣器.png);border:none;color:rgb(255,255,255);}");
         i = 1;
         ba[1] = '7';
         ser->mserial->write(ba);

     }
     else if(i==1){
         ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/images/家电_蜂鸣器.png);border:none;color:rgb(255,255,255);}");
         i = 0;
         ba[0] = '8';
         ser->mserial->write(ba);

     }

}



void jm::on_pushButton_3_clicked()
{
    ba.resize(1);
    static int i = 0;
     if(i==0)
    {
         ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(:/images/灯.png);border:none;color:rgb(255,255,255);}");
         i = 1;
          ba[0] = '3';
         ser->mserial->write(ba);


     }
     else if(i==1){
         ui->pushButton_3->setStyleSheet("QPushButton{border-image: url(:/images/灯(1).png);border:none;color:rgb(255,255,255);}");
         i = 0;
         ba[0] = '4';
         ser->mserial->write(ba);


     }

}



void jm::on_pushButton_7_clicked()
{
    ba.resize(1);

        static int i = 0;
         if(i==0)
        {
             ui->pushButton_7->setStyleSheet("QPushButton{border-image: url(:/images/风扇(2).png);border:none;color:rgb(255,255,255);}");
             i = 1;
             ba[0] = '5';
             ser->mserial->write(ba);

         }
         else if(i==1){
             ui->pushButton_7->setStyleSheet("QPushButton{border-image: url(:/images/风扇.png);border:none;color:rgb(255,255,255);}");
             i = 0;
             ba[0] = '6';
             ser->mserial->write(ba);



         }


}

void jm::on_pushButton_5_clicked()
{
    ba.resize(1);

    ui->pushButton_5->setStyleSheet("QPushButton{border-image: url(:/images/温度.png);border:none;color:rgb(255,255,255);}");
    ba[0] = '9';
    ser->mserial->write(ba);


}

void jm::on_pushButton_6_clicked()
{
    ba.resize(1);

    ui->pushButton_6->setStyleSheet("QPushButton{border-image: url(:/images/湿度.png);border:none;color:rgb(255,255,255);}");
    ba[0] = 'a';
    ser->mserial->write(ba);


}
void jm::showtemhumi()//温湿度显示框
{
    QString str;
    ba += ser->mserial->readAll();
    str = QString(ba);
    if(str.contains("\r\n",Qt::CaseSensitive))
    {
        str.remove(0,1);
        ui->listWidget->addItem(str);
    }
}



