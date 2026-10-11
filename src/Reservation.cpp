#include "Reservation.h"
#include <string>

using namespace std;
//Date class implementation!
//This will make sure that a correct date is being inputed
Date::Date():   month(0),
                day(0),
                year(0){}
Date::Date(int month, int day, int year){
    this->month = month;
    this->day = day;
    this->year = year;
}

int Date::get_month()const{
    return month;
}
void Date::set_month(int month){
    this->month = month;
}

int Date::get_day()const{
    return day;
}

void Date::set_day(int day){
    this->day = day;
}

int Date::get_year()const{
    return year;
}
void Date::set_year(int year){
    this->year = year;
}


/*This logic here will determin weather the inputed data is a int type*/
bool Date::isValid()const{
    if(month<1 || month >12){
        return false;
    }
    if(day < 1 || day>31 ){
        return false;
    }
    if(year <1){
        return false;
    }
    return true;
}


//Reservation Class
/* Initializing default constructor and fully parameterized constructor */
Reservation::Reservation() : ReservationID(0),
                             StudentID(0),
                             ResourceID(""),
                             Name("NONE"),
                             ReservationDate(0,0,0){}
                            

Reservation::Reservation(int ReservationID, int StudentID,string ResourceID, string Name,Date ReservationDate)
{
    this->ReservationID = ReservationID;
	this->StudentID = StudentID;
	this->ResourceID = ResourceID;
	this->Name = Name;
    this->ReservationDate = ReservationDate;
}

// Initializing getters and setters here
int Reservation::get_ReservationID() const
{
    return ReservationID;
}

void Reservation::set_ReservationID(int ReservationID)
{
    this->ReservationID = ReservationID;
}

int Reservation::get_StudentID() const
{
    return StudentID;
}

void Reservation::set_StudentID(int StudentID)
{
    this->StudentID = StudentID;
}

string Reservation::get_ResourceID() const
{
    return ResourceID;
}

void Reservation::set_ResourceID(string ResourceID)
{
    this->ResourceID = ResourceID;
}

string Reservation::get_Name() const
{
    return Name;
}

void Reservation::set_Name(string Name)
{
    this->Name = Name;
}

Date Reservation::get_ReservationDate() const
{
    return ReservationDate;
}

void Reservation::set_ReservationDate(Date ReservationDate)
{
    this->ReservationDate = ReservationDate;
}



