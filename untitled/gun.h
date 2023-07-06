#ifndef GUN_H
#define GUN_H
#include "myitem.h"

class Qgun:public MyItem
{
public:
    Qgun(const QString & filename , QGraphicsScene *scence,int power);
    void changegun(int gunindex);
    int netindex;
    int power;
//private:
    enum { Type = 3 };
    int type() const override;
    QPixmap pixmap;

};

#endif // GUN_H
