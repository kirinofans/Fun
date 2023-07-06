#include "playwindow.h"
#include "myitem.h"
#include "gun.h"
#include <QMenuBar>
#include <QPainter>
#include <QTimer>
#include <QString>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QResizeEvent>
#include "fish.h"
#include "mybutton1.h"
#include <QTimer>
#include "buttle.h"
#include <QTextEdit>
//playwindow::playwindow(QWidget *parent) : QMainWindow(parent)
//{

//}
playwindow::playwindow(int level){
    //设置固定大小
    this->setFixedSize(1500,1000);
    //设置图片
    this->setWindowIcon(QPixmap(":/background/image/mainwin.jpg"));
    this->levelnum = level;
    this->setWindowTitle("捕鱼达人");
    //设置背景图片
    this->setAutoFillBackground(true);
    QString a[5] = {"",":/background/image/background1.jpg",":/background/image/background2.jpg",":/background/image/background3.jpg"};
    QString fin = a[this->levelnum];
    this->setBackgroundBrush(QBrush(QPixmap(fin)));
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);




    //创建分数显示框
    this->showscore=new QTextEdit(this);
    this->showscore->setReadOnly(true);//只读，可以复制
    this->showscore->setFixedSize(170,50);
    this->showscore->setFontPointSize(20);
    this->showscore->move(1350,0);

    //坐标系统不同
    scence = new QGraphicsScene;
    //scence->setSceneRect(-this->width()/2,-this->height()/2,this->width(),this->height());
    scence->setSceneRect(0,0,this->width()-5,this->height()-5);
    this->setScene(scence);

    //大炮
    gun = new Qgun(":/pao/image/pao4.png",scence,1);
    this->gunindex = 0;
    gun->setPos(this->width()/2,this->height()-10);//设置位置
    scence->addItem(gun);

    //加减按钮
    MyPushButton1 * up = new MyPushButton1(":/pao/image/btnup.png","");
    up->setParent(this);
    up->move(this->width()*0.5+35,this->height()-50);
    connect(up,&QPushButton::clicked,[=] ()
    {
        delete gun;
        this->gunindex += 1;
        if(this->gunindex  >= 4)
            this->gunindex=0;
        this->checkgunindex(this->gunindex);
    });

    MyPushButton1 * down = new MyPushButton1(":/pao/image/btndown.png","");
    down->setParent(this);
    down->move(this->width()*0.5-95,this->height()-50);
    connect(down,&QPushButton::clicked,[=] ()
    {
        delete gun;
        this->gunindex -= 1;
        if(this->gunindex < 0)
            this->gunindex = 3;
        this->checkgunindex(this->gunindex);
    });

    this->setMouseTracking(true);//设置鼠标追踪

    fish1 = new fish(":/fish/image/fish5.1.png",scence,8,10,8,1);//魅魔鱼
    fish1->setPos(-120,10);
//    scence->addItem(fish1);
    fish2 = new fish(":/fish/image/fish6.1.png",scence,30,45,30,2);//鲨鱼
    fish2->setPos(-80,30);
//    scence->addItem(fish2);
    fish3 = new fish(":/fish/image/fish8.1.png",scence,4,15,4,3);//墨鱼
    fish3->setPos(-110,15);
//    scence->addItem(fish3);
    fish8 = new fish(":/fish/image/greenfish1.png",scence,6,25,6,4);//大白鲨
    fish8->setPos(-65,5);
    fish4 = new fish(":/fish/image/fish9.1.png",scence,90,120,90,5);//黄金鱼
    fish4->setPos(-99,11);
//    scence->addItem(fish4);
    fish5 = new fish(":/fish/image/greenfish1.png",scence,6,25,6,6);//小绿鱼
    fish5->setPos(-70,10);
    fish6 = new fish(":/fish/image/greenfish1.png",scence,6,25,6,6);//小绿鱼
    fish6->setPos(-75,44);
    fish7 = new fish(":/fish/image/greenfish1.png",scence,6,25,6,6);//小绿鱼
    fish7->setPos(-88,35);


    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),scence,SLOT(advance()));
    connect(timer,&QTimer::timeout,this,&playwindow::updatescore);
    timer->start(50);


}

void playwindow::resizeEvent(QResizeEvent * event){
    QString a[5] = {"",":/background/image/background1.jpg",":/background/image/background2.jpg",":/background/image/background3.jpg"};
    QString fin = a[this->levelnum];
    this->setBackgroundBrush(QBrush(QPixmap(fin).scaled(event->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
}

void playwindow::mouseMoveEvent(QMouseEvent *event){
    QPoint p;
    p = event->pos();//获取鼠标的点
    QLine line(this->width()/2,this->height(),p.x(),p.y());//鼠标位置和大炮之间画一条线
    QLineF linef(line);//变成浮点数
    gun->setRotation(90-linef.angle());//获取角度,旋转大炮
}

void playwindow::mousePressEvent(QMouseEvent *event){

    QString dan[5] = {":/pao/image/dan3.png",":/pao/image/dan4.png",":/pao/image/dan1.png",":/pao/image/dan2.png"};
    QString fin = dan[this->gunindex%4];//不同子弹类型

    QPoint p = event->pos();
    QLineF linef(this->width()/2,this->height(),p.x(),p.y());
    //子弹射出位置应该是炮口，在一个弧线上
    buttle *mybuttle = new buttle(fin,scence,linef.angle(),this,this->gun);
    this->fireornot += 1;
//    mybuttle->setPos(this->width()/2,this->height());
//    mybuttle->setRotation(90-linef.angle());//转移到构造函数了
}

void playwindow::updatescore(){
    if(this->fireornot == 1){
        this->fireornot = 0;
        this->score -= this->gun->power;
    }
    QString str = "得分:";
    QString strscore = QString::number(this->score);
    str.append(strscore);
    //强制类型转换之后添加
    //str.sprintf("得分：%d",score);
    //强烈建议别使用这种方法qwq
    this->showscore->setText(str);
}
void playwindow::checkgunindex(int gunindex){
    QString gunn[5] = {":/pao/image/pao4.png",":/pao/image/pao3.png",":/pao/image/pao5.png",":/pao/image/pao10.jpg"};
    QString fin = gunn[this->gunindex%4];
    switch (gunindex%4) {
    case 0:
        gun = new Qgun(fin,scence,1);
        gun->setPos(this->width()/2,this->height()-10);//设置位置
        scence->addItem(gun);
        break;
    case 1:
        gun = new Qgun(fin,scence,2);
        gun->setPos(this->width()/2,this->height()-10);//设置位置
        scence->addItem(gun);
        break;
    case 2:
        gun = new Qgun(fin,scence,5);
        gun->setPos(this->width()/2,this->height()-10);//设置位置
        scence->addItem(gun);
        break;
    default:
        gun = new Qgun(fin,scence,10);
        gun->setPos(this->width()/2,this->height()-10);//设置位置
        scence->addItem(gun);
        break;
    }

}
playwindow::~playwindow(){
    delete this;
}
