#ifndef CONTENTWIDGET_H
#define CONTENTWIDGET_H

#include "newtrippage.h"
#include "nowtrippage.h"
#include "pasttrippage.h"
#include <QWidget>
#include <QPalette>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QIODevice>
#include <QMessageBox>
#include <QDate>

namespace Ui {
class ContentWidget;
}

class ContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ContentWidget(QWidget *parent = 0);
    newTripPage *newtp;
    nowTripPage *nowtp;
    pastTripPage *pasttp;
    QStackedWidget *stackedWidget;
    QVBoxLayout *layout;
    QString *HEAD;
    bool fromNew;
    ~ContentWidget();

public slots:
    void switchToNew();
    void switchToNow();
    void switchToPast();

private:
    Ui::ContentWidget *ui;

private slots:
    void finishNew();
    void finishNow();
};

#endif // CONTENTWIDGET_H
