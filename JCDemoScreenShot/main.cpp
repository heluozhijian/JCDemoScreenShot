#include <QApplication>
#include <QTextCodec>

#include "ScreenShot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *textCodec = QTextCodec::codecForName("utf8");
    QTextCodec::setCodecForLocale(textCodec);

    ScreenShot::Instance()->showFullScreen();   //直接调用实例

    return a.exec();
}
