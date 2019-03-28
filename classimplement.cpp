//类的实现

#include <iostream>
#include <QTime>
#include <QString>
#include <QIcon>
#include <QList>
#include <mainclass.h>

//object
Object::Object(QString na, int bu, int se)
{
    this->name = na;
    this->buyPrice = bu;
    this->sellPrice = se;
    //this->icon = null;
}
int Object::getBuyPrice()const
{
    return this->buyPrice;
}
QString Object::getName() const
{
    return this->name;
}
int Object::getSellPrice()const
{
    return this->sellPrice;
}
QIcon Object::getIcon()const
{
    return this->icon;
}

//seed
Seed::Seed(QString na,int bu,int se,int nt,int pr):Object(na,bu,se)
{
    this->needTime = nt;
    this->production = pr;
}
int Seed::getNeedTime()const
{
    return this->needTime;
}
int Seed::getProduction()const
{
    return this->production;
}
//bool Seed::operator <(const Seed& s) const
//{
//    return false;
//}

//fertilizer
Fertilizer::Fertilizer(QString na,int bu,int se,int ct):Object(na,bu,se)
{
    this->cutTime = ct;
}
int Fertilizer::getCutTime()const
{
    return this->cutTime;
}
//bool Fertilizer::operator <(const Fertilizer& f) const
//{
//        return false;
//}

//store
Store::Store()
{
    Seed seed1("Apple",5,3,120,10);
    Seed seed2("Orange",5,3,120,10);
    Seed seed3("Tomato",5,3,120,10);
    Fertilizer  f1("普通化肥",10,4,80);
    Fertilizer  f2("优质化肥",10,4,100);
    seedList.append(seed1);
    seedList.append(seed2);
    seedList.append(seed3);
    fertilizerList.append(f1);
    fertilizerList.append(f2);
}
QList<Seed> Store::getSeedList()
{
    return this->seedList;
}

QList<Fertilizer> Store::getFertilizerList()
{
    return this->fertilizerList;
}
//Field
Field::Field(bool iss,Seed s):seed(s),isSow(iss)
{

}


//Backpack
Backpack::Backpack()
{
//    seedList = new QList<Seed>();
//    fertilizerList = new QList<Fertilizer>();
//    fruitList = new QList<Fruit>();
}

//Player
Player::Player(QString na):Backpack(),level(1),exp(5),coins(200)
{
    this->name = na;

}
QString Player::getName() const
{
    return this->name;
}
int Player::getLevel() const {
    return this->level;
}
int Player::getExp() const {
    return this->exp;
}
int Player::getCoins()  const{
    return this->coins;
}
void Player::expPlus(int num)
{
    exp+=num;
    if(exp>100)
    {
        level=level+(exp/100);
        exp=exp%100;
        levelUp();
    }

}
void Player::costCoins(int num)
{
    coins-=num;
    expPlus(num*3);
}
void Player::earnCoins(int num)
{
    coins +=num;
}
void Player::levelUp()
{
    QMessageBox qm;
    qm.setText("恭喜升级！");
    qm.exec();
}






