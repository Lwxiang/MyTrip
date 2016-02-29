#include "photoholder.h"
#include "ui_photoholder.h"

photoHolder::photoHolder(QFrame *parent, QString tail) :
    QFrame(parent),
    ui(new Ui::photoHolder)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(QRect(80, 20, 800, 600));
    this->setMaximumSize(800, 600);
    this->setMinimumSize(800, 600);
    setStyleSheet("photoHolder {background-image:url(:./image/img/bg/phoBG.jpg);}");
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
    titlebar->setTitleName("相册");
    titlebar->setWidth(800);
    content = new photoContent(this, tail);
    control = new PhotoControl(this);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(titlebar);
    mainLayout->addWidget(content);
    mainLayout->addWidget(control);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0,0,0,0);
    this->setLayout(mainLayout);

    this->connect(titlebar->close, SIGNAL(clicked()), this, SLOT(close()));
    this->connect(control->selectPhoto, SIGNAL(clicked()), content, SLOT(choosePhoto()));
}

void photoHolder::mousePressEvent(QMouseEvent *event)
{
    mouseDown = (event->button() == Qt::LeftButton && event->pos().y()<=30);
    oldPos = event->globalPos();
}

void photoHolder::mouseMoveEvent(QMouseEvent *event)
{
    if (mouseDown)
    {
        int dx = event->globalX() - oldPos.x();
        int dy = event->globalY() - oldPos.y();
        oldPos = event->globalPos();
        move(x()+dx, y()+dy);
    }
}

void photoHolder::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        mouseDown = false;
}

photoHolder::~photoHolder()
{
    delete ui;
}
