#include "Updater.h"
#include "XControls/XApplication.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QString logFileName = "updater.log";

#ifdef QT_DEBUG
    QString qssName = "updater.qss";
    QString translatorName = "updater_zh.qm";
#else
    QString qssName = ":/updater/stylesheet";
    QString translatorName = ":/updater/language_zh";
#endif



    XApplication a(argc, argv);
    a.setLogFileName(logFileName);
    a.setQssName(qssName);
    a.setTranslatorName(translatorName);
    a.initialize();

    Updater w;
    w.show();
    return a.exec();
}
