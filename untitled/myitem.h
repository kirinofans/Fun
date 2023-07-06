#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>


class MyItem:public QGraphicsItem
{
public:
    MyItem(const QString & filename , QGraphicsScene *scence);
    //重写两个纯虚函数boundingRect 返回item大致区域paint来绘制item
    QRectF boundingRect () const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    int type() const override;

private:
    QPixmap pixmap;
};

#endif // MYITEM_H
