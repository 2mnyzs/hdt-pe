#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QStyle>
#include <QStyleFactory>
#include <iostream>

#include "havokhelper.h"

int main(int argc, char *argv[])
{
	initHavok();
	
    QApplication a(argc, argv);
	
    MainWindow w;
    w.show();

    return a.exec();
}
