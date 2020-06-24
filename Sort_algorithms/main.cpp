#include "mainwindow.h"
#include <QApplication>
#include <tests.h>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    Tests tests;
    tests.test();
    w.show();
    return a.exec();
}
