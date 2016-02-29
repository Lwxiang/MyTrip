#ifndef PHOTOCONTROL_H
#define PHOTOCONTROL_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QPixmap>

namespace Ui {
class PhotoControl;
}

class PhotoControl : public QWidget
{
    Q_OBJECT

public:
    explicit PhotoControl(QWidget *parent = 0);
    QToolButton *selectPhoto;
    ~PhotoControl();

private:
    Ui::PhotoControl *ui;
};

#endif // PHOTOCONTROL_H
