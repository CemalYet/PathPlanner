#ifndef VIEWHEALTH_H
#define VIEWHEALTH_H

#include <QGraphicsTextItem>
#include <QWidget>

class QProgressBar;

class ViewHealth : public QWidget
{

public:
    ViewHealth(QWidget * parent=0);

    void increase();
    int getHealth();

private:
    int Health;
    QProgressBar *progressBar;

public slots:
    void updateProgress();

};

#endif // VIEWHEALTH_H
