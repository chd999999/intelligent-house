#include "mvserial.h"

mvserial::mvserial(QObject *parent) : QObject(parent)
{
    mserial = new QSerialPort();
    //connect(mserial,SIGNAL(readyRead()),this,SLOT(recdata()));

}

mvserial::~mvserial()
{
    mserial->close();

}

QStringList mvserial::serialportname()
{
    QStringList namelist;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        namelist << info.portName();
        qDebug() << "port name : " << info.portName();
    }
    return namelist;
}

void mvserial::configserialport(QString port)
{
    mserial->setPortName(port);
    mserial->setBaudRate(QSerialPort::Baud115200);//设置波特率
    mserial->setDataBits(QSerialPort::Data8);//设置数据8位
    mserial->setParity(QSerialPort::NoParity);//无校验位
    mserial->setFlowControl(QSerialPort::NoFlowControl);//无流控制
    mserial->setStopBits(QSerialPort::OneStop);//停止位1位
}

bool mvserial::openserialport()
{
    return mserial->open(QIODevice::ReadWrite);

}

void mvserial::recdata()
{
    QByteArray data = mserial->readAll();
    qDebug() << "receive data:" << data;

}
