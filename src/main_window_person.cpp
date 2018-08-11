#include "mainwindow_person.h"
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
//   modal=new QSqlQueryModel();
//   QSqlDatabase db;
//   db=QSqlDatabase::addDatabase("QSQLITE");
//   db.setDatabaseName("/Users/macbook/Desktop/Rodion/BaseList.db");
//   db.open();
//   QSqlQuery* qry=new QSqlQuery(db);
//   qry->prepare("select * from mainwindow_person");
//   qry->exec();
//   modal->setQuery(*qry);

//   db.close();


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

//lbLabel->setLink("action:start", "текст ссылки");



         ++checkboxCountRow;


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
   QSqlDatabase db;
   db=QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("/Users/macbook/Desktop/Rodion/BaseList.db");
   if(!db.open())
   {
       qDebug()<<"ERROR";
   }
   else
   {
       qDebug()<<"OK";
   }
   QSqlQuery query;
   query.prepare("INSERT INTO ListBase (_id,Name,LastName,Email,Age)"
                 "VALUES (:_id,:Name,:LastName,:Email,:Age)");

    int rase=0;
       for (int row=0;row<ui->tableWidget->rowCount();++row)
       {

           if(rase==0)
           {
             query.bindValue(":Name",ui->tableWidget->item(row,rase)->text());
             rase++;
           }

           if (rase==1)
           {
               query.bindValue(":LastName",ui->tableWidget->item(row,rase)->text());
                rase++;
           }
           if (rase==2)
           {
                query.bindValue(":Email",ui->tableWidget->item(row,rase)->text());
                rase++;
           }
           if (rase==3)
           {
                query.bindValue(":Age",ui->tableWidget->item(row,rase)->text().toInt());
                rase++;
           }
           rase=0;

       }
       query.exec();
       this->close();
}



void MainWindow_Person::on_tableWidget_cellDoubleClicked(int row, int column)
{

//        QLabel lbl("<A HREF='http://www.example.com'>LINK</A>");
//        lbl.setText(ui->tableWidget->currentItem()->text());
//        lbl.setOpenExternalLinks(true);

}
