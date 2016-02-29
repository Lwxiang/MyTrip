#include "statubar.h"
#include "ui_statubar.h"

StatuBar::StatuBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatuBar)
{
    ui->setupUi(this);
    this->setWindowOpacity(0.1);
    this->setMaximumSize(1279,26);
    this->setMinimumSize(1279,26);
}

StatuBar::~StatuBar()
{
    delete ui;
}
