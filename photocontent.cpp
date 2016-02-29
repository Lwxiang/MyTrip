#include "photocontent.h"
#include "ui_photocontent.h"

photoContent::photoContent(QWidget *parent, QString tail) :
    QWidget(parent),
    ui(new Ui::photoContent)
{
    ui->setupUi(this);
    HEAD = new QString;
    *HEAD = "../project1/";
    urlTail = tail;
    this->setWindowOpacity(0.1);
    this->setMaximumSize(800, 500);
    this->setMinimumSize(800, 500);
    layout = new QGridLayout;
    for (int i=0; i<9; i++) maps[i] = new QLabel;
    for (int i=0; i<9; i++)
    {
        maps[i] = new QLabel;
        maps[i]->setMaximumSize(250, 400);
        layout->addWidget(maps[i], i/3, i%3);
    }
    setLayout(layout);
    this->layoutRefresh();

}

void photoContent::layoutRefresh()
{
    QDir *dir = new QDir(*HEAD + urlTail);
    dir->setSorting(QDir::Time);
    dir->setFilter(QDir::Files);
    QFileInfoList list = dir->entryInfoList();
    QString url;
    int j = 0;
    qDebug() << list.size();
    for (int i=0; i<list.size(); i++)
    {
        QFileInfo fileinfo = list.at(i);
        qDebug() << fileinfo.fileName();
        if (fileinfo.fileName() == "pht.inf") continue;
        url = *HEAD + urlTail + fileinfo.fileName();
        QImage img;
        img.load(url);
        img = img.scaled(250, 400, Qt::KeepAspectRatio);
        maps[j]->setPixmap(QPixmap::fromImage(img));
        qDebug()<< j;
        j++;
    }
    for (int i=list.size(); i<9; i++) maps[i]->clear();
}

QString photoContent::findName(QString url)
{
    int x = 0;
    for (int i=0; i<url.length(); i++)
    {
        if (url[i] == '/') x = i;
    }
    QString y = "";
    for (int i=x+1; i<url.length(); i++)  y += url[i];
    return y;
}

void photoContent::addPhoto(QString photoUrl)
{
    QFile *file = new QFile;
    file->setFileName(*HEAD + urlTail + "pht.inf");
    file->open(QIODevice::ReadOnly);
    QTextStream in(file);
    QString totS = in.readAll();
    int tot = totS.toInt();
    file->close();
    if (tot == 9) return;
    file->open(QIODevice::WriteOnly);
    QTextStream out(file);
    out << (tot + 1);
    file->close();
    QImage img;
    img.load(photoUrl);
    QString storeUrl = *HEAD + urlTail + findName(photoUrl);
    img.save(storeUrl);
    layoutRefresh();
}

void photoContent::choosePhoto()
{
    QString limit = "jpg(*.jpg);;jpeg(*jpeg)";
    QStringList fileName = QFileDialog::getOpenFileNames(this, "选择照片", QDir::currentPath(), limit);
    for (int i=0; i<fileName.length(); i++) addPhoto(fileName[i]);
}

photoContent::~photoContent()
{
    delete ui;
}
