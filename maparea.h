#ifndef MAPAREA_H
#define MAPAREA_H

#include <QWidget>
#include <QString>
#include <QUrl>
#include <QWebView>
#include <QFile>
#include <QIODevice>
#include <QFileDialog>
#include <QTextStream>
#include <QVBoxLayout>
#include <QDebug>
#include <QTextCodec>

namespace Ui {
class mapArea;
}

class mapArea : public QWidget
{
    Q_OBJECT

public:
    explicit mapArea(QWidget *parent = 0);
    QWebView *webView;
    ~mapArea();

public slots:
    void GetMap(int, QString *[10]);

private:
    Ui::mapArea *ui;
};

#endif // MAPAREA_H
