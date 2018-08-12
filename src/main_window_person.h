#ifndef MAINWINDOW_PERSON_H
#define MAINWINDOW_PERSON_H

#include <QMainWindow>
#include <QPixmap>
#include <QTableWidgetItem>
#include <QSqlQueryModel>
namespace Ui {
class MainWindow_Person;
}

class MainWindow_Person : public QMainWindow
{
    Q_OBJECT
private:
    int sizeTable;
protected:
    QSqlQueryModel *modal;
    QPixmap *pix;
    int checkboxCountRow;
    QTableWidgetItem *newItem;
    QSqlDatabase db;
public:
    explicit MainWindow_Person(QWidget *parent = 0);
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
