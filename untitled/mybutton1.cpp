#include "mybutton1.h"
#include <QDebug>
#include <QSize>
#include <QPropertyAnimation>

//mybutton1::mybutton1(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton1::MyPushButton1(QString normalimg,QString pressimg)
{
    this->normalimgpath = normalimg;
    this->pressimgpath = pressimg;

    QPixmap pix;
    bool ret = pix.load(normalimg);
    if(!ret){
        qDebug()<<"图片加载失败";
        return ;
    }

    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());
    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
    show();

}

void MyPushButton1::sta1(){

    //动画效果
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//时间间隔

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+15,this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行
    animation->start();

}

void MyPushButton1::sta2(){
    //动画效果
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(200);//时间间隔

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+15,this->width(),this->height()));

    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行
    animation->start();
}
