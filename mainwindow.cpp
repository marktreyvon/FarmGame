#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QString>
#include <QDebug>

#include "windowbuy.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    formSimpleStore = new FormSimpeStore();
    player = new Player("player1");
    windowSell = new windowBuy();
    farmBackpack = new FarmBackpack();
    frushWindow();

    this->player->seedMap.insert(CHILI_FRUIT,111);
    this->player->seedMap.insert(TOMATO_FRUIT,222);
    this->player->seedMap.insert(STRAWBERRY_FRUIT,333);


    connect(this->ui->pushButtonStore,SIGNAL(clicked(bool)),this->formSimpleStore,SLOT(openStore()));
    connect(this->formSimpleStore,SIGNAL(buySignal(int,int)),this,SLOT(addBackpack(int,int)));
    connect(this,SIGNAL(fru()),this,SLOT(frush()));
    connect(this->formSimpleStore,SIGNAL(sell()),this,SLOT(sellSlot()));
    connect(this,SIGNAL(refresh(int,int)),this->windowSell,SLOT(refresh(int,int)));
    connect(this->windowSell,SIGNAL(earnSignal(int,int,int)),this,SLOT(earnSlot(int,int,int)));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete formSimpleStore;
    delete player;
}
void MainWindow::frushWindow()
{
    this->ui->lbName->setText(player->getName());
    this->ui->lbLevel->setText("Lv."+QString::number(player->getLevel()));
    this->ui->lbExpNum->setText(QString::number(player->getExp())+"/100");
    this->ui->lbCoinsNum->setText(QString::number(player->getCoins()));
}
void MainWindow::showBackpack()
{
    QMap<int , int>::iterator mapIter = this->player->seedMap.begin();
    for(; mapIter !=  this->player->seedMap.end();mapIter++)
    {
        switch(mapIter.key())
        {
            case CHILI_ID:
            {
            qDebug()<<"Chili\t\t"<<mapIter.value();
                break;
            }
            case TOMATO_ID:
            {
            qDebug()<<"Tomato\t\t"<<mapIter.value();
    //        Seed s2("Tomato",10,7,30,5);
    //        this->player->seedMap.insert(s2,num);
            break;
            }
            case STRAWBERRY_ID:
            {
            qDebug()<<"Strawberry\t\t"<<mapIter.value();
    //        Seed s3("Strawberry",20,15,30,3);
    //        this->player->seedMap.insert(s3,num);
            break;
            }
            case NORMALFERTILIZER_ID:
            {
            qDebug()<<"NormalFertilizer\t\t"<<mapIter.value();
    //        Fertilizer f1("NormalFertilizer",10,5,10);
    //        this->player->fertilizerMap.insert(f1,num);
            break;
            }
            case GOODFERTILIZER_ID:
            {
            qDebug()<<"GoodFertilizer\t\t"<<mapIter.value();
    //        Fertilizer f2("GoodFertilizer",15,7,20);
    //        this->player->fertilizerMap.insert(f2,num);
            break;
            }
        default:break;
        }
    }
    qDebug()<<"coins:\t"<<this->player->getCoins();

}

//slot
void MainWindow::frush()
{
    frushWindow();
}

void MainWindow::addBackpack(int k,int num)
{
    emit refresh(k,num);
    if(this->player->seedMap.contains(k))
    {
        int i = this->player->seedMap.value(k);
        this->player->seedMap.insert(k,i+num);
    }
    else
        this->player->seedMap.insert(k,num);

    switch(k)
    {
        case CHILI_ID:
        {
            this->player->costCoins(5*num);
            break;
        }
        case TOMATO_ID:
        {
            this->player->costCoins(10*num);
            break;
        }
        case STRAWBERRY_ID:
        {
            this->player->costCoins(20*num);
            break;
        }
        case NORMALFERTILIZER_ID:
        {
            this->player->costCoins(10*num);
            break;
        }
        case GOODFERTILIZER_ID:
        {
            this->player->costCoins(15*num);
            break;
        }
    default:break;
    }
    emit fru();
}
void MainWindow::on_pushButtonSeed_clicked()
{
    int s1,s2,s3,f1,f2,f11,f22,f33;
    if(this->player->seedMap.contains(CHILI_ID))
        s1 = this->player->seedMap.value(CHILI_ID);
    else
        s1 = 0;
    s2 = this->player->seedMap.value(TOMATO_ID);
    s3 = this->player->seedMap.value(STRAWBERRY_ID);
    f1 = this->player->seedMap.value(NORMALFERTILIZER_ID);
    f2 = this->player->seedMap.value(GOODFERTILIZER_ID);
    f11 = this->player->seedMap.value(CHILI_FRUIT);
    f22 = this->player->seedMap.value(TOMATO_FRUIT);
    f33 = this->player->seedMap.value(STRAWBERRY_FRUIT);
    this->farmBackpack->update(s1,s2,s3,f1,f2,f11,f22,f33);
    this->farmBackpack->show();

}

void MainWindow::sellSlot()
{
    this->windowSell->add(this->player);
    this->windowSell->exec();
}
void MainWindow::earnSlot(int num,int k,int sellNum)
{
//    QMap<int , int>::iterator mapIter = this->player->seedMap.begin();
//    int i=0;
//    for(; mapIter !=  this->player->seedMap.end()&&i<this->player->seedMap.size();mapIter++)
//    {
//        qDebug()<<mapIter.key()<<mapIter.value();
//        i++;
//    }
    switch (k) {
    case 6:
        k=11;
        break;
    case 7:
        k=22;
        break;
    case 8:
        k=33;
        break;
    default:
        break;
    }
    int old = this->player->seedMap.value(k);
    this->player->seedMap.insert(k,old-sellNum);
    this->player->earnCoins(num);
    emit fru();

}


void MainWindow::on_pushButtonStore_clicked()
{

}
