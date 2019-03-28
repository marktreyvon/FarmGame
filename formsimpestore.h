#ifndef FORMSIMPESTORE_H
#define FORMSIMPESTORE_H

#include <QWidget>
#include <QCloseEvent>
#include "windowbuy.h"
namespace Ui {
class FormSimpeStore;
}

class FormSimpeStore : public QWidget
{
    Q_OBJECT

public:
    explicit FormSimpeStore(QWidget *parent = 0);
    ~FormSimpeStore();
signals:
    void buySignal(int k,int num);
    void sell();
private slots:
    void on_pushButtonP_clicked();

    void on_pushButtonM_clicked();
    void on_pushButtonSell_clicked();

    void on_pushButtonBuy_clicked();

public slots:
    void buy();
    void openStore();
private:
    Ui::FormSimpeStore *ui;
};

#endif // FORMSIMPESTORE_H
