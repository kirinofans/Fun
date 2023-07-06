#ifndef FISH_H
#define FISH_H
#include "myitem.h"

class fish : public MyItem
{
public:
    fish(const QString & filename , QGraphicsScene *scence,int hp,int value,int maxhp,int fishindex);
    void advance(int phase);//重载这个函数，每次timeout信号触发，所有有advance的item都会执行，不用一个一个绑定
    QRectF boundingRect () const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
//重载paint函数，不止画一张画面，实现鱼儿摇头摆尾
    int hp;//鱼的血量，分数等等
    int value;
    int maxhp;//最大血量，当鱼跑出边框时，把鱼的血量恢复最大
    int fishindex;//不同编号代表不同的鱼
    enum { Type = 1 };
    int type() const override;
private:
    QPixmap pixmap;



};

#endif // FISH_H
