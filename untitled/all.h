#ifndef ALL_H
#define ALL_H

#include <QMainWindow>
#include <QGraphicsItem>   //图元
#include <QGraphicsView>   //视图
#include <QGraphicsScene>  //场景

class all : public QGraphicsItem  //自定义类
{
    //Q_OBJECT
public:
    //explicit all(QWidget *parent = nullptr);
    //重写了boundingRect函数、paint函数以及advance函数。
    //boundingRect用于返回一个碰撞大小的矩形框，对之后碰撞检测有影响。
    //paint函数主要用于图元的绘制，实现自定义图元。advance函数用于图元移动。
    all(QString & fileName,QGraphicsScene *scence);
    virtual QRectF boundingRect() const override;
    //void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //QRectF boundingRect() const override;//重写
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    QPixmap pixmap;
signals:

};

#endif // ALL_H
