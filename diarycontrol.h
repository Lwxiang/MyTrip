#ifndef DIARYCONTROL_H
#define DIARYCONTROL_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPixmap>

namespace Ui {
class DiaryControl;
}

class DiaryControl : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryControl(QWidget *parent = 0);
    QHBoxLayout *layout;
    QToolButton *save;
    ~DiaryControl();

private:
    Ui::DiaryControl *ui;
};

#endif // DIARYCONTROL_H
