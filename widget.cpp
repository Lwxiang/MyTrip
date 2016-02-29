#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QFrame *parent) :
    QFrame(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(QRect(80,20,1279,706));
    this->setMaximumSize(1279,706);
    this->setMinimumSize(1279,706);
    setStyleSheet("Widget {background-image:url(:/image/img/bg/KG.jpg);}");
    //生成一张位图
    QBitmap objBitmap(size());
    //QPainter用于在位图上绘画
    QPainter painter(&objBitmap);
    //填充位图矩形框(用白色填充)
    painter.fillRect(rect(),Qt::white);
    painter.setBrush(QColor(0,0,0));
    //在位图上画圆角矩形(用黑色填充)
    painter.drawRoundedRect(this->rect(),10,10);
    //使用setmask过滤即可
    setMask(objBitmap);

    titlebar = new TitleBar(this);
    titlebar->setTitleName("旅游行程记录系统");
    titlebar->setWidth(1279);
    toolbar = new ToolBar(this);
    contentwidget = new ContentWidget(this);
    statubar = new StatuBar(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titlebar);
    mainLayout->addWidget(toolbar);
    mainLayout->addWidget(contentwidget);
    mainLayout->addWidget(statubar);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(mainLayout);

    this->connect(titlebar->minimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
    this->connect(titlebar->close, SIGNAL(clicked()), this, SLOT(close()));
    this->connect(toolbar->newTrip, SIGNAL(clicked()), contentwidget, SLOT(switchToNew()));
    this->connect(toolbar->nowTrip, SIGNAL(clicked()), contentwidget, SLOT(switchToNow()));
    this->connect(toolbar->pastTrip, SIGNAL(clicked()), contentwidget, SLOT(switchToPast()));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    mouseDown = (event->button() == Qt::LeftButton && event->pos().y()<=30);
    oldPos = event->globalPos();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (mouseDown)
    {
        int dx = event->globalX() - oldPos.x();
        int dy = event->globalY() - oldPos.y();
        oldPos = event->globalPos();
        move(x()+dx, y()+dy);
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        mouseDown = false;
}

Widget::~Widget()
{
    delete ui;
}
