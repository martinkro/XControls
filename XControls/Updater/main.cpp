#include "Updater.h"
#include <QtWidgets/QApplication>
#include <QDebug>

#include <windows.h>
#include <Winver.h>

//#pragma comment(lib,"Mincore.lib")
#pragma comment(lib,"version.lib")
#include <string>

void GetPEFileVersion(const QString& exePath)
{
    DWORD dwHandle = 0;
    DWORD dwInfoSize = 0;
    dwInfoSize = GetFileVersionInfoSizeW((LPCWSTR)exePath.utf16(), &dwHandle);
    if (dwInfoSize == 0)
    {
        return;
    }

    unsigned char* versionInfoBuffer = new unsigned char[dwInfoSize];
    GetFileVersionInfoW((LPCWSTR)exePath.utf16(), dwHandle, dwInfoSize, versionInfoBuffer);

    LPVOID lpBuffer = 0;
    UINT pLen = 0;
    BOOL ret = VerQueryValueW(versionInfoBuffer, L"\\StringFileInfo\\080404b0\\ProductVersion", &lpBuffer, &pLen);
    if (ret)
    {
        std::wstring x((const wchar_t*)lpBuffer, pLen);
        qDebug() << "version:" << x.c_str();
    }
    else
    {
        DWORD error = GetLastError();
        qDebug() << "VerQueryValueW fail:" << error;
    }

}

int main(int argc, char *argv[])
{
   
    
    QApplication a(argc, argv);

    QString appDir = qApp->applicationDirPath();
    QString appName = qApp->applicationName();

    qDebug() << "appDir:" << appDir;
    qDebug() << "appName:" << appName;

    QString exePath = appDir + "/" + appName + ".exe";
    qDebug() << "exePath:" << exePath;

    GetPEFileVersion(exePath);

    Updater w;
    w.show();
    return a.exec();
}
