#ifndef MAINWINDOW_PERSON_H
#define MAINWINDOW_PERSON_H

#include <QMainWindow>
#include <QPixmap>
#include <QTableWidgetItem>
#include <QDebug>
#include <QLabel>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPainter>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class MainWindow_Person;
}

class MainWindow_Person : public QMainWindow
{
    Q_OBJECT
protected:
    enum {Num1=1,Num2=2,Num3=3,Num4=4,Num5=5};
    QSqlQueryModel *modal;
    QPixmap *pix;
    QTableWidgetItem *newItem;
    QSqlDatabase db;
    QString *strImg;
public:
    explicit MainWindow_Person(QWidget *parent = nullptr);
    ~MainWindow_Person();

private slots:
    void on_pushButton_clicked();
    void CloseWindow();
    void on_pushButton_2_clicked();
    void SlotSavePix(int,int);

private:
    Ui::MainWindow_Person *ui;
signals:
    void pixmaChange();
};

#endif // MAINWINDOW_PERSON_H
