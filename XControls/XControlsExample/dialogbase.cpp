#include "dialogbase.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QApplication>
#include <QDesktopWidget>
#include <QBitmap>
#include <QPainter>

DialogBase::DialogBase(QWidget* parent)
    :QDialog(parent)
{
	setWindowFlags(Qt::FramelessWindowHint|Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);
    //setAutoFillBackground(true);
    //setWindowOpacity(0.8);
    //QPalette palette = this->palette();
    //palette.setBrush(QPalette::Background, QBrush(QPixmap("images/dlg_advance_config_bg.png")));
    //setPalette(palette);

    //QPixmap pixmap("images/dlg_advance_config_bg.png");
    //setMask(pixmap.mask());

	m_title = new QLabel(tr("Dialog Title"));
	m_title->setObjectName("title");
	btnClose = new QPushButton;
	btnClose->setObjectName("close");

	QHBoxLayout* layoutTitle = new QHBoxLayout;
	layoutTitle->addWidget(m_title);
	layoutTitle->addStretch();
	layoutTitle->addWidget(btnClose,0,Qt::AlignRight);
	QWidget* title = new QWidget;
	title->setObjectName("title");
	title->setLayout(layoutTitle);

	m_win = new QWidget;
	m_center = new QStackedWidget;
	m_center->setObjectName("content");
	m_center->addWidget(m_win);
	QVBoxLayout* main = new QVBoxLayout;
	main->addWidget(title);
	main->addWidget(m_center, 1);
	main->setContentsMargins(0, 0, 0, 0);
	main->setSpacing(0);
	setLayout(main);

    //QLabel* mainLabel = new QLabel(this);
    //mainLabel->setObjectName("main");
    //mainLabel->setLayout(main);

    //QHBoxLayout* x = new QHBoxLayout;
    //x->setContentsMargins(0, 0, 0, 0);
    //x->setSpacing(0);
    //x->addWidget(mainLabel, 1);
    //setLayout(x);

	connect(btnClose, &QPushButton::clicked, [=]() {
		QDialog::close();
	});

    btnClose->setFocusPolicy(Qt::NoFocus);

    //QBitmap bixmap(":/images/dlg_advance_config_bg.png");

    //setMask(bixmap);
}

void DialogBase::setCentralWidget(QWidget* w)
{
	if (w == nullptr)
	{
		return;
	}
	if (m_win && m_win != w)
	{
		m_center->removeWidget(m_win);
		m_win->hide();
		m_win->deleteLater();
	}
	m_win = w;
	m_center->addWidget(m_win);
}

bool DialogBase::event(QEvent* e)
{
    //qDebug() << "DialogBase::event:" << e->type();
    return QDialog::event(e);
}

void DialogBase::keyPressEvent(QKeyEvent* e)
{
    //qDebug() << "DialogBase::keyPressEvent:" << e->key();
    if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Escape || e->key() == Qt::Key_Return)
    {
        return;
    }
    QDialog::keyPressEvent(e);
}

bool DialogBase::eventFilter(QObject* o, QEvent* e)
{
    qDebug() << "DialogBase::eventFilter";
    return QDialog::eventFilter(o, e);
}

void DialogBase::showEvent(QShowEvent* event)
{
    //MainWindow* mainWindow = nullptr;
    //for (QWidget* w : qApp->topLevelWidgets())
    //{
    //    mainWindow = qobject_cast<MainWindow*>(w);
    //    if (mainWindow != nullptr)
    //    {
    //        qDebug() << "Found main window";
    //        break;
    //    }
    //}
    //
    //if (mainWindow != nullptr)
    //{
    //    int cx = 0;
    //    int cy = 0;
    //    int centerX1 = mainWindow->width() / 2 + mainWindow->geometry().x();
    //    int centerY1 = mainWindow->height() / 2 + mainWindow->geometry().y();

    //    int centerX2 = width() / 2 + geometry().x();
    //    int centerY2 = height() / 2 + geometry().y();

    //    cx = centerX1 - centerX2;
    //    cy = centerY1 - centerY2;
    //    qDebug() << "MainWindow Size:" << mainWindow->size();
    //    qDebug() << "MainWindow geometry:" << mainWindow->geometry();
    //    qDebug() << "Dialog Size:" << size();
    //    qDebug() << "Dialog geometry:" << geometry();
    //    qDebug() << "offset:" << cx << "|" << cy;
    //    move(cx, cy);
    //}

    //m_title->setFocus();
    QDialog::showEvent(event);
}

void DialogBase::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isPressed)
    {
        // the mouse position relate to screen
        QPoint point = event->pos();
        move(point - m_point + pos());
    }

}
void DialogBase::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        //m_isPressed = true;
        m_point = event->pos();
        qDebug() << "event pos:" << m_point;
        qDebug() << "pos:" << pos();
        if (m_point.y() < 50)
        {
            m_isPressed = true;
        }
    }
    // the mouse position relate to the current widget
    // you can use event->pos() to replace it.
    
}
void DialogBase::mouseReleaseEvent(QMouseEvent *event)
{
    m_isPressed = false;
}

void DialogBase::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawPixmap(this->rect(),QPixmap("images/dlg_advance_config_bg.png"));
}