#include "mainwindow_person.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_Person w;
    w.show();

    return a.exec();
}
