#ifndef DIALOG_BASE_H
#define DIALOG_BASE_H

#include <QDialog>
#include <QLabel>

class QStackedWidget;
class QWidget;
class QPushButton;


class DialogBase:public QDialog{
  
    Q_OBJECT
public:
    DialogBase(QWidget* parent = Q_NULLPTR);

public:
	void setTitle(const QString& text) { m_title->setText(text); }
	void setCentralWidget(QWidget* w);

    void showEvent(QShowEvent* event)override;

protected:
    bool event(QEvent* e)override;
    void keyPressEvent(QKeyEvent* e)override;
    bool eventFilter(QObject* o, QEvent* e)override;

    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    void paintEvent(QPaintEvent* e)override;

private:
	QStackedWidget* m_center;
	QWidget* m_win;
	QLabel* m_title;
    QPushButton* btnClose;

private:
    bool m_isPressed;
    QPoint m_point;
};

#endif