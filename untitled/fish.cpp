#include "fish.h"
#include <QGraphicsItem>
#include <QGraphicsScene>

fish::fish(const QString & filename , QGraphicsScene *scence,int hp,int value,int maxhp,int fishindex):MyItem(filename,scence)
{
    this->hp = hp;
    this->value = value;
    this->maxhp = maxhp;
    this->pixmap = filename;
    this->fishindex = fishindex;
    scence->addItem(this);
}
QRectF fish::boundingRect () const
{
    return QRectF(-pixmap.width()/2,-pixmap.height(),pixmap.width(),pixmap.height());
}
void fish::advance(int phase){
    if(mapToScene(0,0).y()<=0||mapToScene(0,0).x() >= 1400){//跑出去就重设位置
        this->hp = this->maxhp;
        setPos(-120,qrand()%600);
    }
    int speed = qrand()%20;
    setPos(mapToScene(speed,-qrand()%3));
}

void fish::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    char filename[50]="0";

    switch (this->fishindex) {
    case 1:
        static int i1=0;
        sprintf(filename,":/fish/image/fish5.%d.png",i1++%4+1);//魔鬼鱼
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    case 2:
        static int i2=0;
        sprintf(filename,":/fish/image/fish6.%d.png",i2++%5+1);//鲨鱼
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    case 3:
        static int i3=0;
        sprintf(filename,":/fish/image/fish7.%d.png",i3++%3+1);//黄金墨鱼
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    case 4:
        static int i4=0;
        sprintf(filename,":/fish/image/fish8.%d.png",i4++%4+1);//大白鲨
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    case 5:
        static int i5=0;
        sprintf(filename,":/fish/image/fish9.%d.png",i5++%2+1);//大金鱼
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    default:
        static int i6=0;
        sprintf(filename,":/fish/image/greenfish%d.png",i6++%6+1);//小绿鱼
        pixmap.load(filename);
        painter->drawPixmap(-pixmap.width()/2,-pixmap.height(),pixmap);
        break;
    }

}
int fish::type() const
{
    return Type;
}
