#ifndef PHOTOHOLDER_H
#define PHOTOHOLDER_H

#include "titlebar.h"
#include "photocontent.h"
#include "photocontrol.h"

#include <QWidget>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QFrame>
#include <QBitmap>
#include <QMouseEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFile>
#include <QPainter>

namespace Ui {
class photoHolder;
}

class photoHolder : public QFrame
{
    Q_OBJECT

public:
    explicit photoHolder(QFrame *parent = 0, QString tail="");
    TitleBar *titlebar;
    photoContent *content;
    PhotoControl *control;
    ~photoHolder();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint oldPos;
    bool mouseDown;
    Ui::photoHolder *ui;
};

#endif // PHOTOHOLDER_H
