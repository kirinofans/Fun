#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include "playwindow.h"

class map : public QMainWindow
{
    Q_OBJECT
public:
    explicit map(QWidget *parent = nullptr);

    //重写绘图事件
    void paintEvent(QPaintEvent *);

    //游戏场景对象指针
    playwindow *play = NULL;

signals:

};

#endif // MAP_H
