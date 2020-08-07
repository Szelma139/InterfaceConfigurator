#include "interfaceconfigurator.h"

#include <QProcess>
#include <QDebug>
#include <QRegularExpression>

#include <interfaceconfigurator.h>

#include <QFile>


QString NETWORK_FILE = "/etc/network/interfaces-test";

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
         //   qDebug()<<data2;

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
         //   qDebug()<<"elment"<<element;
        }
    }



    QStringList fileContents;

    /*
    QStringList possibleValues = {"iface", "mapping", "allow", "source"};
    QStringList list = {};

    QFile inputFile(NETWORK_FILE);
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
           QString line = in.readLine();
            if(line.startsWith("iface") || line.startsWith("auto"))
            {

            }
            else {
                list.append(line);

            }

       }

    }
*/

    QFile inputFile(NETWORK_FILE);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&inputFile);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            if(!line.isEmpty() || !line.startsWith("#") || (!line.contains("lo"))){
                    fileContents.append(line);

            }

        }
        inputFile.close();


        QString currentLine;
        int stringLines= fileContents.length()-1;
        int i = 0 ;
        while(i!=stringLines){
            currentLine = fileContents[i];


            if (fileContents[i].contains("auto")){
                Interface * automatic = new Interface();

                //qDebug()<<"Auto - " + fileContents[i];
                for (QString interfaceName:elements){
                    if (fileContents[i].contains(interfaceName)){
                        automatic->setName(interfaceName);
                    }

                }
                automatic->setIsAuto(true);
               // qDebug()<<"Auto 2 -" + fileContents[i+1];
                interfacesList.append(automatic);
                i+=2;
            }
            else if(fileContents[i].contains("static")){
                Interface * manual = new Interface ();

                for (QString interfaceName:elements){
                    if (fileContents[i].contains(interfaceName)){
                        manual->setName(interfaceName);
                    }

                }
                manual->setIpAddress(fileContents[i+1].mid(7));
                manual->setNetmask(fileContents[i+2].mid(7));

                manual->setGateway(fileContents[i+3].mid(7));
                manual->setIsAuto(false);

                interfacesList.append(manual);

             //   qDebug()<<"Manual " + fileContents[i];
                 //   qDebug()<<"Manual 2 " +fileContents[i+1];
                     //   qDebug()<<"Manual 3" +fileContents[i+2];
                        //    qDebug()<<"Manual 4" +fileContents[i+3];
                            i+=3;





            }
            else i++;
        }


        for (Interface * interface : interfacesList){
            qDebug()<<interface->getName()
                   <<interface->getIsAuto()
                  <<interface->getGateway()
                 <<interface->getIpAddress()
                <<interface->getNetmask();
        }




    }


    return elements;
}

QList<Interface *> InterfaceConfigurator::getInterfacesList() const
{
    return interfacesList;
}

void InterfaceConfigurator::setInterfacesList(const QList<Interface *> &value)
{
    interfacesList = value;
}




