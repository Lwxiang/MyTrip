#include "titlebar.h"
#include "ui_titlebar.h"

TitleBar::TitleBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleBar)
{
    ui->setupUi(this);
    setAutoFillBackground(false);
    this->setWindowOpacity(0.1);
    //setBackgroundRole(QPalette::Highlight);
    QPixmap icon;
    minimize = new QToolButton;
    icon.load(":/icon/img/icon/minsize.png");
    minimize->setIcon(icon);
    minimize->setIconSize(icon.size());
    minimize->setAutoRaise(true);
    close = new QToolButton;
    icon.load(":/icon/img/icon/close.png");
    close->setIcon(icon);
    close->setIconSize(icon.size());
    close->setAutoRaise(true);
    title = new QLabel;
    minimize->setMinimumHeight(20);
    close->setMinimumHeight(20);
    QHBoxLayout *titleLayout = new QHBoxLayout;
    titleLayout->addWidget(title);
    titleLayout->addWidget(minimize);
    titleLayout->addWidget(close);
    this->setLayout(titleLayout);
    titleLayout->insertStretch(1, 500);
    titleLayout->setSpacing(0);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
}

void TitleBar::setTitleName(QString titleName)
{
    this->title->setText(titleName);
}

void TitleBar::setWidth(int width)
{
    this->setMaximumSize(width, 30);
    this->setMinimumSize(width, 30);
}

TitleBar::~TitleBar()
{
    delete ui;
}
