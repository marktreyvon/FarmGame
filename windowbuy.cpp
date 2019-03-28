#include "windowbuy.h"
#include "ui_windowbuy.h"
#include <QValidator>
#include <QDebug>
#include <QIcon>
windowBuy::windowBuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::windowBuy)
{
    ui->setupUi(this);

    QRegExp regx("[0-9]+$");//输入限制数字
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
    ui->lineEdit->setValidator( validator );

    connect(this->ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(frushSlot(int)));
}
void windowBuy::add(Player *p)
{

    map = p->seedMap ;

}

windowBuy::~windowBuy()
{
    delete ui;
}

void windowBuy::on_pushButtonPlus_clicked()
{
    int num = this->ui->lineEdit->text().toInt();
    num++;
    this->ui->lineEdit->setText(QString::number((double)num));
}

void windowBuy::on_pushButtonMInus_clicked()
{
    int num = this->ui->lineEdit->text().toInt();
    num--;
    this->ui->lineEdit->setText(QString::number((double)num));
}

//slot

void windowBuy::frushSlot(int index)
{
    int price,num;
    num = this->map.value(index);
    switch(index){
        case CHILI_ID:{
            this->ui->lbName->setText("Chili");
            price = 3;
            break;
        }
        case TOMATO_ID:{
            this->ui->lbName->setText("Tomato");
            price = 7;
            break;
        }
        case STRAWBERRY_ID:{
            this->ui->lbName->setText("Strawberry");
            price = 15;
            break;
        }
        case NORMALFERTILIZER_ID:{
            this->ui->lbName->setText("Normal Fertilizer");
            price = 5;
            break;
        }
        case GOODFERTILIZER_ID:{
            this->ui->lbName->setText("Good Fertilizer");
            price = 7;
            break;
        }
    case 6:{
        this->ui->lbName->setText("Chili Fruit");
        num = this->map.value(CHILI_FRUIT);
        price = 15;
        break;
    }
    case 7:{
        this->ui->lbName->setText("Tomato Fruit");
        num = this->map.value(TOMATO_FRUIT);
        price = 25;
        break;
    }
    case 8:{
        this->ui->lbName->setText("Strawberry Fruit");
        num = this->map.value(STRAWBERRY_FRUIT);
        price = 45;
        break;
    }
    default:{
        this->ui->lbName->setText(" ");
        price = 0;
        num = 0;
        break;
    }
    }
    qDebug()<<index<<price<<num<<num*price;
    this->ui->lbSinglePrice->setText(QString::number(price));
    this->ui->lbHaveNum->setText(QString::number(num));
    this->ui->lbPrice->setText(QString::number(num*price));
}

void windowBuy::refresh(int k,int num)
{
    if(map.contains(k))
    {
        int old = map.value(k);
        map.insert(k,old+num);
    }
}


void windowBuy::on_buttonBox_accepted()
{
    //showInfo();
    int sellNum = this->ui->lineEdit->text().toInt();
    int haveNum = this->ui->lbHaveNum->text().toInt();
    int coins =sellNum* this->ui->lbSinglePrice->text().toInt();
    //qDebug()<<sellNum<<"  "<<haveNum;
    if(sellNum <= haveNum &&sellNum >0)
    {
        emit earnSignal(coins,this->ui->comboBox->currentIndex(),sellNum);
    }
    else
    {
        QMessageBox mgb;
        mgb.setText("数量不足！");
        mgb.exec();
    }
}

void windowBuy::showInfo()
{
    QMap<int , int>::iterator mapIter = map.begin();
    int i=0;
    for(; mapIter !=  map.end()&&i<map.size();mapIter++)
    {
        qDebug()<<mapIter.key()<<mapIter.value();
        i++;
    }
}
