#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QString>
#include <QComboBox>
#include <QDialog>
#include <QCalendarWidget>
#include <QLabel>

class Window : public QDialog
{
    Q_OBJECT
public:
    QPushButton* but_Add;
    QLineEdit* linkEdit;
    QVBoxLayout* layout;


public:
    explicit Window(QWidget *parent = nullptr);

};

#endif // WINDOW_H
