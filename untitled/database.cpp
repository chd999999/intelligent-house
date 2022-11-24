#include "database.h"

database::database(QObject *parent) : QObject(parent)
{
    createConnection();
    //createTable();
}

database::~database()
{
    db.close();
}

bool database::createConnection()//创建连接
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("users.db");
    if(!db.open())
    {
        qDebug() << "无法建立数据库连接";
        return false;
    }else
    {
        qDebug() << "连接成功";
    }
                    return true;
    }

    bool database::createTable()//创建数据库表
    {
        db = QSqlDatabase::database();
        QSqlQuery query(db);
        bool success = query.exec("create table users(username text primary key,password text,phone text)");
        if(success)
        {
            qDebug() << "数据库表创建成功";
        }else
        {
            qDebug() << "数据库表创建失败";
        }
            return false;
      }

    bool database::insertinfo(QString username, QString password, QString phone)//注册用户信息
    {
         QSqlQuery query(db);
         query.prepare("insert into users values(?,?,?)");
         query.addBindValue(username);
         query.addBindValue(password);
         query.addBindValue(phone);
         if(!query.exec())
         {
               qDebug() << "error:insert fail" << query.lastError();
               return false;
         }
          return true;

        }

     bool database::loginsearchinfo(QString username, QString password)//实现登录
     {
          QSqlQuery query(db);
          if(!query.exec("select * from users"))
          {
               qDebug() << "error: select fail" << query.lastError();
        }else{
              while(query.next())
             {
                  if(username == query.value(0).toString() && password == query.value(1).toString())
                   {
                        return true;
                   }
             }
     }
       return false;
    }

