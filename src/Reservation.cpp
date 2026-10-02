#include "Reservation.h"
#include <string>

using namespace std;

/* Initializing default constructor and fully parameterized constructor */
Reservation::Reservation() : ReservationID(""),
                             StudentID(""),
                             ResourceID(""),
                             Name("NONE"),
                             ReservationDate("0/0/00") {}

Reservation::Reservation(string ReservationID, string StudentID,string ResourceID, string Name,string ReservationDate)
{
    this->ReservationID = ReservationID;
	this->StudentID = StudentID;
	this->ResourceID = ResourceID;
	this->Name = Name;
    this->ReservationDate = ReservationDate;
}

// Initializing getters and setters here
string Reservation::get_ReservationID() const
{
    return ReservationID;
}

void Reservation::set_ReservationID(string ReservationID)
{
    this->ReservationID = ReservationID;
}

string Reservation::get_StudentID() const
{
    return StudentID;
}

void Reservation::set_StudentID(string StudentID)
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

string Reservation::get_ReservationDate() const
{
    return ReservationDate;
}

void Reservation::set_ReservationDate(string ReservationDate)
{
    this->ReservationDate = ReservationDate;
}