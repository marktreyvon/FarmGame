#include "farmstore.h"
#include "ui_farmstore.h"
#include <QPushButton>
#include <QDebug>
#include <QStandardItem>
FarmStore::FarmStore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FarmStore)
{
    flag = 0;
    ui->setupUi(this);
    this->model = new QStandardItemModel;
    this->ui->tableView->setModel(model);

//    connect(this->ui->StoreKind,SIGNAL(currentIndexChanged(int)),this,SLOT(frushTable()));

//    connect(this->ui->btnBuy,SIGNAL(clicked(bool)),this,SLOT(buyClick()));
}

FarmStore::~FarmStore()
{
    delete ui;
    delete model;
}
//void FarmStore::updateMap(QMap<int, int> map)
//{
//    seedMap = map;
//}
void FarmStore::createTableModel(int idx)
{
    switch(idx)
    {
        case 1:{
                this->model->setHorizontalHeaderItem(0,new QStandardItem("请选择"));
                this->model->setHorizontalHeaderItem(1,new QStandardItem("名称"));
                this->model->setHorizontalHeaderItem(2,new QStandardItem("价格"));
                this->model->setHorizontalHeaderItem(3,new QStandardItem("成熟用时"));
                this->model->setHorizontalHeaderItem(4,new QStandardItem("产量"));
    }   case 2:{
                this->model->setHorizontalHeaderItem(0,new QStandardItem("请选择"));
                this->model->setHorizontalHeaderItem(1,new QStandardItem("名称"));
                this->model->setHorizontalHeaderItem(2,new QStandardItem("价格"));
                this->model->setHorizontalHeaderItem(3,new QStandardItem("缩短时间"));
    }
    }

}
//void FarmStore::frushTable()
//{
//    this->model->clear();
//    int kind = this->ui->StoreKind->currentIndex();
//    createTableModel(kind);
//    switch(kind)
//    {
//        case 1:{
//                for(int i=0;i<store->getSeedList().length();i++)
//                {
//                    this->model->setItem(i,1,new QStandardItem(store->getSeedList().at(i).getName()));
//                    this->model->setItem(i,2,new QStandardItem(QString::number(store->getSeedList().at(i).getBuyPrice())));
//                    this->model->setItem(i,3,new QStandardItem(QString::number(store->getSeedList().at(i).getNeedTime())));
//                    this->model->setItem(i,4,new QStandardItem(QString::number(store->getSeedList().at(i).getProduction())));
//                }
//                break;
//    }   case 2:{
//                for(int i=0;i<store->getFertilizerList().length();i++)
//                {
//                    this->model->setItem(i,1,new QStandardItem(store->getFertilizerList().at(i).getName()));
//                    this->model->setItem(i,2,new QStandardItem(QString::number(store->getFertilizerList().at(i).getBuyPrice())));
//                    this->model->setItem(i,3,new QStandardItem(QString::number(store->getFertilizerList().at(i).getCutTime())));
//                }
//                break;
//    }   default:{
//        this->model->clear();
//        createTableModel(0);
//        break;
//    }
//    }
//}
//void FarmStore::buyClick()
//{

//}





















