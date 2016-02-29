#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QPalette>
#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QHBoxLayout>
#include <QString>
#include <QPixmap>

namespace Ui {
class TitleBar;
}

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    QToolButton *minimize;
    QToolButton *close;
    QLabel *title;
    void setTitleName(QString);
    void setWidth(int);
    ~TitleBar();

private:
    Ui::TitleBar *ui;
};

#endif // TITLEBAR_H
