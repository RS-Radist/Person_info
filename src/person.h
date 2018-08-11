#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
private:
    QString name;
    QString lastName;
    QString email;
    int year;
public:
    Person();

 //Setter
    void SetName(QString name);
    void SetlastName(QString lastName);
    void SetEmail(QString email);
    void SetYear(int year);
 //Getter
    QString GetName();
    QString GetLastName();
    QString GetEmail();
    int GetYear();

};

#endif // PERSON_H
