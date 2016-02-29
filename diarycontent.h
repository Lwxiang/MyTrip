#ifndef DIARYCONTENT_H
#define DIARYCONTENT_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QProcess>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QDebug>
#include <QFileInfoList>
#include <QFileInfo>
#include <QTextEdit>
#include <QLineEdit>
#include <QPalette>
#include <QBitmap>
#include <QPainter>

namespace Ui {
class DiaryContent;
}

class DiaryContent : public QWidget
{
    Q_OBJECT

public:
    explicit DiaryContent(QWidget *parent = 0, QString tail="");
    QVBoxLayout *layout;
    QString *HEAD;
    QString URL;
    QString urlTail;
    QTextEdit *text;
    QLabel *title;
    ~DiaryContent();

private:
    Ui::DiaryContent *ui;

private slots:
    void saveFile();
};

#endif // DIARYCONTENT_H
