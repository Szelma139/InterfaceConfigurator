#ifndef INTERFACECONFIGURATOR_H
#define INTERFACECONFIGURATOR_H

#include <QObject>

#include <interface.h>

class InterfaceConfigurator: public QObject
{
    Q_OBJECT
public:
    InterfaceConfigurator(QObject * parent);
    QStringList fetchInterfaceNames();

private:
    QList <Interface*> interfacesList;


public:
    QList<Interface *> getInterfacesList() const;
    void setInterfacesList(const QList<Interface *> &value);
};

#endif // INTERFACECONFIGURATOR_H
