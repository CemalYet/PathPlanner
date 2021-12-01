#include <QApplication>
#include "ViewGraphical.h"


ViewGraphical * viewGraphical;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    viewGraphical = new ViewGraphical();
    viewGraphical->show();

    return a.exec();
}
