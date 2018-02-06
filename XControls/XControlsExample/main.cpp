#include "XControlsExample.h"
#include "XControls/XApplication.h"
#include <QDebug>
#include <QTemporaryDir>
#include <QDir>
#include <QStandardPaths>
#include <windows.h>
#include <map>

#include "XControls/XWidget.h"
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

    qDebug() << "Cache:" << QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    qDebug() << "AppLocalData:" << QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    qDebug() << "AppData:" << QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    qDebug() << "Temp:" << QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    qDebug() << "Runtime:" << QStandardPaths::writableLocation(QStandardPaths::RuntimeLocation);
    qDebug() << "AppLocalData:" << QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation);
    qDebug() << "Cache:" << QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    qDebug() << "Cache:" << QStandardPaths::writableLocation(QStandardPaths::CacheLocation);

    QString cacheDir = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    if (!QFileInfo(cacheDir).isDir())
    {
        qDebug() << cacheDir << ":not exist";
        bool ret = QDir().mkpath(cacheDir);
        if (!ret)
        {
            qWarning() << "mkdir fail:" << cacheDir;
        }
    }

    qDebug() << QFileInfo(cacheDir).fileName();

    std::map<int, int64_t> maps;
    qDebug() << "size of map:" << sizeof(maps);

    QString symbolPath = cacheDir + "/dir_mc_in";
    QString realPath = "F:/Game1";
    CreateSymbolicLinkW(
        reinterpret_cast<LPCWSTR>(symbolPath.utf16()),
        reinterpret_cast<LPCWSTR>(realPath.utf16()),
        SYMBOLIC_LINK_FLAG_DIRECTORY);

    
    if (QFileInfo(symbolPath).exists())
    {
        bool ret = false;
        ret = QDir().rmdir(symbolPath);
    }
    //XControlsExample w;
    XWidget w;
    w.setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    w.setFixedSize(960, 600);
    w.show();

    return a.exec();
}
