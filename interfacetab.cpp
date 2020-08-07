#include "interfacetab.h"
#include "ui_interfacetab.h"

InterfaceTab::InterfaceTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InterfaceTab)
{
    ui->setupUi(this);
    connect (ui->radioButtonDHCP, &QRadioButton::toggled,
             this,&InterfaceTab::disableInterface);

    connect (ui->radioButtonManual, &QRadioButton::toggled,
             this, &InterfaceTab::enableInterface);

}

InterfaceTab::~InterfaceTab()
{
    delete ui;
}



void InterfaceTab::disableInterface(){

 ui->lineEditIp->setDisabled(true);
 ui->lineEditMask->setDisabled(true);
 ui->lineEditGateway->setDisabled(true);

 isUiDisabled = true;

}


void InterfaceTab::enableInterface(){

    ui->lineEditIp->setDisabled(false);
    ui->lineEditMask->setDisabled(false);
    ui->lineEditGateway->setDisabled(false);
    isUiDisabled = false;

    ui->lineEditIp->show();
    ui->lineEditMask->show();
    ui->lineEditGateway->show();

}

