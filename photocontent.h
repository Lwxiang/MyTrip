#ifndef PHOTOCONTENT_H
#define PHOTOCONTENT_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QProcess>
#include <QGridLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFileInfoList>
#include <QFileInfo>

namespace Ui {
class photoContent;
}

class photoContent : public QWidget
{
    Q_OBJECT

public:
    explicit photoContent(QWidget *parent = 0, QString tail="");
    QGridLayout *layout;
    QLabel *maps[20];
    int totalMap;
    QString *HEAD;
    int totalPhoto;
    QString *photoUrl[20];
    void addPhoto(QString);
    QString findName(QString);
    QString urlTail;
    ~photoContent();

private:
    Ui::photoContent *ui;

private slots:
    void layoutRefresh();
    void choosePhoto();
};

#endif // PHOTOCONTENT_H
