#include "person.h"

Person::Person()
{

}

void Person::SetName(QString name)
{
    this->name=name;
}

void Person::SetlastName(QString lastName)
{
    this->lastName=lastName;
}

void Person::SetEmail(QString email)
{
    this->email=email;
}

void Person::SetYear(int year)
{
    this->year=year;
}

QString Person::GetName()
{
    return this->name;
}

QString Person::GetLastName()
{
    return this->lastName;
}

QString Person::GetEmail()
{
    return this->email;
}

int Person::GetYear()
{
    return this->year;
}

