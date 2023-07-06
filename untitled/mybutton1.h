#ifndef MYBUTTON1_H
#define MYBUTTON1_H

#include <QWidget>
#include <QPushButton>
#include <QString>

class MyPushButton1 : public QPushButton
{
    Q_OBJECT
public:
    //explicit mybutton1(QWidget *parent = nullptr);

    //构造函数 参数一 默认显示图片 参数二 按下按键显示图片
    MyPushButton1(QString normalimg,QString pressimg);

    //成员属性
    QString normalimgpath;
    QString pressimgpath;

    //弹跳效果
    void sta1();//上跳
    void sta2();//下跳

signals:

};

#endif // MYBUTTON1_H
