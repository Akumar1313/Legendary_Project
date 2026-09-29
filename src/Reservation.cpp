#include "Reservation.h"
#include <string>

using namespace std;

/* Initializing default constructor and fully parameterized constructor */
Reservation::Reservation() : ReservationID(0),
                             StudentID(0),
                             ResourceID(""),
                             Name("NONE"),
                             ReservationDate("0/0/00") {}

Reservation::Reservation(int ReservationID, int StudentID, string ResourceID, string Name, string ReservationDate) : ReservationID(ReservationID),
                                                                                                                     StudentID(StudentID),
                                                                                                                     ResourceID(ResourceID),
                                                                                                                     Name(Name),
                                                                                                                     ReservationDate(ReservationDate) {}

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

string Reservation::get_ReservationDate() const
{
    return ReservationDate;
}

void Reservation::set_ReservationDate(string ReservationDate)
{
    this->ReservationDate = ReservationDate;
}