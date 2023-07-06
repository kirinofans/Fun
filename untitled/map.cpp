#include "map.h"
#include "mybutton1.h"
#include "playwindow.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>

map::map(QWidget *parent) : QMainWindow(parent)
{
    //设置固定大小
    this->setFixedSize(1500,1000);
    //设置图片
    this->setWindowIcon(QPixmap(":/background/image/mainwin.jpg"));

    this->setWindowTitle("捕鱼达人场景选择");

    //菜单栏等等
    QMenuBar * bar = new QMenuBar();
    setMenuBar(bar);
    QMenu * startme = bar->addMenu("开始");
    bar->addAction("帮助");
    QAction * quit = startme->addAction("退出");
    connect(quit,&QAction::triggered,[=] () {
        this->close();
    });

    //设置地图选择按钮
    MyPushButton1 * map1btn = new MyPushButton1(":/other/image/chosebtn.png","");
    map1btn->setParent(this);
    map1btn->move(160,900);
    //设置地图选择按钮
    MyPushButton1 * map2btn = new MyPushButton1(":/other/image/chosebtn2.png","");
    map2btn->setParent(this);
    map2btn->move(650,900);
    //设置地图选择按钮
    MyPushButton1 * map3btn = new MyPushButton1(":/other/image/chosebtn3.png","");
    map3btn->setParent(this);
    map3btn->move(1100,900);


    //按钮触发的事件
    connect(map1btn,&MyPushButton1::clicked,[=] () {
        //做特效
        map1btn->sta1();
        map1btn->sta2();
        //延时一下
        QTimer::singleShot(500,this,[=] () {
            //进入场景
            //隐藏自身
            this->hide();
            this->play = new playwindow(1);//传入地图代号
            play->show();
        });
    });
    //按钮触发的事件
    connect(map2btn,&MyPushButton1::clicked,[=] () {
        //做特效
        map2btn->sta1();
        map2btn->sta2();
        //延时一下
        QTimer::singleShot(500,this,[=] () {
            //进入场景
            //隐藏自身
            this->hide();
            this->play = new playwindow(2);//传入地图代号
            play->show();
        });
    });
    //按钮触发的事件
    connect(map3btn,&MyPushButton1::clicked,[=] () {
        //做特效
        map3btn->sta1();
        map3btn->sta2();
        //延时一下
        QTimer::singleShot(500,this,[=] () {
            //进入场景
            //隐藏自身
            this->hide();
            this->play = new playwindow(3);//传入地图代号
            play->show();

        });
    });
}
void map::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/background/image/chosemap.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/other/image/dia.png");
    painter.drawPixmap(590,120,pix.width(),pix.height(),pix);

    pix.load(":/background/image/background1.jpg");
    painter.drawPixmap(50,200,400,600,pix);

    pix.load(":/background/image/background2.jpg");
    painter.drawPixmap(550,200,400,600,pix);

    pix.load(":/background/image/background3.jpg");
    painter.drawPixmap(1050,200,400,600,pix);



}
