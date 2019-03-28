#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPushButton>
#include <qpushbutton.h>
#include "formsimpestore.h"
#include "farmbackpack.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void showBackpack();
    void frushWindow();
    ~MainWindow();
signals:
    void refresh(int k,int num);
    void fru();
public slots:
    void earnSlot(int num,int k,int sellNum);
    void sellSlot();
    void addBackpack(int k,int num);
    void frush();
private slots:
    void on_pushButtonSeed_clicked();

    void on_pushButtonStore_clicked();

private:
    Ui::MainWindow *ui;
    FormSimpeStore *formSimpleStore;
    Player * player;
    windowBuy * windowSell;
    FarmBackpack * farmBackpack;

};

#endif // MAINWINDOW_H
