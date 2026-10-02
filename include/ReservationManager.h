#ifndef RESERVATIONMANAGER.H
#define RESERVATIONMANAGER.H
#include <stack>
#include <list>
#include <string>
#include <vector>
#include <queue>
#include "Resource.h"
#include "Reservation.h"
using namespace std;

class ReservationManager{
    private:
        Reservation * reservptr;
        list<Reservation*> currentReservation;
        stack<Reservation*> cancellationStack;
        queue<Reservation*> waitingQueue;

    public:
        ReservationManager();
        ~ReservationManager();

        void viewResources()const;
        void createReservation(string,string,string,string,string);
        void cancelReservaton(string  ReservationID);
        void waitingList()const;
        void undoReservation(string ResrvationID);
        void searchReservation(string ReservationID)const;
        void sortResources();
        void generateReport()const;
        void printReservatonInfo(Reservation*)const;
        bool loadResourcesFromFile(string fileName);
        bool loadReservationsFromFile(string fileName);

        void Run();
};

#endif