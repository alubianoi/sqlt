#include <QtSql>
#include <QtGui>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createConnection();

    //QSqlRelationalTableModel model;
    //QTableView view;
    model = new QSqlRelationalTableModel;
    model->setTable("modules");
    model->select();
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    connect(ui->savebutton,SIGNAL(pressed()),model,SLOT(submitAll()));
    connect(ui->revertbutton,SIGNAL(pressed()),model,SLOT(revertAll()));

    ui->view->setModel(model);
    ui->view->resizeColumnsToContents();



}

MainWindow::~MainWindow()
{
    delete ui;
}



