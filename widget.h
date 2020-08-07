#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class InterfaceTab;
class InterfaceConfigurator;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    //InterfaceTab * tabPointer;
    QList<InterfaceTab *> p_tabs;
    InterfaceConfigurator * interfaceConfigurator;




    void createTabs();
};
#endif // WIDGET_H
