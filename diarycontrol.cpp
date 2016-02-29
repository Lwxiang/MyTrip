#include "diarycontrol.h"
#include "ui_diarycontrol.h"

DiaryControl::DiaryControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiaryControl)
{
    ui->setupUi(this);

    this->setMaximumSize(800, 70);
    this->setMinimumSize(800, 70);
    QPixmap icon;
    save = new QToolButton;
    icon.load(":/icon/img/icon/openpho.png");
    save->setIcon(icon);
    save->setIconSize(icon.size());
    save->setAutoRaise(true);
    layout = new QHBoxLayout;
    layout->addWidget(save);
    this->setLayout(layout);
}

DiaryControl::~DiaryControl()
{
    delete ui;
}
