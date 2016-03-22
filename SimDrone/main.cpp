#include "simdrone.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    simDrone w;
    w.show();

    return a.exec();
}
