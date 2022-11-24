#include "weather.h"
#include "ui_weather.h"

weather::weather(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::weather)
{
    ui->setupUi(this);
    this->setStyleSheet("QWidget#weatherwidget{border-image:url(:/images/background2.png)}");

        //按钮无边框
        ui->pushButton_2->setFlat(true);
        ui->pushButton->setFlat(true);

        //界面无边框
        this->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
        //label图片自适应大小
        ui->label_typepng->setScaledContents(true);
        ui->label_typepng1->setScaledContents(true);
        ui->label_typepng1_2->setScaledContents(true);
        ui->label_typepng1_3->setScaledContents(true);
        ui->label_typepng1_4->setScaledContents(true);


        this->datelb[0] = ui->label_date;
        this->datelb[1] = ui->label_date1;
        this->datelb[2] = ui->label_date1_2;
        this->datelb[3] = ui->label_date1_3;
        this->datelb[4] = ui->label_date1_4;

        weeklb[0] = ui->label_week;
        weeklb[1] = ui->label_week1;
        weeklb[2] = ui->label_week1_2;
        weeklb[3] = ui->label_week1_3;
        weeklb[4] = ui->label_week1_4;

        typepnglb[0] = ui->label_typepng;
        typepnglb[1] = ui->label_typepng1;
        typepnglb[2] = ui->label_typepng1_2;
        typepnglb[3] = ui->label_typepng1_3;
        typepnglb[4] = ui->label_typepng1_4;

        typelb[0] = ui->label_type;
        typelb[1] = ui->label_type1;
        typelb[2] = ui->label_type1_2;
        typelb[3] = ui->label_type1_3;
        typelb[4] = ui->label_type1_4;

        wendulb[0] = ui->label_wendu;
        wendulb[1] = ui->label_wendu1;
        wendulb[2] = ui->label_wendu1_2;
        wendulb[3] = ui->label_wendu1_3;
        wendulb[4] = ui->label_wendu1_4;

        fenglb[0] = ui->label_feng;
        fenglb[1] = ui->label_feng1;
        fenglb[2] = ui->label_feng1_2;
        fenglb[3] = ui->label_feng1_3;
        fenglb[4] = ui->label_feng1_4;

        apilb[0] = ui->label_api;
        apilb[1] = ui->label_api1;
        apilb[2] = ui->label_api1_2;
        apilb[3] = ui->label_api1_3;
        apilb[4] = ui->label_api1_4;

        noticelb[0] = ui->label_notice;
        noticelb[1] = ui->label_notice1;
        noticelb[2] = ui->label_notice1_2;
        noticelb[3] = ui->label_notice1_3;
        noticelb[4] = ui->label_notice1_4;


        //武汉101200101
        manager = new QNetworkAccessManager;
        QUrl url("http://t.weather.itboy.net/api/weather/city/101200101");
        QNetworkRequest request(url);
        reply = manager->get(request);
        connect(reply, SIGNAL(finished()), this, SLOT(read_data()));
}

weather::~weather()
{

    delete ui;
}

void weather::api_ret(int api, int i)
{
    if(api<=50){apilb[i]->setText("优");}
    else if(api<=100){apilb[i]->setText("良");}
    else if(api<=150){apilb[i]->setText("轻度污染");}
    else if(api<=200){apilb[i]->setText("中度污染");}
    else if(api<=300){apilb[i]->setText("重度污染");}
    else{apilb[i]->setText("严重污染");}

}

void weather::typepng_ret(QString type, int i)
{
    QString path;
    if(type=="晴"){path = ":/images/晴天.png";}
    else if(type=="阴"){path = ":/images/阴.png";}
    else if(type=="多云"){path = ":/images/多云.png";}
    else if(type=="小雨"){path = ":/images/小雨.png";}
    else if(type=="中雨"){path = ":/images/中雨.png";}
    else if(type=="大雨"){path = ":/images/大雨.png";}
    typepnglb[i]->setPixmap(QPixmap(path));
}

void weather::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}

void weather::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_bPressed = true;
        m_point = event->pos();
    }
}

void weather::mouseMoveEvent(QMouseEvent *event)
{
    if(m_bPressed)
        move(event->pos() - m_point + pos());
}

void weather::on_pushButton_2_clicked()
{
    this->close();
    emit this->ComfirmPosition_closed();
}

void weather::read_data()//读取数据
{
    QByteArray buffer = reply->readAll();

    qDebug() << "接受的数据：" << buffer;

    QJsonParseError e;
    QJsonDocument jsondoc = QJsonDocument::fromJson(buffer, &e);
    if(e.error == QJsonParseError::NoError)
    {
        qDebug() << tr("解析json成功");
    }else{
        qDebug() << tr("解析json错误");
    }
    QJsonObject weatherobj = jsondoc.object();

    QJsonObject cityobj = weatherobj.value("cityInfo").toObject();
    QString city = cityobj.value("city").toString();
    ui->label->setText(city);

    QJsonObject dataobj = weatherobj.value("data").toObject();
    QString nowwendu = dataobj.value("wendu").toString() + "℃";
    ui->label_5->setText(nowwendu);

    QJsonArray forecastarray = dataobj.value("forecast").toArray();
    for(int i =0; i < 5; i++)
    {
        QJsonObject obj = forecastarray.at(i).toObject();
        QString high = obj.value("high").toString();
        high = high.mid(3);
        QString low = obj.value("low").toString();
        low = low.mid(3,1);
        QString wendu = low + "~" + high;
        QString date = obj.value("ymd").toString();
        QString week = obj.value("week").toString();
        QString type = obj.value("type").toString();
        QString fx = obj.value("fx").toString();
        QString fl = obj.value("fl").toString();
        QString feng = fx + " " + fl;
        int api = obj.value("api").toInt();
        QString notice = obj.value("notice").toString();

        weeklb[i]->setText(week);
        datelb[i]->setText(date);
        wendulb[i]->setText(wendu);
        typelb[i]->setText(type);
        fenglb[i]->setText(feng);
        noticelb[i]->setText(notice);
        api_ret(api,i);
        typepng_ret(type,i);


    }
}

void weather::on_pushButton_clicked()//天气查询
{
    QString ip;
    QString city = ui->comboBox->currentText();

    QFile file("G:/QT/untitled/city.json");//读取json文件
    if(!file.open(QIODevice::ReadOnly))
    {
        qDebug() << file.errorString();
    }
    QByteArray buffer = file.readAll();
    QJsonParseError e;
    QJsonDocument jsondoc = QJsonDocument::fromJson(buffer, &e);
    if(e.error == QJsonParseError::NoError)
    {
        qDebug() << tr("解析json成功");
    }else{
        qDebug() << tr("解析json错误");
    }

    QJsonArray array = jsondoc.array();
    for(int i = 0; i < array.size(); i++)
    {
        QJsonObject data = array[i].toObject();
        if(city == data.value("city_name").toString() || city + "市" == data.value("city_name").toString() || city + "区" == data.value("city_name").toString() || city + "县" == data.value("city_name").toString() )
        {
            ip = "http://t.weather.itboy.net/api/weather/city/" + data.value("city_code").toString();
        }

    }
    file.close();

    QUrl url(ip);
    QNetworkRequest request(url);
       reply = manager->get(request);
       connect(reply, SIGNAL(finished()), this, SLOT(read_data()));
   }
