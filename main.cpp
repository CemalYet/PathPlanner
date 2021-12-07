#include <QApplication>
#include "ViewGraphical.h"
#include "mainwindow.h"


ViewGraphical * viewGraphical;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //viewGraphical = new ViewGraphical();
    //viewGraphical->show();
    MainWindow w;
    w.show();

    return a.exec();
}
