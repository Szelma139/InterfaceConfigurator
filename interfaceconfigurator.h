#ifndef INTERFACECONFIGURATOR_H
#define INTERFACECONFIGURATOR_H

#include <QObject>

class InterfaceConfigurator: public QObject
{
    Q_OBJECT
public:
    InterfaceConfigurator(QObject * parent);
    QStringList fetchInterfaceNames();
};

#endif // INTERFACECONFIGURATOR_H
