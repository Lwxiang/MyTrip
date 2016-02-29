#include "diarycontent.h"
#include "ui_diarycontent.h"

DiaryContent::DiaryContent(QWidget *parent, QString tail) :
    QWidget(parent),
    ui(new Ui::DiaryContent)
{
    ui->setupUi(this);
    HEAD = new QString;
    *HEAD = "../project1/";
    urlTail = tail;
    URL = *HEAD + urlTail + "diary.txt";
    this->setWindowOpacity(0.1);
    this->setMaximumSize(800, 500);
    this->setMinimumSize(800, 500);
    title = new QLabel;
    title->setMaximumHeight(30);
    title->setMinimumHeight(30);
    title->setText(tail.replace("/", "~").replace("users", ""));
    text = new QTextEdit;
    QPalette pl = text->palette();
    pl.setBrush(QPalette::Base,QBrush(QColor(255,0,0,0)));
    text->setPalette(pl);
    layout = new QVBoxLayout;
    layout->addWidget(title);
    layout->addWidget(text);
    setLayout(layout);
    bool ok = QFileInfo::exists(URL);
    if (ok) {
        QFile *file = new QFile;
        file->setFileName(URL);
        file->open(QIODevice::ReadOnly);
        QTextStream in(file);
        text->setText(in.readAll());
        file->close();
    }
}

void DiaryContent::saveFile()
{
    QFile *file = new QFile;
    bool ok = QFileInfo::exists(URL);
    if (!ok)
    {
        file->setFileName(URL);
        file->open(QIODevice::WriteOnly);
        file->close();
    }
    file->setFileName(URL);
    file->open(QIODevice::WriteOnly);
    QTextStream out(file);
    out << text->toPlainText();
    file->close();
}

DiaryContent::~DiaryContent()
{
    delete ui;
}
