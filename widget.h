#ifndef WIDGET_H
#define WIDGET_H

#include "titlebar.h"
#include "toolbar.h"
#include "statubar.h"
#include "contentwidget.h"

#include <QWidget>
#include <QRect>
#include <QBitmap>
#include <QPainter>
#include <QFrame>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class Widget;
}

class Widget : public QFrame
{
    Q_OBJECT

public:
    explicit Widget(QFrame *parent = 0);
    TitleBar *titlebar;
    ToolBar *toolbar;
    ContentWidget *contentwidget;
    StatuBar *statubar;
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint oldPos;
    bool mouseDown;
    Ui::Widget *ui;
};

#endif // WIDGET_H
