#include "clw.h"
#include "ui_clw.h"

clw::clw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clw)
{
    ui->setupUi(this);
    mdatabase = new database();

    ui->label_4->setScaledContents(true);
    ui->label_6->setScaledContents(true);
    ui->label_7->setScaledContents(true);
    ui->label_9->setScaledContents(true);
    ui->label_10->setScaledContents(true);
    ui->label_5->setScaledContents(true);
    ui->label_11->setScaledContents(true);
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    ui->lineEdit_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid;border-left:0px solid;border-right:0px solid;");
    this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    mymain = new jm();
    mreg = new mregister();
    connect(mreg,&mregister::comfirmposition_closed,this,[=](){this->show();});



}

clw::~clw()
{
    delete ui;
}

void clw::on_pushButton_clicked()//登录函数
{
    mdatabase = new database();
    QString str_pw;
    str_pw = ui->lineEdit_2->text();//输入密码框
    QString str_un;
    str_un = ui->comboBox->currentText();//输入账号框

    if(mdatabase->loginsearchinfo(str_un,str_pw))//是否存在账号
    {
        this->close();
        mymain->show();
        qDebug() << "login is successful";//登录成功
    }else{
        qDebug() << "login is failed!";//登录失败
    }
}

void clw::on_pushButton_4_clicked()
{
    this->close();
    mreg->show();
}
