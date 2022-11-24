#ifndef DATABASE_H
#define DATABASE_H

//头文件：
#include <QObject>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QDebug>
#include <QTime>

class database : public QObject
{
    Q_OBJECT
public:
    explicit database(QObject *parent = nullptr);
    ~database();
    bool createConnection(); //创建连接
    bool createTable(); //创建数据库表
    bool insertinfo(QString username,QString password,QString phone); //添加信息
    bool loginsearchinfo(QString username,QString password); //登录查询信息
    bool fqpwdsearchinfo(QString username,QString phone); //登录密码查询
    bool updatainfo(); //更新信息
    bool deleteinfo(); //删除信息
    QSqlDatabase db;

signals:

public slots:
};

#endif // DATABASE_H
