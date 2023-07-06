#include "all.h"
all::all(QString & fileName,QGraphicsScene *scence)
{
    pixmap.load(fileName);
    scence->addItem(this);
}

QRectF all::boundingRect() const
{
    return QRectF(-pixmap.width()/2,-pixmap.height(),pixmap.width(),pixmap.height());
}


void all::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    //位置设置为-pixmap.width()/2,-pixmap.height()，以便在场景绘图时不在场景之外
    painter->drawPixmap(pixmap.width()/2,pixmap.height(),pixmap);
}
