#include "addlinkwindow.h"

AddLinkWindow::AddLinkWindow(QWidget* parent):QDialog(parent)
{
    butOk=new QPushButton("OK",this);
    lineEdit=new QLineEdit(this);

}
