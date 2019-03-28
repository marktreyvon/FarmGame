#ifndef WINDOWBUY_H
#define WINDOWBUY_H

#include <QDialog>
#include <QPushButton>
#include <QMap>
#include "mainclass.h"
#include <QMessageBox>
namespace Ui {
class windowBuy;
}

class windowBuy : public QDialog
{
    Q_OBJECT

public:
    explicit windowBuy(QWidget *parent = 0);
    void add(Player * p);
    void showInfo();
    ~windowBuy();
signals:
    void earnSignal(int num,int k,int sellNum);
public slots:
    void refresh(int k,int num);
private slots:
    void frushSlot(int index);
    void on_pushButtonPlus_clicked();

    void on_pushButtonMInus_clicked();

    void on_buttonBox_accepted();

private:
    Ui::windowBuy *ui;
    QMap<int,int> map;
};

#endif // WINDOWBUY_H
