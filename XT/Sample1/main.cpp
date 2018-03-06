#include "Sample1.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sample1 w;
    w.show();
    return a.exec();
}
