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
    //Deleting stuff from the tempstack at the end of the exicution
    while(!tempStack.empty()){
        delete tempStack.top();
        tempStack.pop();
    }

};
//This function's parameter would be given by Resource file(a vector)
//Then we would initilize a iterator which would go over the vector and display resouces
void ReservationManager::viewResources(const vector<Resource > ResourceVector)const{
    vector<Resource>::iterator it;

    for(it = ResourceVector.begin(); it!= ResourceVector.end(); it++){

//Still working on this waiting for the resource 
    }
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

            //need to add the checker if the resource is avaible

}
void ReservationManager::cancelReservaton(string ResourceID, const Reservation* ReservationList){
    


}



