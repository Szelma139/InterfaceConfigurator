#include "widget.h"
#include "ui_widget.h"


#include <interfacetab.h>

#include <interfaceconfigurator.h>
#include <interface.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    interfaceConfigurator = new InterfaceConfigurator(this);

    createInterfaceTabs();

    //ui->tabWidget->addTab(tabPointer,"test");


}

Widget::~Widget()
{
    delete ui;
}


void Widget::createInterfaceTabs(){

        QStringList tabs = interfaceConfigurator->fetchInterfaceNames();
        QList<Interface*> interfaces = interfaceConfigurator->getInterfacesList();


        for (Interface * interface:interfaces){

        for (int i=0;i<tabs.length();i++){
            if(interface->getName() == tabs[i]){

                if (interface->getIsAuto()){
                    InterfaceTab * tabPointer = new InterfaceTab(this,true);
                    p_tabs.append(tabPointer);
                     ui->tabWidget->addTab(tabPointer,QString::number(i+1)+ ". " + tabs[i]);
                   // p_tabs[i]->
                }
                else if(!interface->getIsAuto())
                {
                    InterfaceTab * tabPointer = new InterfaceTab(this,false);
                    p_tabs.append(tabPointer);

                    tabPointer->setIp(interface->getIpAddress());
                    tabPointer->setMask(interface->getNetmask());
                    tabPointer->setGateway(interface->getGateway());

                     ui->tabWidget->addTab(tabPointer,QString::number(i+1)+ ". " + tabs[i]);
                   // p_tabs[i]->
                }



               }
            }





        }



       // for (int i=0;i<p_tabs.size();i++){
        //
         //  for (Interface * interface: interfaces){
          //     ui->tabWidget[0].
          // }
       // }



}

