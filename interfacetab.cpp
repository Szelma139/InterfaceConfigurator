#include "interfacetab.h"
#include "ui_interfacetab.h"

InterfaceTab::InterfaceTab(QWidget *parent, bool isDhcp) :
    QWidget(parent),
    ui(new Ui::InterfaceTab)
{
    ui->setupUi(this);



    connect (ui->radioButtonDHCP, &QRadioButton::toggled,
             this,&InterfaceTab::disableInterface);

    connect (ui->radioButtonManual, &QRadioButton::toggled,
             this, &InterfaceTab::enableInterface);

    if (isDhcp) ui->radioButtonDHCP->setChecked(true);
    else ui->radioButtonManual->setChecked(false);

}

InterfaceTab::~InterfaceTab()
{
    delete ui;
}

Ui::InterfaceTab *InterfaceTab::getUi() const
{
    return ui;
}

void InterfaceTab::setUi(Ui::InterfaceTab *value)
{
    ui = value;
}



void InterfaceTab::disableInterface(){

    ui->lineEditIp->setDisabled(true);
    ui->lineEditMask->setDisabled(true);
    ui->lineEditGateway->setDisabled(true);

    ui->lineEditIp->hide();
    ui->lineEditMask->hide();
    ui->lineEditGateway->hide();

 isUiDisabled = true;

}

void InterfaceTab::setIp(QString ip){

    ui->lineEditIp->setText(ip);
}

void InterfaceTab::setMask(QString netmask){
    ui->lineEditMask->setText(netmask);
}

void InterfaceTab::setGateway(QString gateway){
    ui->lineEditGateway->setText(gateway);
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

