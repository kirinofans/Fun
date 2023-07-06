#include "net.h"
#include "fish.h"
#include "playwindow.h"
#include <QDebug>

net::net(const QString & filename , QGraphicsScene *scence,playwindow *window,Qgun *gun):MyItem(filename,scence)
{
    this->window = window;
    this->gun = gun;
}
void net::advance(int phase){
    if(this->collidingItems().count()>0){
        //qDebug()<<
        QList <QGraphicsItem *> tem = this->collidingItems();


        foreach (QGraphicsItem *item, tem) {
            if(item->type() == fish::Type){
//重载了type函数，获取item的类型判断返回的QGraphicsItem *item每个节点是否都是鱼
//避免了返回的item是渔网类型而强制转换成鱼而报错终止程序的bug
//可喜可贺  2023/7/5
                //qDebug()<<"类型:"<<item->type();
                fish *fishs;
                fishs =(fish*)(item);
                     fishs->hp-=this->gun->power; //减少一点当前生命值
                     if(fishs->hp<=0)
                     {
                                       //鱼死亡，加分
                        this->window->score+=fishs->value;
                        fishs->setPos(-50-rand()%300,200+rand()%500);//鱼死亡就移到屏幕外
                        fishs->hp = fishs->maxhp;
                      }
            }
            else{
                //qDebug()<<"类型不对"<<item->type();
            }

        }
//        QList<QGraphicsItem *>::Iterator i;//迭代器，用来遍历
//                fish *fishs;
//                i=tem.begin();//表头
//                while(i!=tem.end())
//                {
//                    fishs=(fish *)(*i);
//                    fishs->hp-=this->gun->power; //减少一点当前生命值
//                    if(fishs->hp<=0)
//                    {
//                        //鱼死亡，加分
//                        this->window->score+=fishs->value;
//                        fishs->setPos(-50-rand()%300,200+rand()%500);//鱼死亡就移到屏幕外
//                        fishs->hp = fishs->maxhp;
//                    }
//                    i++;
//                }

    }
    this->hide();
    delete this;
}
int net::type() const
{
    return Type;
}
