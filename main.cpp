#include "mainwindow.h"
#include "database.h"
#include <QApplication>
#include <QtSql>
#include <QtGui>










int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;


    w.show();


    
    return a.exec();
}