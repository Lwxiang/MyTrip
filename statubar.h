#ifndef STATUBAR_H
#define STATUBAR_H

#include <QWidget>
#include <QPalette>

namespace Ui {
class StatuBar;
}

class StatuBar : public QWidget
{
    Q_OBJECT

public:
    explicit StatuBar(QWidget *parent = 0);
    ~StatuBar();

private:
    Ui::StatuBar *ui;
};

#endif // STATUBAR_H
