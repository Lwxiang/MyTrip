#include "maparea.h"
#include "ui_maparea.h"

mapArea::mapArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mapArea)
{
    ui->setupUi(this);
    this->setMaximumSize(600, 500);
    this->setMinimumSize(600, 500);
    webView = new QWebView;
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(webView);
    this->setLayout(layout);
}

mapArea::~mapArea()
{
    delete ui;
}

void mapArea::GetMap(int total, QString *point[10])
{
    QFile *savef = new QFile;
    savef->setFileName("../project1/newdrive.html");
    bool saveok = savef->open(QIODevice::WriteOnly);
    if (saveok){
        QTextStream out(savef);
        out.setCodec(QTextCodec::codecForName("UTF-8"));
        QFile *openf = new QFile;
        openf->setFileName("../project1/partofdrive.html");
        bool openok = openf->open(QIODevice::ReadOnly);
        if (openok){
            QTextStream in(openf);
            QString line, count, le, ri;
            while (openf->atEnd() == false) {
                line = openf->readLine();
                out << line;
            }
            openf->close();
            delete(openf);
            line="\n";
            out<<line;
            //第一部分的头文件
            for (int i=0; i<total; i++){
                count.setNum(i+1);
                line = "var place" + count + "=\"" + *(point[i]) + "\";\n";
                out<<line;
            }
            //第二部分的头文件
            line="\nvar myGeo = new BMap.Geocoder();\n";
            out<<line;
            for (int i=0; i<total; i++){
                count.setNum(i+1);
                line = "myGeo.getPoint(place" + count + ",function(point){if(point){myplace" + count + "=new BMap.Point(point.lng,point.lat);	}},stcenter);\n";
                out<<line;
            }
            //第三部分找到地点
            line = "\nfunction run(){\nmap.clearOverlays();\nvar driving = new BMap.DrivingRoute(map);\n";
            out<<line;
            for (int i=1; i<total; i++){
                le.setNum(i);
                ri.setNum(i+1);
                line = "driving.search(myplace" + le + ",myplace" + ri + ");\n";
                out<<line;
            }
            //第四部分找到路线
            line="\ndriving.setSearchCompleteCallback(function(){\nvar pts = driving.getResults().getPlan(0).getRoute(0).getPath();\n";
            out<<line;
            line = "\nvar polyline = new BMap.Polyline(pts);\nmap.addOverlay(polyline);\nmap.addOverlay(polyline);\n";
            out<<line;
            for (int i=0; i<total; i++){
                count.setNum(i+1);
                line = "map.addOverlay(new BMap.Marker(myplace" + count + "));\n";
                out<<line;
            }
            for (int i=0; i<total; i++){
                count.setNum(i+1);
                line = "map.addOverlay(new BMap.Label(\"";
                if (i == 0){line = line + "起点-\"+place";}
                    else if (i == total-1){line = line + "终点-\"+place";}
                        else {line = line + "途经点-\"+place";}
                line = line + count + ",{position:myplace" + count + "}));\n";
                out<<line;
            }
            //第五部分添加OverLay
            line = "\nsetTimeout(function(){map.setViewport([";
            for (int i=0; i<total; i++){
                count.setNum(i+1);
                line = line + "myplace" + count;
                if (i == total-1){line = line + "])},1000);\n});\n}\n</script>";}
                    else{line = line + ",";}
            }
            out<<line;
        }
    }
    savef->close();
    delete(savef);
    //文件处理结束
    QString naka = QDir::currentPath();
    QString shit = "file:///" + naka + "/../project1/newdrive.html";
    //将QString 转换成 QUrl
    QUrl url(shit);
    webView->reload();
    webView->setUrl(url);
    webView->reload();
    shit.clear();
    url.clear();
}
