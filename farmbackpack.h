#ifndef FARMBACKPACK_H
#define FARMBACKPACK_H

#include <QWidget>

namespace Ui {
class FarmBackpack;
}

class FarmBackpack : public QWidget
{
    Q_OBJECT

public:
    explicit FarmBackpack(QWidget *parent = 0);
    ~FarmBackpack();
    void update(int s1,int s2,int s3,int f1,int f2,int f11,int f22,int f33);
private:
    Ui::FarmBackpack *ui;
};

#endif // FARMBACKPACK_H
