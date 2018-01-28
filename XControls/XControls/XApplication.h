#ifndef XAPPLICATION_H
#define XAPPLICATION_H

#include "xcontrols_global.h"
#include <QtWidgets/QApplication>

class QTranslator;

class XCONTROLS_EXPORT XApplication:public QApplication
{
    Q_OBJECT
public:
	XApplication(int &argc, char **argv);
	virtual ~XApplication();

public:
    void setLogFileName(const QString& name) { logFileName = name; }
    void setQssName(const QString& name) { qssName = name; }
    void setTranslatorName(const QString& name) { translatorName = name; }

public:
	void initialize();

private:
	void intializeTranslator();
	void intializeStyleSheet();
	void intializeFonts();

private:
	QTranslator* translator;
    QString logFileName;
    QString qssName;
    QString translatorName;
};

#endif