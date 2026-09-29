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

    public:
        ReservationManager();
        ~ReservationManager();
        

            Reservation * reservptr;
            list<Reservation*> currentReservation;
            stack<Reservation*> cancellationStack;
            queue<Reservation*> waitingQueue;
            vector<Resource> resources;

                void viewResources()const;
                void createReservation();
                void cancelReservaton(int  ReservationID);
                void waitingList()const;
                void undoReservation(int ResrvationID);
                void searchReservation(int ReservationID)const;
                void sortResources();
                void generateReport()const;

                void Run();
};

#endif