#include "main_window_person.h"
#include "ui_mainwindow_person.h"
#include <QDebug>
#include <QLabel>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QPixmap>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTableWidgetItem>


MainWindow_Person::MainWindow_Person(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Person)
{
   ui->setupUi(this);
   sizeTable=0;
   checkboxCountRow=0;

//   QSqlQuery query;
//   int id;
//   QString name,lastN;

//   query.prepare("SELECT * FROM ListBase (_id,Name,LastName,Email,Age)"
//                 "VALUES (:_id,:Name,:LastName,:Email,:Age)");
//   while ( query.next() ) {
//        id=query.value(0).toInt();
//        name =query.value(1).toString();
//        lastN= query.value(2).toString();

//   }
//   qDebug()<<name;
   QObject::connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SlotSavePix(int,int)));
   QObject::connect(ui->pB_QuitSave,SIGNAL(clicked()),SLOT(CloseWindow()));
}

MainWindow_Person::~MainWindow_Person()
{
    delete ui;
}

void MainWindow_Person::on_pushButton_clicked()
{
    ++sizeTable;
    ui->tableWidget->setRowCount(sizeTable);
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    ui->tableWidget->setItem(checkboxCountRow, 4, item );
    ++checkboxCountRow;
    if(!db.open())
    {
        qDebug()<<"ERROR";
    }
    else
    {
        qDebug()<<"OK";
    }
//    db=QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("/Users/macbook/Desktop/Rodion/BaseList.db");
//    QSqlQuery query;
//    if (ui->tableWidget->rowCount()==2)
//    {
//        qDebug()<<"MI TYT";
//        query.prepare("INSERT INTO ListBase (_id,Name,LastName,Email,Age)"
//                      "VALUES (:_id,:Name,:LastName,:Email,:Age)");
//        qDebug()<<ui->tableWidget->rowCount();
//        qDebug()<<ui->tableWidget->columnCount();

//            query.bindValue(":Name",ui->tableWidget->item(ui->tableWidget->rowCount()-1,0)->text());
//            query.bindValue(":LastName",ui->tableWidget->item(ui->tableWidget->rowCount()-1,1)->text());
//            query.bindValue(":Email",ui->tableWidget->item(ui->tableWidget->rowCount()-1,2)->text());
//            query.bindValue(":Age",ui->tableWidget->item(ui->tableWidget->rowCount()-1,3)->text().toInt());
//        query.exec();
//    }
//    else
//    {
//        query.prepare("UPDATE FROM ListBase SET (_id,Name,LastName,Email,Age)"
//                      "VALUES (:_id,:Name,:LastName,:Email,:Age)");
//        qDebug()<<ui->tableWidget->rowCount();
//            for (int row=1;row<ui->tableWidget->rowCount();++row)
//            {
//                query.bindValue(":Name",ui->tableWidget->item(row,0)->text());
//                query.bindValue(":LastName",ui->tableWidget->item(row,1)->text());
//                query.bindValue(":Email",ui->tableWidget->item(row,2)->text());
//                query.bindValue(":Age",ui->tableWidget->item(row,3)->text().toInt());
//            }
//        query.exec();
//    }


}

void MainWindow_Person::on_pushButton_2_clicked()
{
    if (sizeTable>0)
    {
        --checkboxCountRow;
        --sizeTable;
        ui->tableWidget->removeRow(sizeTable);
    }
}


void MainWindow_Person::SlotSavePix(int row, int column)
{
    if (column==5)
    {
        QString str=QFileDialog::getOpenFileName(this);
        QPixmap pix(str);
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        newItem->setData(Qt::DecorationRole, pix.scaled(25,25,Qt::KeepAspectRatio));
        ui->tableWidget->setItem(row, column, newItem);
        ui->tableWidget->item(row,column)->setTextAlignment(Qt::AlignCenter);
    }

}
void MainWindow_Person::CloseWindow()
{
   this->close();
}



