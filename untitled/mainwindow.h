#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "map.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //重写绘图事件
    void paintEvent(QPaintEvent *);

    map *mymap = NULL;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
