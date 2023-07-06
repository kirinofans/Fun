#include "myitem.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

MyItem::MyItem(const QString & filename,QGraphicsScene * scence)
{
    pixmap.load(filename);
    scence->addItem(this);
}
int MyItem::type() const
{

    // Enable the use of qgraphicsitem_cast with this item.

    return Type;

}
QRectF MyItem::boundingRect () const
{
    return QRectF(-pixmap.width()/2,-pixmap.height(),pixmap.width(),pixmap.height());
}

void MyItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
}
