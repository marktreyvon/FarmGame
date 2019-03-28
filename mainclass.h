#ifndef MAINCLASS
#define MAINCLASS

#endif // MAINCLASS
#include <iostream>
#include <QTime>
#include <QString>
#include <QIcon>
#include <QList>
#include <QMap>
#include <QMessageBox>

#define CHILI_ID 1
#define TOMATO_ID 2
#define STRAWBERRY_ID 3
#define NORMALFERTILIZER_ID 4
#define GOODFERTILIZER_ID 5
#define CHILI_FRUIT 11
#define TOMATO_FRUIT 22
#define STRAWBERRY_FRUIT 33



enum Status{normal,haveGrass,haveWorm,needWater,isWither};              //土地的状态：正常，有草，有虫，缺水，枯萎

class Object        //物品基类
{
private:
    QString name;       //名字
    int buyPrice;       //买入价格
    int sellPrice;      //卖出价格
    QIcon icon;         //图标
public:
    Object(){}
    Object(QString na,int bu,int se);
    int getBuyPrice()const;
    int getSellPrice()const;
    QString getName()const;
    QIcon getIcon()const;
    void setIcon(QIcon ic);     //
};

class Seed:public Object        //种子类：继承物品类
{
private:
    int ID;                 //ID
    int production;         //产量
    int needTime;              //成熟需要的时间
public:
    Seed(){}
    Seed(QString na,int bu,int se,int nt,int pr);
    int getNeedTime()const;
    int getProduction()const;
    bool operator < (const Seed& s) const;
};

class Field
{
private:
    int ID;                 //ID
    bool isMature;              //是否成熟
    bool isPick;              //是否采摘
    bool isSow;              //是否播种
    Status status;              //状态（缺水等）
    Seed seed;              //种的种类
    QTime sowTime;              //种下的时间
    QTime matureTime;              //理论成熟时间
public:
    Field(){}
    Field(bool iss,Seed s);
    bool getIsSow()const;
    bool getIsStatus()const;
    bool getIsMature()const;
    bool getIsIsPick()const;
    Seed getSeed()const;
    QTime getSowTime()const;
    QTime getMatureTime()const;
    bool meetProblem();              //成长遇到问题
    bool sow();              //播种
    bool pick();              //采摘
    bool shovel();              //铲除（枯萎或者正常）
    bool killGrass();              //除草
    bool killWorm();              //除虫
    bool water();              //浇水

};

class Problem              //遇到的问题类  （需要？）
{
private:
    QString pname;
public:

};

class Fertilizer:public Object              //肥料类：继承物品类
{
private:
    int cutTime;              //缩短时间
public:
    Fertilizer(QString na,int bu,int se,int ct);
    int getCutTime()const;
    bool operator <(const Fertilizer& f)const;
};
class Fruit:public Object              //果实类：继承物品
{

};

class Backpack              //背包类
{
public:
    QMap<int,int> seedMap;              //种子集
//    QMap<Fruit,int> fruitMap;              //果实集
//    QMap<Fertilizer,int> fertilizerMap;              //肥料集
    Backpack();
    void sum();              //统计资产
};

class Player:public Backpack              //玩家类：继承背包
{
private:
    QString name;           //名字
    int level;              //等级
    int exp;              //经验值
    int coins;              //金币数
    QMap<Field,int> fieldMap;              //解锁的土地集
    QIcon icon;
public:
    Player():Backpack(){}
    Player(QString na);
    QString getName()const;
    int getLevel()const;
    int getExp()const;
    int getCoins()const;
    void costCoins(int num);
    void earnCoins(int num);
    void expPlus(int num);
    void levelUp();              //升级 （exp每满100升一级）
    void sell();              //出售
};

class Store              //商店类
{
private:
    QList<Seed> seedList;              //可购买的种子
    QList<Fertilizer> fertilizerList;              //可购买的肥料
public:
    Store();
    void buy();              //购买
    QList<Seed> getSeedList();
    QList<Fertilizer> getFertilizerList();
};

class Gamesys              //游戏系统类
{
private:
    QList<Player> playerList;              //所有玩家集
public:


};



