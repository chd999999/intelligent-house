#ifndef MVSERIAL_H
#define MVSERIAL_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QString>
#include <QStringList>

class mvserial : public QObject
{
    Q_OBJECT
public:
    explicit mvserial(QObject *parent = nullptr);
    ~mvserial();

    QStringList serialportname();
    void configserialport(QString port);
    bool openserialport();
QSerialPort *mserial;

signals:

public slots:
    void recdata();

private:

};

#endif // MVSERIAL_H
