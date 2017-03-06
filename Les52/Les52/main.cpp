#include <QApplication>
#include <TurtleWorkArea.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TurtleWorkArea turtleWorkarea;
    turtleWorkarea.setWindowTitle("Turtle with JavaScript");
    turtleWorkarea.show();

    return a.exec();
}
