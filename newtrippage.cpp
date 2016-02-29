#include "newtrippage.h"
#include "ui_newtrippage.h"

newTripPage::newTripPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newTripPage)
{
    ui->setupUi(this);
    //newTrip窗口在contentWidget中，大小不能超过1279,576
    this->setMaximumSize(1260,576);
    this->setMinimumSize(1260,576);
    QPixmap icon;
    //初始化左端表格布局中所有部件
    for (int i=0; i<15; i++)
    {
        viewSpotEdit[i] = new QLineEdit;
        viewSpotEdit[i]->setTextMargins( 5, 5, 5, 5);
        viewSpotEdit[i]->setPlaceholderText("景点");
        timeSpotEdit[i] = new QDateEdit;
        addButton[i] = new QToolButton;
        icon.load(":/icon/img/icon/add.png");
        addButton[i]->setIcon(icon);
        addButton[i]->setIconSize(icon.size());
        addButton[i]->setAutoRaise(true);
        cancelButton[i] = new QToolButton;
        icon.load(":/icon/img/icon/del.png");
        cancelButton[i]->setIcon(icon);
        cancelButton[i]->setIconSize(icon.size());
        cancelButton[i]->setAutoRaise(true);
        viewSpots[i] = new QString;
        timeSpots[i] = new QDate;
    }
    timeSpotEdit[0]->setDate(QDate::currentDate());
    *timeSpots[0] =  QDate::currentDate();
    tripNameLabel = new QLabel;
    tripNameLabel->setText("        ");
    tripNameEdit = new QLineEdit;
    tripNameEdit->setTextMargins( 5, 5, 5, 5);
    tripNameEdit->setPlaceholderText("旅行计划的名字");
    tripName = new QString;
    finish = new QToolButton;
    icon.load(":/icon/img/icon/setout.png");
    finish->setIcon(icon);
    finish->setIconSize(QSize(130, 40));
    finish->setAutoRaise(true);
    add = new QToolButton;
    icon.load(":/icon/img/icon/ins.png");
    add->setIcon(icon);
    add->setIconSize(icon.size());
    add->setAutoRaise(true);
    addtop = new QToolButton;
    icon.load(":/icon/img/icon/add.png");
    addtop->setIcon(icon);
    addtop->setIconSize(icon.size());
    addtop->setAutoRaise(true);
    totalSpot = 1;
    wantAdd = false;
    leftLayout = new QGridLayout;
    rightLayout = new QGridLayout;
    layout = new QHBoxLayout;
    map = new mapArea;
    //刷新布局
    this->layoutRefresh();
    //链接槽
    this->connect(this->addtop, SIGNAL(clicked()), this, SLOT(makeAddSignal_top()));
    this->connect(this->add, SIGNAL(clicked()), this, SLOT(makeAddChoice()));
    this->connect(this->tripNameEdit, SIGNAL(textChanged(const QString)), this, SLOT(storeTripName()));
    this->connect(this->addButton[0], SIGNAL(clicked()), this, SLOT(makeAddSignal_0()));
    this->connect(this->addButton[1], SIGNAL(clicked()), this, SLOT(makeAddSignal_1()));
    this->connect(this->addButton[2], SIGNAL(clicked()), this, SLOT(makeAddSignal_2()));
    this->connect(this->addButton[3], SIGNAL(clicked()), this, SLOT(makeAddSignal_3()));
    this->connect(this->addButton[4], SIGNAL(clicked()), this, SLOT(makeAddSignal_4()));
    this->connect(this->addButton[5], SIGNAL(clicked()), this, SLOT(makeAddSignal_5()));
    this->connect(this->addButton[6], SIGNAL(clicked()), this, SLOT(makeAddSignal_6()));
    this->connect(this->cancelButton[0], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_0()));
    this->connect(this->cancelButton[1], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_1()));
    this->connect(this->cancelButton[2], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_2()));
    this->connect(this->cancelButton[3], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_3()));
    this->connect(this->cancelButton[4], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_4()));
    this->connect(this->cancelButton[5], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_5()));
    this->connect(this->cancelButton[6], SIGNAL(clicked()), this, SLOT(makeDeleteSignal_6()));
    this->connect(this->viewSpotEdit[0], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_0()));
    this->connect(this->viewSpotEdit[1], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_1()));
    this->connect(this->viewSpotEdit[2], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_2()));
    this->connect(this->viewSpotEdit[3], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_3()));
    this->connect(this->viewSpotEdit[4], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_4()));
    this->connect(this->viewSpotEdit[5], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_5()));
    this->connect(this->viewSpotEdit[6], SIGNAL(textChanged(const QString)), this, SLOT(makeStoreSpotSignal_6()));
    this->connect(this->timeSpotEdit[0], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_0()));
    this->connect(this->timeSpotEdit[1], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_1()));
    this->connect(this->timeSpotEdit[2], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_2()));
    this->connect(this->timeSpotEdit[3], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_3()));
    this->connect(this->timeSpotEdit[4], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_4()));
    this->connect(this->timeSpotEdit[5], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_5()));
    this->connect(this->timeSpotEdit[6], SIGNAL(dateChanged(const QDate)), this, SLOT(makeStoreSpotSignal_6()));
}

//伪造自定义信号
void newTripPage::makeAddChoice()
{
    if (wantAdd)
    {
        wantAdd = false;
    } else {
        wantAdd = true;
    }
    this->layoutRefresh();
}
void newTripPage::makeAddSignal_top(){addSpot(totalSpot);}
void newTripPage::makeAddSignal_0(){addSpot(0);}
void newTripPage::makeAddSignal_1(){addSpot(1);}
void newTripPage::makeAddSignal_2(){addSpot(2);}
void newTripPage::makeAddSignal_3(){addSpot(3);}
void newTripPage::makeAddSignal_4(){addSpot(4);}
void newTripPage::makeAddSignal_5(){addSpot(5);}
void newTripPage::makeAddSignal_6(){addSpot(6);}
void newTripPage::makeDeleteSignal_0(){deleteSpot(0);}
void newTripPage::makeDeleteSignal_1(){deleteSpot(1);}
void newTripPage::makeDeleteSignal_2(){deleteSpot(2);}
void newTripPage::makeDeleteSignal_3(){deleteSpot(3);}
void newTripPage::makeDeleteSignal_4(){deleteSpot(4);}
void newTripPage::makeDeleteSignal_5(){deleteSpot(5);}
void newTripPage::makeDeleteSignal_6(){deleteSpot(6);}
void newTripPage::makeStoreSpotSignal_0(){storeSpot(0);}
void newTripPage::makeStoreSpotSignal_1(){storeSpot(1);}
void newTripPage::makeStoreSpotSignal_2(){storeSpot(2);}
void newTripPage::makeStoreSpotSignal_3(){storeSpot(3);}
void newTripPage::makeStoreSpotSignal_4(){storeSpot(4);}
void newTripPage::makeStoreSpotSignal_5(){storeSpot(5);}
void newTripPage::makeStoreSpotSignal_6(){storeSpot(6);}

//添加景点
void newTripPage::addSpot(int x)
{
    if (totalSpot >=  7) return;
    for (int i=totalSpot; i>x; i--)
    {
        *viewSpots[i] = *viewSpots[i-1];
        *timeSpots[i] = *timeSpots[i-1];
    }
    *viewSpots[x] = "";
    if (x == 0)
    {
        *timeSpots[x] =QDate::currentDate();
    } else {
        *timeSpots[x] = *timeSpots[x-1];
    }
    totalSpot++;
    wantAdd = false;
    //刷新布局
    this->layoutRefresh();
}

//删除景点
void newTripPage::deleteSpot(int x)
{
    if (totalSpot == 1)
    {
        *viewSpots[x] = "";
        *timeSpots[x] = QDate::currentDate();
    } else {
        for (int i=x; i<totalSpot-1; i++)
        {
            *viewSpots[i] = *viewSpots[i+1];
            *timeSpots[i] = *timeSpots[i+1];
        }
        totalSpot--;
    }
    //刷新地图
    map->GetMap(totalSpot, viewSpots);
    //刷新布局
    this->layoutRefresh();
}

//储存景点
void newTripPage::storeSpot(int x)
{
    *viewSpots[x] = viewSpotEdit[x]->text();
    *timeSpots[x] = timeSpotEdit[x]->date();
    //刷新地图
    map->GetMap(totalSpot, viewSpots);
}

void newTripPage::storeTripName()
{
    *tripName = tripNameEdit->text();
}

//刷新布局
void newTripPage::layoutRefresh()
{
    //清除原有布局
    finish->setParent(NULL);
    rightLayout->removeWidget(finish);
    map->setParent(NULL);
    rightLayout->removeWidget(map);
    add->setParent(NULL);
    leftLayout->removeWidget(add);
    addtop->setParent(NULL);
    leftLayout->removeWidget(addtop);
    for (int i=0; i<7; i++)
    {
        viewSpotEdit[i]->setParent(NULL);
        timeSpotEdit[i]->setParent(NULL);
        addButton[i]->setParent(NULL);
        cancelButton[i]->setParent(NULL);
        leftLayout->removeWidget(viewSpotEdit[i]);
        leftLayout->removeWidget(timeSpotEdit[i]);
        leftLayout->removeWidget(addButton[i]);
        leftLayout->removeWidget(cancelButton[i]);
    }
    tripNameLabel->setParent(NULL);
    leftLayout->removeWidget(tripNameLabel);
    tripNameEdit->setParent(NULL);
    leftLayout->removeWidget(tripNameEdit);
    addButton[7]->setParent(NULL);
    leftLayout->removeWidget(addButton[7]);
    //释放之前的布局
    delete(leftLayout);
    //新建左端的表格布局
    leftLayout = new QGridLayout;
    //填充表格布局中的关键点来支撑起格式
    QLabel *spacex = new QLabel;
    spacex->setMaximumHeight(30);
    spacex->setMinimumHeight(30);
    spacex->setMaximumWidth(4);
    QLabel *spacey = new QLabel;
    leftLayout->addWidget(spacey, 200,0);
    leftLayout->addWidget(spacey, 0, 0, 1, 7);
    leftLayout->addWidget(spacey, 0, 8, 1, 5);
    leftLayout->addWidget(spacey, 0, 14, 1, 2);
    leftLayout->addWidget(spacey, 0, 17, 1, 23);
    leftLayout->addWidget(add, 0, 40);
    leftLayout->addWidget(addtop, 0, 41);
    //把已经填入的信息导入编辑框
    leftLayout->addWidget(tripNameLabel, 0, 0, 1, 7);
    tripNameEdit->setText(*tripName);
    leftLayout->addWidget(tripNameEdit, 0, 7, 1, 10);
    for (int i=0; i<totalSpot; i++)
    {
        viewSpotEdit[i]->setText(*viewSpots[i]);
        timeSpotEdit[i]->setDate(*timeSpots[i]);
        leftLayout->addWidget(viewSpotEdit[i], i*2+2, 7);
        leftLayout->addWidget(timeSpotEdit[i], i*2+2, 13);
        if (wantAdd)
            leftLayout->addWidget(addButton[i], i*2+1, 7);
        else
            leftLayout->addWidget(spacex, i*2+1, 7);
        leftLayout->addWidget(cancelButton[i], i*2+2, 16);
    }
    if (wantAdd && totalSpot<7) leftLayout->addWidget(addButton[totalSpot], 16, 7);
    //确定右边地图的布局
    delete(rightLayout);
    rightLayout = new QGridLayout;
    rightLayout->addWidget(map, 0, 70, 3, 3);
    rightLayout->addWidget(finish, 10, 70);
    rightLayout->addWidget(spacey, 200, 0);
    //整个newTripPage的布局
    delete(layout);
    layout = new QHBoxLayout;
    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);
    layout->insertStretch(1, 20);
    this->setLayout(layout);
}

newTripPage::~newTripPage()
{
    delete ui;
}
