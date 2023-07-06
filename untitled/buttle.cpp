#include "buttle.h"
#include <QtGui>
#include <QGraphicsScene>
#include <QtDebug>
#include "net.h"
#include <QList>
#include <QGraphicsItem>
#include "fish.h"
#include "playwindow.h"
#include "gun.h"

buttle::buttle(const QString & filename ,QGraphicsScene *scence,qreal angle,playwindow*window , Qgun *gun):MyItem(filename,scence)
{
    this->gun = gun;
    this->window = window;
    this->filename = filename;
    this->scence = scence;
    qreal dx,dy;
    qreal rad;
    rad = angle*3.14/180;
    dx = 130*cos(rad);
    dy = 130*sin(rad);
    this->setPos(scence->width()/2+dx,scence->height()-dy);
    this->setRotation(90-angle);//设置角度
}
void buttle::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    pixmap.load(filename);
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
    if(this->collidingItems().count()>0){
//        //qDebug()<<
//        QList <QGraphicsItem *> tem = this->collidingItems();
//        QList<QGraphicsItem *>::Iterator i;//迭代器，用来遍历
//                fish *fishs;
//                i=tem.begin();
//                while(i!=tem.end())
//                {
//                    fishs=(fish *)(*i);
//                    fishs->hp-=1; //减少一点当前生命值
//                    if(fishs->hp==0)
//                    {
//                        //鱼死亡，加分
//                    }
//                    i++;
//                }

        //qDebug()<<scence->items().pare;
        colliding();
    }
}
void buttle::advance(int phase){

    if(mapToScene(0,0).x() <= 0||mapToScene(0,0).x() > 1400||mapToScene(0,0).y() <= 0){
        delete  this;//超出边框自动释放
        //qDebug()<<mapToScene(0,0).x()<<mapToScene(0,0);
    }
    else{
        this->setPos(mapToScene(0,-22));
    }
//    mapToScene主要解决了怎么从父widget中得到相应的坐标，然后通过mapToScene函数进行转换，即可得到相应的坐标
//    简单来说这个函数就是为了将之前（父widget）的坐标转换到目前的坐标系中去

}
void buttle::colliding(){//碰撞处理

    QString nett[5] = {":/pao/image/net2.png",":/pao/image/net4.png",":/pao/image/net.png",":/pao/image/netsss.png"};
    QString fin = nett[this->window->gunindex%4];
    net *mynet = new net(fin,this->scence,this->window,this->gun);
    mynet->setPos(mapToScene(0,0));
    delete this;
}
