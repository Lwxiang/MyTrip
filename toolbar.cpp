#include "toolbar.h"
#include "ui_toolbar.h"

ToolBar::ToolBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToolBar)
{
    ui->setupUi(this);
    this->setWindowOpacity(0.1);
    this->setMaximumSize(1279,70);
    this->setMinimumSize(1279,70);

    newTrip = new QToolButton;
    nowTrip = new QToolButton;
    pastTrip = new QToolButton;
    QPixmap icon;
    icon.load(":./icon/img/icon/newT.png");
    newTrip->setIcon(icon);
    newTrip->setIconSize(icon.size());
    newTrip->setAutoRaise(true);
    icon.load(":./icon/img/icon/nowT.png");
    nowTrip->setIcon(icon);
    nowTrip->setIconSize(icon.size());
    nowTrip->setAutoRaise(true);
    icon.load(":./icon/img/icon/pastT.png");
    pastTrip->setIcon(icon);
    pastTrip->setIconSize(icon.size());
    pastTrip->setAutoRaise(true);
    QHBoxLayout *toolLayout = new QHBoxLayout;
    toolLayout->addWidget(newTrip);
    toolLayout->addWidget(nowTrip);
    toolLayout->addWidget(pastTrip);
    this->setLayout(toolLayout);
}

ToolBar::~ToolBar()
{
    delete ui;
}
