#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QPalette>
#include <QToolButton>
#include <QHBoxLayout>
#include <QImage>
#include <QPixmap>

namespace Ui {
class ToolBar;
}

class ToolBar : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBar(QWidget *parent = 0);
    QToolButton *newTrip;
    QToolButton *nowTrip;
    QToolButton *pastTrip;
    ~ToolBar();

private:
    Ui::ToolBar *ui;
};

#endif // TOOLBAR_H
