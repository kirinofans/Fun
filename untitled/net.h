#ifndef NET_H
#define NET_H

#include "myitem.h"
#include "playwindow.h"
#include "gun.h"

class net: public MyItem
{
public:
    net(const QString & filename , QGraphicsScene *scence,playwindow *window,Qgun *gun);
    void advance(int phase);
    enum { Type = 2 };
    int type() const override;
    playwindow *window;
    Qgun *gun;
};

#endif // NET_H
