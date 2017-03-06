#include "VideoPlayer.h"

#include <QtWidgets>
#include <QVideoWidget>

VideoPlayer::VideoPlayer(QWidget *pwgt):SoundPlayer(pwgt)
{
    pvw = new QVideoWidget;
    pvw->setMinimumSize(300,300);
    //m_pvbxMainLayout->addWidget(pvw);
    pvw->show();
    m_pmp->setVideoOutput(pvw);
    QPushButton *shButton = new QPushButton("&FULLSCREEN");
    m_pvbxMainLayout->addWidget(shButton);
    shButton->setFlat(true);
    shButton->setCheckable(true);
    connect(shButton,SIGNAL(clicked(bool)),pvw,SLOT(setFullScreen(bool)));
}
