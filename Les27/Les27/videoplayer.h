#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include "SoundPlayer.h"

class VideoPlayer : public SoundPlayer
{
private:
    QVideoWidget *pvw;
public:
    VideoPlayer(QWidget *pwgt = 0);
};

#endif // VIDEOPLAYER_H
