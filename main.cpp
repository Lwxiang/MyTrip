#include "widget.h"
#include <QApplication>
#include <QTextCodec>
#include <QSplashScreen>
#include <QPixmap>
#include <time.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/image/img/bg/screen.png");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents();
    double time1 = (double)clock();
    while (true)
    {
        double time2 = (double)clock();
        if (time2 - time1 > 3000) break;
    }
    Widget w;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    w.show();
    splash.finish(&w);
    return a.exec();
}
