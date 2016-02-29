#include "contentwidget.h"
#include "ui_contentwidget.h"
#include <direct.h>

ContentWidget::ContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContentWidget)
{
    ui->setupUi(this);
    HEAD = new QString;
    *HEAD = "../project1/";
    //setAutoFillBackground(true);
    fromNew = false;
    this->setWindowOpacity(0.1);
    this->setMaximumSize(1279,576);
    this->setMinimumSize(1279,576);
    newtp = new newTripPage;
    nowtp = new nowTripPage;
    pasttp = new pastTripPage;
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(newtp);
    stackedWidget->addWidget(nowtp);
    stackedWidget->addWidget(pasttp);
    layout = new QVBoxLayout;
    layout->addWidget(stackedWidget);
    setLayout(layout);

    this->connect(newtp->finish, SIGNAL(clicked()), this, SLOT(finishNew()));
    this->connect(nowtp, SIGNAL(finishNow()), this, SLOT(finishNow()));
}

void ContentWidget::finishNew()
{
    if ((QMessageBox::question(this, "新的旅程", "要开始新的旅程吗？", QMessageBox::Yes | QMessageBox::Cancel)) != QMessageBox::Yes)
        return;
    fromNew = true;
    finishNow();
    //储存信息
    //获取已有的行程总数tot
    QFile *usersInf = new QFile;
    usersInf->setFileName(*HEAD + "users.inf");
    usersInf->open(QIODevice::ReadOnly);
    QTextStream in(usersInf);
    QString totS = in.readAll();
    int tot = totS.toInt();
    usersInf->close();
    usersInf->open(QIODevice::WriteOnly);
    tot++;
    QTextStream out(usersInf);
    out << tot;
    usersInf->close();
    //创建新的行程
    if (*(newtp->tripName) == "") *(newtp->tripName) = "未命名" + totS;
    //创建相应的文件夹
    QDir *dir = new QDir;
    dir->mkdir(*HEAD + "users/" + *(newtp->tripName));
    for (int i=0; i<newtp->totalSpot; i++)
    {
        dir->mkdir(*HEAD + "users/" + *(newtp->tripName) + "/" + *(newtp->viewSpots[i]));
        dir->mkdir(*HEAD + "users/" + *(newtp->tripName) + "/" + *(newtp->viewSpots[i]) + "/照片");
        QFile *file = new QFile;
        file->setFileName(*HEAD + "users/" + *(newtp->tripName) + "/" + *(newtp->viewSpots[i]) + "/照片/pht.inf");
        file->open(QIODevice::WriteOnly);
        file->close();
        file->open(QIODevice::WriteOnly);
        QTextStream inPht(file);
        inPht << 0;
        file->close();
        dir->mkdir(*HEAD + "users/" + *(newtp->tripName) + "/" + *(newtp->viewSpots[i]) + "/日志");
    }
    QFile *addTrip;
    addTrip = new QFile;
    addTrip->setFileName(*HEAD + "users/" + totS + ".inf");
    addTrip->open(QIODevice::WriteOnly);
    addTrip->close();
    delete(addTrip);
    addTrip = new QFile;
    addTrip->setFileName(*HEAD + "users/" + totS + ".inf");
    addTrip->open(QIODevice::WriteOnly);
    QTextStream *output = new QTextStream(addTrip);
    //output.setCodec(QTextCodec::codecForName("UTF-8"));
    QString line;
    QString *tmp = new QString;
    tmp->setNum(newtp->totalSpot);
    line = *(newtp->tripName) + "&" + *tmp;
    for (int i=0; i<newtp->totalSpot; i++)
    {
        line += "&" + *(newtp->viewSpots[i]);
        tmp->setNum(newtp->timeSpots[i]->year());
        line += "&" + *tmp;
        tmp->setNum(newtp->timeSpots[i]->month());
        line += "&" + *tmp;
        tmp->setNum(newtp->timeSpots[i]->day());
        line += "&" + *tmp;
    }
    line += "&";
    //初始化标记
    line += "0";
    for (int i=1; i<newtp->totalSpot; i++)
    {
        line += "1";
    }
    line += "&";
    (*output) << line;
    addTrip->close();
    delete(output);
    delete(addTrip);
    stackedWidget->setParent(NULL);
    layout->removeWidget(stackedWidget);
    newtp->setParent(NULL);
    stackedWidget->removeWidget(newtp);
    nowtp->setParent(NULL);
    stackedWidget->removeWidget(nowtp);
    pasttp->setParent(NULL);
    stackedWidget->removeWidget(pasttp);
    stackedWidget->addWidget(newtp);
    stackedWidget->addWidget(nowtp);
    stackedWidget->addWidget(pasttp);
    layout->addWidget(stackedWidget);
    setLayout(layout);
    //更新nowTripPage里的内容
    nowtp->layoutRefresh();
    this->switchToNow();
}

void ContentWidget::finishNow()
{
    if (!fromNew)
        if ((QMessageBox::question(this, "结束旅程", "要结束这段旅程吗？", QMessageBox::Yes | QMessageBox::Cancel)) != QMessageBox::Yes)
            return;
    if (nowtp->nowSpot < nowtp->totalSpot || nowtp->nowSpot != -1)
    {
        nowtp->mark[nowtp->nowSpot] = '2';
        QPixmap icon;
        icon.load(":/icon/img/icon/finishL.png");
        nowtp->arrived[nowtp->nowSpot]->setPixmap(icon);
        nowtp->storeMark();
        for (int i=nowtp->nowSpot+1; i<nowtp->totalSpot; i++) nowtp->cancelSpot(i);
    }
    pasttp->layoutRefresh();
    switchToPast();
}


void ContentWidget::switchToNew()
{
    stackedWidget->setCurrentIndex(0);
}

void ContentWidget::switchToNow()
{
    stackedWidget->setCurrentIndex(1);
}

void ContentWidget::switchToPast()
{
    stackedWidget->setCurrentIndex(2);
}

ContentWidget::~ContentWidget()
{
    delete ui;
}
