#include "interfaceconfigurator.h"

#include <QProcess>
#include <QDebug>
#include <QRegularExpression>



InterfaceConfigurator::InterfaceConfigurator(QObject * parent)
    :QObject(parent)
{

}



QStringList InterfaceConfigurator::fetchInterfaceNames(){
    QString data2;
    QString proc ="/bin/bash";
    QProcess process;
    QStringList arguments;
    QStringList elements;

    process.start(proc,arguments);
    if (process.waitForStarted()){
        process.write("ip a s");

        process.closeWriteChannel();

        if (process.waitForFinished()){

            data2 =  QString(process.readAllStandardOutput());
            qDebug()<<data2;

        }



        QRegularExpression reA("[\\d]: [a-z 0-9]{3,25}");

        QRegularExpressionMatchIterator i = reA.globalMatch(data2);
        while (i.hasNext()) {
            QRegularExpressionMatch match = i.next();
            if (match.hasMatch()) {
                elements.append(match.captured(0));
            }
        }

        for (QString & element: elements){
            element = element.mid(3,element.length()-3);
            qDebug()<<"elment"<<element;
        }
    }
    return elements;
}
