#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


static bool createConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db.sqlite");

    if(!db.open()) {
        qDebug()<<db.lastError().text();
        return false;
    }
    else {
        qDebug()<< "db loaded";
        return true;
    }
}

#endif // DATABASE_H
