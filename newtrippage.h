#ifndef NEWTRIPPAGE_H
#define NEWTRIPPAGE_H

#include <maparea.h>

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDate>
#include <QDateEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPixmap>
#include <QToolButton>
#include <QString>
#include <qDebug>

namespace Ui {
class newTripPage;
}

class newTripPage : public QWidget
{
    Q_OBJECT

public:
    explicit newTripPage(QWidget *parent = 0);
    QGridLayout *leftLayout;
    QGridLayout *rightLayout;
    QHBoxLayout *layout;
    QLineEdit *viewSpotEdit[20];
    QDateEdit *timeSpotEdit[20];
    QToolButton *addButton[20];
    QToolButton *cancelButton[20];
    QToolButton *add;
    QToolButton *addtop;
    QToolButton *finish;
    QString *viewSpots[20];
    QDate *timeSpots[20];
    QLineEdit *tripNameEdit;
    QString *tripName;
    QLabel *tripNameLabel;
    mapArea *map;
    int totalSpot;
    bool onEdit;
    void layoutRefresh();
    ~newTripPage();

private:
    bool wantAdd;
    void addSpot(int);
    void deleteSpot(int);
    void storeSpot(int);
    Ui::newTripPage *ui;

private slots:
    void storeTripName();
    void makeAddChoice();
    void makeAddSignal_top();
    void makeAddSignal_0();
    void makeAddSignal_1();
    void makeAddSignal_2();
    void makeAddSignal_3();
    void makeAddSignal_4();
    void makeAddSignal_5();
    void makeAddSignal_6();
    void makeDeleteSignal_0();
    void makeDeleteSignal_1();
    void makeDeleteSignal_2();
    void makeDeleteSignal_3();
    void makeDeleteSignal_4();
    void makeDeleteSignal_5();
    void makeDeleteSignal_6();
    void makeStoreSpotSignal_0();
    void makeStoreSpotSignal_1();
    void makeStoreSpotSignal_2();
    void makeStoreSpotSignal_3();
    void makeStoreSpotSignal_4();
    void makeStoreSpotSignal_5();
    void makeStoreSpotSignal_6();
};

#endif // NEWTRIPPAGE_H
