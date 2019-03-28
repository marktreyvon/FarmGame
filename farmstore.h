#ifndef FARMSTORE_H
#define FARMSTORE_H

#include <QWidget>
#include <QStandardItem>
#include <QStandardItemModel>
namespace Ui {
class FarmStore;
}

class FarmStore : public QWidget
{
    Q_OBJECT

public:
    explicit FarmStore(QWidget *parent = 0);
    ~FarmStore();
    void createTableModel(int idx);
    //void updateMap(QMap<int,int> map);
    //public slots:
    //    void frushTable();
    //    void openStore();
    //private slots:
    //    void buyClick();
private:
    Ui::FarmStore *ui;
    QStandardItemModel * model;
    int flag ;
    QMap<int,int> seedMap;
};

#endif // FARMSTORE_H
