#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QWidget>
#include <QMenu>
#include <QPoint>
#include <QSize>

#include "Screen.h"

//截屏窗口类
class ScreenShot : public QWidget
{
    Q_OBJECT
public:
    static ScreenShot *Instance();
    explicit ScreenShot(QWidget *parent = 0);

private:
    static QScopedPointer<ScreenShot> self;
    QMenu *menu;            //右键菜单对象
    Screen *screen;         //截屏对象
    QPixmap *fullScreen;    //保存全屏图像
    QPixmap *bgScreen;      //模糊背景图
    QPoint movPos;          //坐标

protected:
    void contextMenuEvent(QContextMenuEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);

private slots:
    void saveScreen();
    void saveFullScreen();
    void saveScreenOther();
    void saveFullOther();
};
#endif // SCREENSHOT_H
