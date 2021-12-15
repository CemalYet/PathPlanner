#ifndef MY_QLABEL_H
#define MY_QLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

class  my_qlabel : public QLabel
{
    Q_OBJECT
private:


public:
    explicit my_qlabel(QWidget *parent = 0);

    void mouseMoveEvent(QMouseEvent *ev);
    //void mousePressEvent(QMouseEvent *ev);
    void leaveEvent(QEvent *);

    int x,y;

signals:
    void Mouse_pressed();
    void Mouse_Pos();
    void Mouse_left();

};

#endif // MY_QLABEL_H
