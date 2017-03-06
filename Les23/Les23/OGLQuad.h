#ifndef OGLQUAD_H
#define OGLQUAD_H

#include <QOpenGLWidget>
#include <QtWidgets>
#include <QtOpenGL>

class OGLQuad : public QGLWidget
{
protected:
    virtual void initializeGL();
    virtual void resizeGL(int nWidth, int nHeight);
    virtual void paintGL();
public:
    explicit OGLQuad(QWidget *pwgt = 0);
};

#endif // OGLQUAD_H
