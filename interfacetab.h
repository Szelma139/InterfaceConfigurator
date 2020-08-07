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
    explicit InterfaceTab(QWidget *parent = nullptr);
    ~InterfaceTab();

private:
    Ui::InterfaceTab *ui;

    bool isUiDisabled;



public slots:
    void disableInterface();
    void enableInterface();


};

#endif // INTERFACETAB_H
