#ifndef MYGUN_H
#define MYGUN_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <all.h>
#include <QGraphicsScene>
class Gun:public all
{
public:
    Gun(const QString & fileName,QGraphicsScene *scence);

};


#endif // MYGUN_H
