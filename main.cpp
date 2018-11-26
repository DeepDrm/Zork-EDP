#include <iostream>
#include <QApplication>

using namespace std;
#include "mainwindow.h"
#include "ZorkUL.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    MainWindow w;
    w.setVisible(true);
    w.show();

    return a.exec();
}
