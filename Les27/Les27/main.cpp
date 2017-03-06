#include "mainwindow.h"
#include <QApplication>
#include "SoundPlayer.h"
#include "VideoPlayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    SoundPlayer soundPlayer;
//    soundPlayer.setWindowTitle("MyPlayer");
//    soundPlayer.resize(230,75);
//    soundPlayer.show();

    VideoPlayer videoPlayer;

    videoPlayer.resize(320,80);
    videoPlayer.show();

    return a.exec();
}
