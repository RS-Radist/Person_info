#ifndef ADDLINKWINDOW_H
#define ADDLINKWINDOW_H
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>

class AddLinkWindow:public QDialog
{
    Q_OBJECT

private:
    QPushButton *butOk;
    QLineEdit *lineEdit;
    QHBoxLayout *boxL;
public:
    explicit AddLinkWindow(QWidget *parent=nullptr);
};

#endif // ADDLINKWINDOW_H
