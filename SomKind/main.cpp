#include "anotebook.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ANoteBook w;
    w.show();

    return a.exec();
}
