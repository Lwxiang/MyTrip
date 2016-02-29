#include "nowtrippage.h"
#include "ui_nowtrippage.h"

nowTripPage::nowTripPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nowTripPage)
{
    ui->setupUi(this);
    QPixmap icon;
    HEAD = new QString;
    *HEAD = "../project1/";
    //nowTrip窗口在contentWidget中，大小不能超过1279, 576
    this->setMaximumSize(1260,576);
    this->setMinimumSize(1260,576);
    map = new mapArea;
    layout = new QHBoxLayout;
    leftLayout = new QGridLayout;
    rightLayout = new QGridLayout;
    next = new QToolButton;
    icon.load(":/icon/img/icon/go.png");
    next->setIcon(icon);
    next->setIconSize(icon.size());
    next->setAutoRaise(true);
    finish = new QToolButton;
    icon.load(":/icon/img/icon/end.png");
    finish->setIcon(icon);
    finish->setIconSize(icon.size());
    finish->setAutoRaise(true);
    tripNameLabel = new QLabel;
    tripNameLabel->setMinimumHeight(40);
    QFont font;
    font.setPointSize(15);
    tripNameLabel->setFont(font);
    for (int i=0; i<8; i++)
    {
        arrived[i] = new QLabel;
        viewSpot[i] = new QLabel;
        viewSpots[i] = new QString;
        timeSpot[i] = new QLabel;
        photos[i] = new QToolButton;
        icon.load(":/icon/img/icon/pho.png");
        photos[i]->setIcon(icon);
        photos[i]->setIconSize(icon.size());
        photos[i]->setAutoRaise(true);
        diary[i] = new QToolButton;
        icon.load(":/icon/img/icon/pen.png");
        diary[i]->setIcon(icon);
        diary[i]->setIconSize(icon.size());
        diary[i]->setAutoRaise(true);
        cancel[i] = new QToolButton;
        icon.load(":/icon/img/icon/not.png");
        cancel[i]->setIcon(icon);
        cancel[i]->setIconSize(icon.size());
        cancel[i]->setAutoRaise(true);
    }
    layoutRefresh();
    //连接槽
    this->connect(this->next, SIGNAL(clicked()), this, SLOT(nextSpot()));
    this->connect(this->finish, SIGNAL(clicked()), this, SLOT(sendFinishNowSinal()));
    this->connect(this->photos[0], SIGNAL(clicked()), this, SLOT(photoSpot_0()));
    this->connect(this->photos[1], SIGNAL(clicked()), this, SLOT(photoSpot_1()));
    this->connect(this->photos[2], SIGNAL(clicked()), this, SLOT(photoSpot_2()));
    this->connect(this->photos[3], SIGNAL(clicked()), this, SLOT(photoSpot_3()));
    this->connect(this->photos[4], SIGNAL(clicked()), this, SLOT(photoSpot_4()));
    this->connect(this->photos[5], SIGNAL(clicked()), this, SLOT(photoSpot_5()));
    this->connect(this->photos[6], SIGNAL(clicked()), this, SLOT(photoSpot_6()));
    this->connect(this->diary[0], SIGNAL(clicked()), this, SLOT(diarySpot_0()));
    this->connect(this->diary[1], SIGNAL(clicked()), this, SLOT(diarySpot_1()));
    this->connect(this->diary[2], SIGNAL(clicked()), this, SLOT(diarySpot_2()));
    this->connect(this->diary[3], SIGNAL(clicked()), this, SLOT(diarySpot_3()));
    this->connect(this->diary[4], SIGNAL(clicked()), this, SLOT(diarySpot_4()));
    this->connect(this->diary[5], SIGNAL(clicked()), this, SLOT(diarySpot_5()));
    this->connect(this->diary[6], SIGNAL(clicked()), this, SLOT(diarySpot_6()));
    this->connect(this->cancel[0], SIGNAL(clicked()), this, SLOT(cancelSpot_0()));
    this->connect(this->cancel[1], SIGNAL(clicked()), this, SLOT(cancelSpot_1()));
    this->connect(this->cancel[2], SIGNAL(clicked()), this, SLOT(cancelSpot_2()));
    this->connect(this->cancel[3], SIGNAL(clicked()), this, SLOT(cancelSpot_3()));
    this->connect(this->cancel[4], SIGNAL(clicked()), this, SLOT(cancelSpot_4()));
    this->connect(this->cancel[5], SIGNAL(clicked()), this, SLOT(cancelSpot_5()));
    this->connect(this->cancel[6], SIGNAL(clicked()), this, SLOT(cancelSpot_6()));
}

void nowTripPage::cancelSpot_0(){cancelSpot(0);}
void nowTripPage::cancelSpot_1(){cancelSpot(1);}
void nowTripPage::cancelSpot_2(){cancelSpot(2);}
void nowTripPage::cancelSpot_3(){cancelSpot(3);}
void nowTripPage::cancelSpot_4(){cancelSpot(4);}
void nowTripPage::cancelSpot_5(){cancelSpot(5);}
void nowTripPage::cancelSpot_6(){cancelSpot(6);}
void nowTripPage::photoSpot_0(){openPhotoHolder(0);}
void nowTripPage::photoSpot_1(){openPhotoHolder(1);}
void nowTripPage::photoSpot_2(){openPhotoHolder(2);}
void nowTripPage::photoSpot_3(){openPhotoHolder(3);}
void nowTripPage::photoSpot_4(){openPhotoHolder(4);}
void nowTripPage::photoSpot_5(){openPhotoHolder(5);}
void nowTripPage::photoSpot_6(){openPhotoHolder(6);}
void nowTripPage::diarySpot_0(){openDiaryHolder(0);}
void nowTripPage::diarySpot_1(){openDiaryHolder(1);}
void nowTripPage::diarySpot_2(){openDiaryHolder(2);}
void nowTripPage::diarySpot_3(){openDiaryHolder(3);}
void nowTripPage::diarySpot_4(){openDiaryHolder(4);}
void nowTripPage::diarySpot_5(){openDiaryHolder(5);}
void nowTripPage::diarySpot_6(){openDiaryHolder(6);}

void nowTripPage::cancelSpot(int x)
{
    if (x < nowSpot) return;
    if (x == nowSpot) nextSpot();
    QPixmap icon;
    mark[x] = '3';
    icon.load(":/icon/img/icon/notL.png");
    arrived[x]->setPixmap(icon);
    storeMark();
}

void nowTripPage::layoutRefresh()
{
    //导入信息
    active = true;
    loadInf();
    if (!active) return;
    //清除原有布局
    map->setParent(NULL);
    leftLayout->removeWidget(map);
    next->setParent(NULL);
    rightLayout->removeWidget(next);
    finish->setParent(NULL);
    rightLayout->removeWidget(finish);
    tripNameLabel->setParent(NULL);
    rightLayout->removeWidget(tripNameLabel);
    for (int i=0; i<7; i++)
    {
        arrived[i]->setParent(NULL);
        viewSpot[i]->setParent(NULL);
        timeSpot[i]->setParent(NULL);
        photos[i]->setParent(NULL);
        diary[i]->setParent(NULL);
        cancel[i]->setParent(NULL);
        rightLayout->removeWidget(arrived[i]);
        rightLayout->removeWidget(viewSpot[i]);
        rightLayout->removeWidget(timeSpot[i]);
        rightLayout->removeWidget(photos[i]);
        rightLayout->removeWidget(diary[i]);
        rightLayout->removeWidget(cancel[i]);
    }
    delete(leftLayout);
    delete(rightLayout);
    delete(layout);
    QLabel *spacex = new QLabel;
    spacex->setMaximumHeight(22);
    spacex->setMaximumWidth(4);
    QLabel *spacey = new QLabel;
    //初始化左端布局
    leftLayout = new QGridLayout;
    leftLayout->addWidget(map, 0, 70, 3, 3);
    leftLayout->addWidget(spacey, 200, 0);
    //初始化右端布局
    rightLayout = new QGridLayout;
    rightLayout->addWidget(spacey, 200,0);
    rightLayout->addWidget(spacey, 0, 0, 1, 2);
    rightLayout->addWidget(spacey, 0, 3, 1, 4);
    rightLayout->addWidget(spacey, 0, 8, 1, 5);
    rightLayout->addWidget(spacey, 0, 14, 1, 2);
    rightLayout->addWidget(spacey, 0, 17, 1, 1);
    rightLayout->addWidget(spacey, 0, 19, 1, 3);
    rightLayout->addWidget(spacey, 0, 23, 1, 17);
    rightLayout->addWidget(spacey, 0, 0, 20, 1);
    rightLayout->addWidget(next, 0, 40);
    rightLayout->addWidget(finish, 20, 15);
    rightLayout->addWidget(tripNameLabel, 0, 7, 1, 20);
    for (int i=0; i<totalSpot; i++)
    {
        rightLayout->addWidget(arrived[i], (i+1)*2, 2);
        rightLayout->addWidget(viewSpot[i], (i+1)*2, 7);
        rightLayout->addWidget(timeSpot[i], (i+1)*2, 13);
        rightLayout->addWidget(photos[i], (i+1)*2, 16);
        rightLayout->addWidget(diary[i], (i+1)*2, 18);
        rightLayout->addWidget(cancel[i], (i+1)*2, 22);
        rightLayout->addWidget(spacex, (i+1)*2-1, 7);
    }
    //总的布局
    layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);
    layout->insertStretch(1, 20);
    this->setLayout(layout);
}

void nowTripPage::sendFinishNowSinal()
{
    emit finishNow();
}

void nowTripPage::nextSpot()
{
    if (nowSpot == totalSpot || nowSpot == -1) return;
    QPixmap icon;
    int lastSpot = nowSpot;
    icon.load(":/icon/img/icon/finishL.png");
    arrived[lastSpot]->setPixmap(icon);
    mark[lastSpot] = '2';
    nowSpot++;
    while (nowSpot < totalSpot)
    {
        if (mark[nowSpot] == '1')
        {
            icon.load(":/icon/img/icon/nowL.png");
            arrived[nowSpot]->setPixmap(icon);
            mark[nowSpot] = '0';
            break;
        }
        nowSpot++;
    }
    this->storeMark();
    if (nowSpot == totalSpot) emit finishNow();
}

void nowTripPage::storeMark()
{
    //把改变储存起来
    QFile *usersInf;
    QTextStream *put;
    QString line;
    usersInf = new QFile;
    usersInf->setFileName(infUrl);
    usersInf->open(QIODevice::ReadOnly);
    put = new QTextStream(usersInf);
    put->setCodec(QTextCodec::codecForName("UTF-8"));
    //修改标记信息
    line = put->readAll();
    for (int i=0; i<totalSpot; i++)
    {
        int j = line.length() - totalSpot -1 + i;
        line[j] = mark[i];
    }
    delete(put);
    usersInf->close();
    delete(usersInf);
    usersInf = new QFile;
    usersInf->setFileName(infUrl);
    usersInf->open(QIODevice::WriteOnly);
    put = new QTextStream(usersInf);
    put->setCodec(QTextCodec::codecForName("UTF-8"));
    (*put) << line;
    delete(put);
    usersInf->close();
    delete(usersInf);
}

void nowTripPage::openPhotoHolder(int x)
{
    QString a = "users/" + tripNameLabel->text() + "/" + *(viewSpots[x]) + "/照片/";
    photoEdit = new photoHolder( 0, a);
    photoEdit->show();
}

void nowTripPage::openDiaryHolder(int x)
{
    QString a = "users/" + tripNameLabel->text() + "/" + *(viewSpots[x]) + "/日志/";
    diaryEdit = new DiaryHolder( 0, a);
    diaryEdit->show();
}

void nowTripPage::findString(QString *line, QString *tmp, int *index)
{
    *tmp = "";
    while ((*line)[(*index)] != '&')
    {
        *tmp = *tmp + (*line)[(*index)];
        *index = *index + 1;
    }
    *index = *index + 1;
}

void nowTripPage::loadInf()
{
    QFile *usersInf = new QFile;
    usersInf->setFileName(*HEAD + "users.inf");
    usersInf->open(QIODevice::ReadOnly);
    QTextStream in(usersInf);
    int totI = in.readAll().toInt();
    QString totS;
    totS.setNum(totI - 1);
    usersInf->close();
    if (totI == 0)
    {
        totalSpot = 0;
        active = false;
        return;
    }
    infUrl = *HEAD + "users/" + totS + ".inf";
    usersInf->setFileName(infUrl);
    usersInf->open(QIODevice::ReadOnly);
    QTextStream *input = new QTextStream(usersInf);
    input->setCodec(QTextCodec::codecForName("UTF-8"));
    QString line = input->readAll();
    delete(input);
    usersInf->close();
    delete(usersInf);
    int i = 0;
    QString tmp = "";
    findString(&line, &tmp, &i);
    this->tripNameLabel->setText(tmp);
    findString(&line, &tmp, &i);
    this->totalSpot = tmp.toInt();
    QDate *date = new QDate;
    for (int j=0; j<totalSpot; j++)
    {
        findString(&line, &tmp, &i);
        this->viewSpot[j]->setText(tmp);
        *viewSpots[j] = tmp;
        findString(&line, &tmp, &i);
        int year = tmp.toInt();
        findString(&line, &tmp, &i);
        int month = tmp.toInt();
        findString(&line, &tmp, &i);
        int day = tmp.toInt();
        date->setDate(year, month, day);
        this->timeSpot[j]->setText(date->toString("yyyy-MM-dd"));
    }
    findString(&line, &tmp, &i);
    mark = tmp;
    nowSpot = mark.indexOf("0");
    QPixmap icon;
    for (int j=0; j<totalSpot; j++)
    {
        if (mark[j] == '0')
        {
            icon.load(":/icon/img/icon/nowL.png");
            arrived[j]->setPixmap(icon);
        } else if (mark[j] == '1')
        {
            icon.load(":/icon/img/icon/waitL.png");
            arrived[j]->setPixmap(icon);
        } else if (mark[j] == '2')
        {
            icon.load(":/icon/img/icon/finishL.png");
            arrived[j]->setPixmap(icon);
        } else
        {
            icon.load(":/icon/img/icon/notL.png");
            arrived[j]->setPixmap(icon);
        }
    }
    map->GetMap(totalSpot, viewSpots);
}

nowTripPage::~nowTripPage()
{
    delete ui;
}
