#ifndef INTERFACETAB_H
#define INTERFACETAB_H

#include <QWidget>

namespace Ui {
class InterfaceTab;
}

class InterfaceTab : public QWidget
{
    Q_OBJECT

public:
    explicit InterfaceTab(QWidget *parent = nullptr, bool isDhcp = false);
    ~InterfaceTab();

    Ui::InterfaceTab *getUi() const;
    void setUi(Ui::InterfaceTab *value);


    void setIp(QString ip);

    void setMask(QString netmask);

    void setGateway(QString gateway);


private:
    Ui::InterfaceTab *ui;

    bool isUiDisabled;



public slots:
    void disableInterface();
    void enableInterface();


};

#endif // INTERFACETAB_H
