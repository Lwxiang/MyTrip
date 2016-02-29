#include "pasttrippage.h"
#include "ui_pasttrippage.h"

pastTripPage::pastTripPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pastTripPage)
{
    ui->setupUi(this);
    this->setMaximumSize(1260,576);
    this->setMinimumSize(1260,576);
    HEAD = new QString;
    *HEAD = "../project1/";

    for (int i=0; i<10; i++)
    {
        tripNameLabel[i] = new QLabel;
        mark[i] = new QString;
    }
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            viewSpot[i][j] = new QLabel;
            timeSpot[i][j] = new QLabel;
            went[i][j] = new QLabel;
        }
    layout = new QGridLayout;
    layoutRefresh();
}

void pastTripPage::layoutRefresh()
{
    //清理布局
    for (int i=0; i<10; i++)
    {
        tripNameLabel[i]->setParent(NULL);
        layout->removeWidget(tripNameLabel[i]);
        tripNameLabel[i]->clear();
    }
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            viewSpot[i][j]->setParent(NULL);
            timeSpot[i][j]->setParent(NULL);
            went[i][j]->setParent(NULL);
            layout->removeWidget(viewSpot[i][j]);
            layout->removeWidget(timeSpot[i][j]);
            layout->removeWidget(went[i][j]);
            viewSpot[i][j]->clear();
            timeSpot[i][j]->clear();
            went[i][j]->clear();
        }
    delete(layout);

    //重新布局
    QPixmap icon;
    icon.load(":/icon/img/icon/nowL.png");
    QPixmap fly;
    fly.load(":/icon/img/icon/go.png");

    layout = new QGridLayout;
    for (int i=0; i<10; i++)
    {
        layout->addWidget(tripNameLabel[i], i, 0);
        layout->addWidget(went[i][7], i, 1);
        int row=2;
        for (int j=0; j<7; j++)
         {
            layout->addWidget(viewSpot[i][j], i, row);
            row += 1;
            layout->addWidget(timeSpot[i][j], i, row);
            row += 1;
            layout->addWidget(went[i][j], i, row);
            row += 1;
         }
    }
    setLayout(layout);

    //获取信息
    QFile *file = new QFile;
    file->setFileName(*HEAD + "trips.inf");
    file->open(QIODevice::ReadOnly);
    QTextStream in1(file);
    QString active = in1.readAll();
    file->close();
    file->setFileName(*HEAD + "users.inf");
    file->open(QIODevice::ReadOnly);
    QTextStream in2(file);
    QString totS = in2.readAll();
    file->close();
    totalTrip = totS.toInt();
    if (active == "1") totalTrip--;
    int row = 0;
    QFont font;
    font.setPixelSize(14);
    for (int n=totalTrip-1; n>=0; n--)
    {
        QString nowS;
        nowS.setNum(n);
        file->setFileName(*HEAD + "users/" + nowS + ".inf");
        file->open(QIODevice::ReadOnly);
        QTextStream input(file);
        input.setCodec(QTextCodec::codecForName("UTF-8"));
        QString line = input.readAll();
        file->close();
        int i = 0;
        QString tmp = "";
        findString(&line, &tmp, &i);
        tripNameLabel[row]->setText(tmp);
        tripNameLabel[row]->setFont(font);
        findString(&line, &tmp, &i);
        totalSpot = tmp.toInt();
        QDate *date = new QDate;
        for (int j=0; j<totalSpot; j++)
        {
            findString(&line, &tmp, &i);
            viewSpot[row][j]->setText(tmp);
            viewSpot[row][j]->setFont(font);
            findString(&line, &tmp, &i);
            int year = tmp.toInt();
            findString(&line, &tmp, &i);
            int month = tmp.toInt();
            findString(&line, &tmp, &i);
            int day = tmp.toInt();
            date->setDate(year, month, day);
            timeSpot[row][j]->setText(date->toString("yyyy-MM-dd"));
            timeSpot[row][j]->setFont(font);
            went[row][j]->setPixmap(icon);
        }
        went[row][totalSpot-1]->clear();
        went[row][7]->setPixmap(fly);
        findString(&line, &tmp, &i);
        *(mark[row]) = tmp;
        row++;
    }
}

void pastTripPage::findString(QString *line, QString *tmp, int *index)
{
    *tmp = "";
    while ((*line)[(*index)] != '&')
    {
        *tmp = *tmp + (*line)[(*index)];
        *index = *index + 1;
    }
    *index = *index + 1;
}

pastTripPage::~pastTripPage()
{
    delete ui;
}
