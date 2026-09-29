#include "ReservationManager.h"
#include "Reservation.h"
#include "Resource.h"
#include <iostream>
using namespace std;

ReservationManager::ReservationManager(){};
ReservationManager::~ReservationManager(){
    for(auto ptr : currentReservation){//Deleting DMA for linked list!!! here 
        delete ptr;
    }
    //Deleting stuff from the cancellation stack at the end of exicution
    while(!cancellationStack.empty()){
        delete cancellationStack.top();
        cancellationStack.pop();
    }
    while(!waitingQueue.empty()){
        delete waitingQueue.front();
        waitingQueue.pop();
    }

};
//This function's parameter would be given by Resource file(a vector)
//Then we would initilize a iterator which would go over the vector and display resouces
void ReservationManager::viewResources()const{
    vector<Resource>::iterator it;

    for(it = resources.begin(); it != resources.end(); it++){
            cout<<""
    }
        //Still working on this need to discuss stuff with rodion

    }


void ReservationManager::createReservation(){
            int ReservationID;
            int StudentID;
            string ResourceID;
            string Name;
            string ReservationDate;

            cout << "Enter the Reservation ID : " << endl;
            cin >> ReservationID;

            cout << "Enter the Student ID : " << endl;
            cin >> StudentID;

            cout << "Enter the Resource ID : " << endl;
            cin >> ResourceID;

            cin.ignore();

            cout << "Enter student Name : " << endl;
            getline(cin, Name);

            cout << "Enter the Reservation Date : " << endl;
            getline(cin, ReservationDate);


            reservptr = new Reservation     (ReservationID,
                                              StudentID,
                                              ResourceID,
                                              Name,
                                              ReservationDate);
            currentReservation.push_back(reservptr);

            

}
void ReservationManager::cancelReservaton(int ReservationID){
    /*Here I create a object holder cancelNode which would hold the data for 
    the Reservatio ID which the user wants to cancel.
    and if succesfully found we would save that reservation node to the cancelNode and break out of the loop.
    Then push that copyed node to the cancellation stack then remove it from the original linked list!*/
    Reservation* cancelNode = NULL;
    
        for(auto ptr: currentReservation){
            if(ptr->get_ReservationID() == ReservationID){
                cout<<"Reservation Found canceling user....."<<endl;
                cancelNode = ptr;
                break;
            }
        }
        if(cancelNode == NULL){
            cout<<"Reservation Not found... Please try again!"<<endl;
            return;
        }

    cancellationStack.push(cancelNode);
    currentReservation.remove(cancelNode);

}

void ReservationManager::waitingList()const
{
    cout<<"Displaying the Waiting list for the Reservations"<<endl;
    queue<Reservation *> tempqueue = waitingQueue;

    while(!tempqueue.empty()){
        cout<<"Displaying Waiting list!"<<endl;
        //need a print function which can take and print info
    }
}
void ReservationManager::undoReservation(int ReservationID){
    /*For the undo function, We first create a temp stack which we can use to iterator over
    and find the requestion ReservationNumber; also create a temp Reservation class pointer 
    to store the reservation which holds the requestion Reservation ID
    if the reservation is found successfully then we would push_back that into the Reservatio Linkedlist
    */
    stack<Reservation*>tempstack = cancellationStack;
    Reservation* undoptr;
    while(!tempstack.empty()){
        undoptr = tempstack.top();
            if(undoptr->get_ReservationID() == ReservationID){
                cout<<"Resrevation found... Restoring Reservation..."<<endl;
                break;
            }
    }
    currentReservation.push_back(undoptr);
}

void ReservationManager::searchReservation(int ReservationID)const{
    /*Using Binary search overall; sinec the data will not be sorted, we will first sort the 
    data based on ReservationIDs then I would inplement Binary serach*/
    //Use one of the algo to sort the data first then do binary search
}

void 


