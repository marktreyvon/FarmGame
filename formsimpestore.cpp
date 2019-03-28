#include "formsimpestore.h"
#include "ui_formsimpestore.h"
#include <QButtonGroup>
#include <QPixmap>
#include <QRegExp>
#include <QValidator>
#include <QPalette>

FormSimpeStore::FormSimpeStore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormSimpeStore)
{
    ui->setupUi(this);
    QButtonGroup * qbg = new QButtonGroup();
    qbg->addButton(this->ui->btnChili);
    qbg->addButton(this->ui->btnTomato);
    qbg->addButton(this->ui->btnStrawberry);
    qbg->addButton(this->ui->btnGoodFertilizer);
    qbg->addButton(this->ui->btnNormalFertilizer);
    qbg->setExclusive(true);
    QRegExp regx("[0-9]+$");//输入限制数字
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit );
    ui->lineEdit->setValidator( validator );
    connect(this->ui->pushButtonBuy,SIGNAL(clicked(bool)),this,SLOT(buy()));

    QPalette pal(this->palette());

    //设置背景黑色
    pal.setColor(QPalette::Background, Qt::gray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);


}

FormSimpeStore::~FormSimpeStore()
{
    delete ui;
}

//slot

void FormSimpeStore::openStore()
{
    this->show();
}

void FormSimpeStore::buy()
{
    int buyNum = this->ui->lineEdit->text().toInt();
    if(buyNum > 0)
    {
        if(this->ui->btnChili->isChecked())
        {
            emit buySignal(CHILI_ID,buyNum);
        }
        if(this->ui->btnTomato->isChecked())
        {
            emit buySignal(TOMATO_ID,buyNum);
        }
        if(this->ui->btnStrawberry->isChecked())
        {
            emit buySignal(STRAWBERRY_ID,buyNum);
        }
        if(this->ui->btnNormalFertilizer->isChecked())
        {
            emit buySignal(NORMALFERTILIZER_ID,buyNum);
        }
        if(this->ui->btnGoodFertilizer->isChecked())
        {
            emit buySignal(GOODFERTILIZER_ID,buyNum);
        }
    }

}

void FormSimpeStore::on_pushButtonP_clicked()
{
    int num = this->ui->lineEdit->text().toInt();
    num++;
    this->ui->lineEdit->setText(QString::number((double)num));
}

void FormSimpeStore::on_pushButtonM_clicked()
{
    int num = this->ui->lineEdit->text().toInt();
    num--;
    this->ui->lineEdit->setText(QString::number((double)num));
}

void FormSimpeStore::on_pushButtonSell_clicked()
{
    emit sell();
}

void FormSimpeStore::on_pushButtonBuy_clicked()
{

}
