#include "XControlsExample.h"
#include "XControls/XApplication.h"
#include <QDebug>

#include <map>
int main(int argc, char *argv[])
{

    QString logFileName = "Example.log";

#ifdef QT_DEBUG
    QString qssName = "XControlsExample.qss";
    QString translatorName = "xcontrolsexample_zh.qm";
#else
    QString qssName = ":/XControlsExample/stylesheet";
    QString translatorName = ":/XControlsExample/language_zh";
#endif

    

    XApplication a(argc, argv);
    a.setLogFileName(logFileName);
    a.setQssName(qssName);
    a.setTranslatorName(translatorName);
    a.initialize();

    std::map<int, int64_t> maps;
    qDebug() << "size of map:" << sizeof(maps);

    XControlsExample w;
    w.show();

    return a.exec();
}
