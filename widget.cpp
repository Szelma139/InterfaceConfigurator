#include "widget.h"
#include "ui_widget.h"


#include <interfacetab.h>

#include <interfaceconfigurator.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    interfaceConfigurator = new InterfaceConfigurator(this);


    createTabs();

    //ui->tabWidget->addTab(tabPointer,"test");



}

Widget::~Widget()
{
    delete ui;
}


void Widget::createTabs(){

        QStringList tabs = interfaceConfigurator->fetchInterfaceNames();

        for (int i=0;i<tabs.length();i++){
            tabPointer = new InterfaceTab(this);
            ui->tabWidget->addTab(tabPointer,QString::number(i+1)+ ". " + tabs[i]);
        }



}

