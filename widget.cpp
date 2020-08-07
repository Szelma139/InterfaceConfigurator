﻿#include "widget.h"
#include "ui_widget.h"


#include <interfacetab.h>

#include <interfaceconfigurator.h>

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

        for (int i=0;i<tabs.length();i++){
           InterfaceTab * tabPointer = new InterfaceTab(this);
           p_tabs.append(tabPointer);
            ui->tabWidget->addTab(p_tabs[i],QString::number(i+1)+ ". " + tabs[i]);
        }



}

