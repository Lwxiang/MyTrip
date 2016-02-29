#ifndef NOWTRIPPAGE_H
#define NOWTRIPPAGE_H

#include "diaryholder.h"
#include "photoholder.h"
#include "newtrippage.h"
#include <maparea.h>

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QToolButton>
#include <QPixmap>
#include <QDateEdit>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTextCodec>
#include <QChar>
#include <QPixmap>
#include <QFont>

namespace Ui {
class nowTripPage;
}

class nowTripPage : public QWidget
{
    Q_OBJECT

public:
    explicit nowTripPage(QWidget *parent = 0);
    QLabel *arrived[20];
    QLabel *viewSpot[20];
    QString *viewSpots[20];
    QLabel *timeSpot[20];
    QToolButton *photos[20];
    QToolButton *diary[20];
    QToolButton *cancel[20];
    QToolButton *next;
    QToolButton *finish;
    QGridLayout *leftLayout;
    QGridLayout *rightLayout;
    QHBoxLayout *layout;
    photoHolder *photoEdit;
    DiaryHolder *diaryEdit;
    QLabel *tripNameLabel;
    QString mark;
    mapArea *map;
    QString infUrl;
    bool active;
    bool fromNew;
    int totalSpot;
    int nowSpot;
    void layoutRefresh();
    void storeMark();
    void cancelSpot(int);
    QString *HEAD;
    ~nowTripPage();

signals:
    void finishNow();

private:
    void loadInf();
    void findString(QString*, QString*, int*);
    void openPhotoHolder(int);
    void openDiaryHolder(int);
    Ui::nowTripPage *ui;

private slots:
    void nextSpot();
    void photoSpot_0();
    void photoSpot_1();
    void photoSpot_2();
    void photoSpot_3();
    void photoSpot_4();
    void photoSpot_5();
    void photoSpot_6();
    void diarySpot_0();
    void diarySpot_1();
    void diarySpot_2();
    void diarySpot_3();
    void diarySpot_4();
    void diarySpot_5();
    void diarySpot_6();
    void sendFinishNowSinal();
    void cancelSpot_0();
    void cancelSpot_1();
    void cancelSpot_2();
    void cancelSpot_3();
    void cancelSpot_4();
    void cancelSpot_5();
    void cancelSpot_6();
};

#endif // NOWTRIPPAGE_H
