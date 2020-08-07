#ifndef INTERFACE_H
#define INTERFACE_H

#include <QString>

class Interface
{
public:
    Interface();
    Interface(QString Name, QString Netmask, QString IpAddress, bool isAuto);


    QString getName() const;
    void setName(const QString &value);

    QString getNetmask() const;
    void setNetmask(const QString &value);

    QString getIpAddress() const;
    void setIpAddress(const QString &value);

    bool getIsAuto() const;
    void setIsAuto(bool value);

    QString getGateway() const;
    void setGateway(const QString &value);

private:
    QString Name;
    QString Netmask;
    QString IpAddress;
    bool isAuto = false;
    QString Gateway;

};

#endif // INTERFACE_H
