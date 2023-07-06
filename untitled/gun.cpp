#include "gun.h"
#include "myitem.h"

Qgun::Qgun(const QString & filename , QGraphicsScene *scence,int power):MyItem(filename,scence)//参数列表向基类传递参数
{
    this->power = power;
}

int Qgun::type() const
{
    return Type;
}
//void Qgun::changegun(int gunindex){
//    static int i = 0;



//}
