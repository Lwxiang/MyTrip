#ifndef PASTTRIPPAGE_H
#define PASTTRIPPAGE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QGridLayout>
#include <QDate>
#include <QPixmap>
#include <QDebug>
#include <QTextCodec>
#include <QFont>

namespace Ui {
class pastTripPage;
}

class pastTripPage : public QWidget
{
    Q_OBJECT

public:
    explicit pastTripPage(QWidget *parent = 0);
    QGridLayout *layout;
    QString *HEAD;
    int totalTrip;
    QLabel *tripNameLabel[20];
    int totalSpot;
    QLabel *viewSpot[20][20];
    QLabel *timeSpot[20][20];
    QString *mark[20];
    QLabel *went[20][20];
    void layoutRefresh();
    ~pastTripPage();

private:
    void findString(QString *, QString *, int *);
    Ui::pastTripPage *ui;
};

#endif // PASTTRIPPAGE_H
