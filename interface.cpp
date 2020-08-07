#include "interface.h"

Interface::Interface()
{

}

Interface::Interface(QString Name, QString Netmask, QString IpAddress, bool isAuto)
{

    this->Name = Name;
    this->Netmask = Netmask;
    this->IpAddress = IpAddress;
    this->isAuto = isAuto;
}

QString Interface::getName() const
{
    return Name;
}

void Interface::setName(const QString &value)
{
    Name = value;
}

QString Interface::getNetmask() const
{
    return Netmask;
}

void Interface::setNetmask(const QString &value)
{
    Netmask = value;
}

QString Interface::getIpAddress() const
{
    return IpAddress;
}

void Interface::setIpAddress(const QString &value)
{
    IpAddress = value;
}

bool Interface::getIsAuto() const
{
    return isAuto;
}

void Interface::setIsAuto(bool value)
{
    isAuto = value;
}

QString Interface::getGateway() const
{
    return Gateway;
}

void Interface::setGateway(const QString &value)
{
    Gateway = value;
}
