#ifndef WEATHER_H
#define WEATHER_H

#include <QWidget>
#include <QMouseEvent>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonValue>
#include <QLabel>
#include <QFile>

namespace Ui {
class weather;
}

class weather : public QWidget
{
    Q_OBJECT

public:
    explicit weather(QWidget *parent = 0);
    ~weather();
    void api_ret(int api, int i);
        void typepng_ret(QString type, int i);
        void mouseReleaseEvent(QMouseEvent* event);
        void mousePressEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);
private slots:
    void on_pushButton_2_clicked();
    void read_data();

    void on_pushButton_clicked();

signals:
    void ComfirmPosition_closed();



private:
    Ui::weather *ui;
    bool m_bPressed = true;
       QPoint m_point;
       QNetworkAccessManager* manager;
       QNetworkReply* reply;
       QLabel *weeklb[5];
       QLabel *typepnglb[5];
       QLabel *wendulb[5];
       QLabel *typelb[5];
       QLabel *fenglb[5];
       QLabel *noticelb[5];
       QLabel *datelb[5];
       QLabel *apilb[5];

};

#endif // WEATHER_H
