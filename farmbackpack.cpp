#include "farmbackpack.h"
#include "ui_farmbackpack.h"

FarmBackpack::FarmBackpack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FarmBackpack)
{
    ui->setupUi(this);
}

FarmBackpack::~FarmBackpack()
{
    delete ui;
}
void FarmBackpack::update(int s1, int s2, int s3, int f1, int f2, int f11, int f22, int f33)
{
    this->ui->lbSeed1->setText("×"+QString::number(s1));
    this->ui->lbSeed2->setText("×"+QString::number(s2));
    this->ui->lbSeed3->setText("×"+QString::number(s3));
    this->ui->lbf1->setText("×"+QString::number(f1));
    this->ui->lbf2->setText("×"+QString::number(f2));
    this->ui->lbf11->setText("×"+QString::number(f11));
    this->ui->lbf22->setText("×"+QString::number(f22));
    this->ui->lbf33->setText("×"+QString::number(f33));
}
