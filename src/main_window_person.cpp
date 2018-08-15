#include "main_window_person.h"
#include "ui_mainwindow_person.h"



MainWindow_Person::MainWindow_Person(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_Person)
{
   ui->setupUi(this);   
   ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
   ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);// запрещает редактировать несколько ячеек таблицы.

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
     QSqlQuery query("SELECT * FROM ListBase");
     for(int i = 0; query.next(); i++)
     {
            // добавление строк по параметрам

             ui->tableWidget->insertRow(i);
             QTableWidgetItem *item = new QTableWidgetItem();

             item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
             item->setCheckState(Qt::Unchecked);
             ui->tableWidget->setItem(i, 4, item );
             ui->tableWidget->setItem(i, 0, new QTableWidgetItem(query.value(1).toString())); //запись в ячейки
             ui->tableWidget->setItem(i, 1, new QTableWidgetItem(query.value(2).toString()));
             ui->tableWidget->setItem(i, 2, new QTableWidgetItem(query.value(3).toString()));
             ui->tableWidget->setItem(i, 3, new QTableWidgetItem(query.value(4).toString()));
             QTableWidgetItem *itemCheck = new QTableWidgetItem();
             itemCheck->data(Qt::CheckStateRole);
                    /* Проверяем, на статус нечетности, если нечетное устройство, то
                     * выставляем состояние чекбокса в Checked, иначе в Unchecked
                     * */
             if(query.value(5).toInt() == 1) //проверка чебокса
             {
                itemCheck->setCheckState(Qt::Checked);
             }
             else
             {
                itemCheck->setCheckState(Qt::Unchecked);
             }

             ui->tableWidget->setItem(i,4, itemCheck);// Уставновка чекбокса
     }

   QObject::connect(ui->tableWidget,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(SlotSavePix(int,int)));
   QObject::connect(ui->pB_QuitSave,SIGNAL(clicked()),SLOT(CloseWindow()));
}


MainWindow_Person::~MainWindow_Person()
{
    delete ui;
}

void MainWindow_Person::on_pushButton_clicked()
{
    qDebug()<<ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());

    QTableWidgetItem *item = new QTableWidgetItem();
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
    item->setCheckState(Qt::Unchecked);
    ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 4, item );
    QSqlQuery query;
    query.prepare("UPDATE FROM ListBase SET String = ':Name', String = ':LastName',String =':Email',Int = ':Age', Int=':Kids' WHERE ID = :_id");

     for(int i=0;i<ui->tableWidget->rowCount();++i)
     {
        query.bindValue(":Name",ui->tableWidget->item(i,0)->text());
        query.bindValue(":LastName",ui->tableWidget->item(i,1)->text());
        query.bindValue(":Email",ui->tableWidget->item(i,2)->text());
        query.bindValue(":Age",ui->tableWidget->item(i,3)->text().toInt());
        QTableWidgetItem* pItem(ui->tableWidget->item(i, 4));

        if (pItem->checkState())
        {
        qDebug()<<pItem->checkState();              //состояние чекбокса
            query.bindValue(":Kids",1);
        }
        else
        {
            qDebug()<<pItem->checkState();
            query.bindValue(":Kids",0);
        }
     }
     query.exec();
}

void MainWindow_Person::on_pushButton_2_clicked()
{


    if (ui->tableWidget->rowCount()>0)
    {
        ui->tableWidget->removeRow(0);
        QSqlQuery query;
        query.prepare("DELETE FROM `ListBase` WHERE `_id`=TOP"); // удалить не могу первую строку

        query.exec();
    }
    else
    {
        QMessageBox::warning(this,"Ошибка","Удалить нельзя");
    }
    qDebug()<<ui->tableWidget->rowCount();
}

void MainWindow_Person::SlotSavePix(int row, int column)
{
    if (column==Num5)
    {
        strImg= new QString (QFileDialog::getOpenFileName(0));
        QPixmap pix(*strImg);
        QTableWidgetItem *newItem = new QTableWidgetItem("");
        newItem->setData(Qt::DecorationRole, pix.scaled(40,40,Qt::KeepAspectRatio));
        ui->tableWidget->setItem(row, column, newItem);
        ui->tableWidget->item(row,column)->setTextAlignment(Qt::AlignCenter);
        newItem->setTextAlignment(Qt::AlignCenter);
    }

}
void MainWindow_Person::CloseWindow()
{
   this->close();
}



