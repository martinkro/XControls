#include "sampleforframeless.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SampleForFrameless w;
    w.show();
    return a.exec();
}
