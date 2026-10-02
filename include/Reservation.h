#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
using namespace std;

class Reservation
{
private:
    // All the required data members for the reservation!
    string ReservationID;
    string StudentID;
    string ResourceID;
    string Name;
    string ReservationDate;

public:
    Reservation();                              // Default constructor
    Reservation(string ReservationID, string StudentID, string ResourceID, string Name,string ReservationDate); // fully parametrized construtor
    //~Reservation();

    // Here we have the getters and setters for all the data members!
    string get_ReservationID() const;
    void set_ReservationID(string);

    string get_StudentID() const;
    void set_StudentID(string);

    string get_ResourceID() const;
    void set_ResourceID(string);

    string get_Name() const;
    void set_Name(string);

    string get_ReservationDate() const;
    void set_ReservationDate(string);
};
#endif