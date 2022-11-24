#include "mregister.h"
#include "ui_mregister.h"

mregister::mregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mregister)
{
    ui->setupUi(this);
}

mregister::~mregister()
{
    delete ui;
}


void mregister::on_pushButton_clicked()//注册信息
{
    regdb = new database;
    QString username,password,phone;
    username = ui->lineEdit->text();//注册新账号
    password = ui->lineEdit_2->text();//注册新密码
    phone = ui->lineEdit_3->text();//注册电话

    regdb->insertinfo(username,password,phone);
    regdb->db.close();
}

void mregister::on_pushButton_2_clicked()
{
    this->close();
    emit this->comfirmposition_closed();
}
