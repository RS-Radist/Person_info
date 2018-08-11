#include "window.h"

Window::Window(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("Window");
    but_Add=new QPushButton("OK",this);
    linkEdit=new QLineEdit("Email");

    layout=new QVBoxLayout(this);

    layout->addWidget(linkEdit);

    layout->addWidget(but_Add);
    this->setLayout(layout);
    QObject::connect(but_Add,SIGNAL(clicked()),this,SLOT(close()));



}



