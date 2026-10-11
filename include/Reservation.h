#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
using namespace std;

/*To make sure that the user would enter a valid data
I've created a seprate class for data which would 
make sure the correct data is being entred*/
class Date{
    private:
        int month;
        int day;
        int year;

    public:
        Date();
        Date(int, int, int);

        int get_month()const;
        void set_month(int);

        int get_day()const;
        void set_day(int);

        int get_year()const;
        void set_year(int);
        bool isValid()const;
};


class Reservation
{
private:
    // All the required data members for the reservation!
    int ReservationID;
    int StudentID;
    string ResourceID;
    string Name;
    Date ReservationDate;

public:
    Reservation();                              // Default constructor
    Reservation(int ReservationID, int StudentID, string ResourceID, string Name, Date ReservationDate); // fully parametrized construtor
    //~Reservation();

    // Here we have the getters and setters for all the data members!
    int get_ReservationID() const;
    void set_ReservationID(int);

    int get_StudentID() const;
    void set_StudentID(int);

    string get_ResourceID() const;
    void set_ResourceID(string);

    string get_Name() const;
    void set_Name(string);

    Date get_ReservationDate() const;
    void set_ReservationDate(Date);
};


#endif