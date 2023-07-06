#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mybutton1.h"
#include "map.h"
#include <QPainter>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置固定大小
    this->setFixedSize(1500,1000);
    //设置图片
    this->setWindowIcon(QPixmap(":/background/image/mainwin.jpg"));

    this->setWindowTitle("捕鱼达人");
    //退出按钮
    connect(ui->exit,&QAction::triggered,[=] (){
        this->close();
    });
    //开始按钮
    MyPushButton1 * startbtn = new MyPushButton1(":/other/image/start.png","");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.75,600);

    this->mymap = new map();
    //开始按钮触发的事件
    connect(startbtn,&MyPushButton1::clicked,[=] () {
        //做特效
        startbtn->sta1();
        startbtn->sta2();

        //延时一下
        QTimer::singleShot(500,this,[=] () {
            //进入场景选择
            //隐藏自身
            this->hide();
            mymap->show();
        });
    });

}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/background/image/mainwin.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}


MainWindow::~MainWindow()
{
    delete ui;
}


