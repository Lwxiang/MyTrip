#include "photocontrol.h"
#include "ui_photocontrol.h"

PhotoControl::PhotoControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PhotoControl)
{
    ui->setupUi(this);

    this->setMaximumSize(800, 70);
    this->setMinimumSize(800, 70);
    QPixmap icon;
    selectPhoto = new QToolButton;
    icon.load(":/icon/img/icon/openpho.png");
    selectPhoto->setIcon(icon);
    selectPhoto->setIconSize(icon.size());
    selectPhoto->setAutoRaise(true);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(selectPhoto);
    this->setLayout(layout);
}

PhotoControl::~PhotoControl()
{
    delete ui;
}
