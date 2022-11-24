#include "clw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    clw w;
    w.show();

    return a.exec();
}
