#include "XApplication.h"
#include "XLogger.h"


#include <QFontDatabase>
#include <QStyleFactory>
#include <QTranslator>
#include <QDir>
#include <QDebug>

XApplication::XApplication(int &argc, char **argv) :
	QApplication(argc, argv)
{

}

void XApplication::initialize()
{
    XLogger::getInstance().setLogFileName(logFileName);
    qInstallMessageHandler(XLogger::messageHandler);
	intializeFonts();
	intializeTranslator();
	intializeStyleSheet();
}

XApplication::~XApplication()
{
	qDebug() << "XApplication destructor";
}

void XApplication::intializeTranslator()
{
	// Translator settings
	bool ret = false;
	translator = new QTranslator(this);
	ret = translator->load(translatorName);

	if (!ret)
	{
		qCritical() << "Load translator fail";
	}
	ret = installTranslator(translator);
	if (!ret)
	{
		qCritical() << "Install translator fail";
	}
}
void XApplication::intializeStyleSheet()
{
	bool ret = false;
	QFile file(qssName);
	ret = file.open(QFile::ReadOnly);
	if (!ret)
	{
		qCritical() << "Open stylesheet fail";
	}
	else
	{
		setStyleSheet(file.readAll());
		file.close();
	}
	
}
void XApplication::intializeFonts()
{
	QString homeDir = "";
#ifdef QT_DEBUG
	homeDir = QDir::currentPath();
#else
	homeDir = applicationDirPath();
#endif

	// Font settings
	QString yhPath = homeDir + "/fonts/MSYH.TTC";
	QString fontName;
	if (QFile::exists(yhPath))
	{
		int fontId = QFontDatabase::addApplicationFont(homeDir + "/fonts/MSYH.TTC");
		QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
		qDebug() << fontName;
		QFont font(fontName);
		setFont(font);
	}
	else
	{
		qWarning() << "font:" << yhPath << " not exists";
	}
	

	//yhPath = homeDir + "/fonts/MSYHBD.TTC";
	//if (QFile::exists(yhPath))
	//{
	//	int fontBoldId = QFontDatabase::addApplicationFont(yhPath);
	//	fontName = QFontDatabase::applicationFontFamilies(fontBoldId).at(0);
	//	qDebug() << fontName;
	//}
	//else
	//{
	//	qWarning() << "font:" << yhPath << " not exists";
	//}
}