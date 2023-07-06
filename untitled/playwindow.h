#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsView>
#include "gun.h"
#include "fish.h"
#include <QTimer>
#include <QTextEdit>

class playwindow : public QGraphicsView
{
    Q_OBJECT
public:
    //explicit playwindow(QWidget *parent = nullptr);
    playwindow(int level);
    ~playwindow();
    void resizeEvent(QResizeEvent * event);
    void mouseMoveEvent(QMouseEvent *event);//大炮追踪鼠标 用于大炮类
    void mousePressEvent(QMouseEvent *event);//鼠标按下事件 用于子弹类
    void checkgunindex(int gunindex);
    void updatescore();
    int levelnum;//记录关卡号
    int score = 10;//记录得分
    int fireornot = 0;//是否开火，开火就扣分当做消耗
    int gunindex;//记录炮的下标
    QTextEdit *showscore;//得分框显示

private:
    QGraphicsScene *scence;
    Qgun * gun;
    fish *fish1;
    fish *fish2;
    fish *fish3;
    fish *fish4;
    fish *fish5;
    fish *fish6;
    fish *fish7;
    fish *fish8;
    QTimer *timer;

signals:

};

#endif // PLAYWINDOW_H
