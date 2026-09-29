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
            stack<Reservation*> tempStack;
            queue<Reservation*> waitingQueue;

                void viewResources(const vector<Resource > ResourceVector)const;
                void createReservation();
                void cancelReservaton(string ResourceID, const Reservation* ReservationList);
                void waitingList(const Reservation* waitingqueue)const;
                void undoReservation(const Reservation* ReservationList, const Reservation* cancellationStack);
                void searchReservation(int ReservationID)const;
                void sortResources();
                void generateReport()const;

                void Run();
};

#endif