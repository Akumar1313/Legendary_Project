#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H
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
        list<Reservation*> currentReservation;
        stack<Reservation*> cancellationStack;
        queue<Reservation*> waitingQueue;
        vector<Resource> resources;

    public:
        ReservationManager();
        ~ReservationManager();

        void viewResources()const;
        void createReservation(int,int,string,string,Date);
        void createReservation();
        void cancelReservaton(int  ReservationID);
        void waitingList()const;
        void undoReservation();
        void searchReservation(int ReservationID)const;
        //void sortResources();
        void generateReport()const;
        void printReservatonInfo(Reservation*)const;
        bool loadResourcesFromFile(string fileName);
        bool loadReservationsFromFile(string fileName);

        void Run();
};

#endif