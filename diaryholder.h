#ifndef DIARYHOLDER_H
#define DIARYHOLDER_H

#include "titlebar.h"
#include "diarycontent.h"
#include "diarycontrol.h"

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
class DiaryHolder;
}

class DiaryHolder : public QFrame
{
    Q_OBJECT

public:
    explicit DiaryHolder(QFrame *parent = 0, QString tail="");
    TitleBar *titlebar;
    DiaryContent *content;
    DiaryControl *control;
    ~DiaryHolder();

protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

private:
    QPoint oldPos;
    bool mouseDown;
    Ui::DiaryHolder *ui;
};

#endif // DIARYHOLDER_H
