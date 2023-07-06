#ifndef BUTTLE_H
#define BUTTLE_H

#include "myitem.h"
#include <QGraphicsScene>
#include "playwindow.h"
#include "gun.h"

class buttle : public MyItem
{
public:
    buttle(const QString & filename , QGraphicsScene *scence,qreal angle,playwindow*window,Qgun *gun);
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    void advance(int phase);//重写advance函数进行移动

    void colliding();//碰撞之后执行
private:
    QGraphicsScene *scence;
    QPixmap pixmap;
    QString filename;
    playwindow*window;
    Qgun *gun;
};

#endif // BUTTLE_H
