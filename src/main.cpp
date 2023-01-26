#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentAnalyzer w;
    w.show();
    return a.exec();
}
