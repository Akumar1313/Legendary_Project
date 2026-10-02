#include "ReservationManager.h"
#include "Reservation.h"
#include "Resource.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>;
using namespace std;

vector<Resource> resources;
ReservationManager::ReservationManager() {}; // Default constructor

// DESTRUCTOR
ReservationManager::~ReservationManager()
{
    /*Here we are deleting Dma initilized stuff Linkedlist data, Stack data, and Waiting Queue data*/
    for (auto ptr : currentReservation)
    {
        delete ptr;
    }
    while (!cancellationStack.empty())
    {
        delete cancellationStack.top();
        cancellationStack.pop();
    }
    while (!waitingQueue.empty())
    {
        delete waitingQueue.front();
        waitingQueue.pop();
    }
};
/*File reading logic for resource and */
bool ReservationManager::loadResourcesFromFile(string fileName)
{
    ifstream fin1;
	fin1.open(fileName);
	
	if (fin1.fail())
	{
		cout << "File error" << endl;
		return false; // error of file-reading
	}

	string id, name, type, status;
	while (getline(fin1, id, '|'))
	{
		getline(fin1, name, '|'); // reads until '|' excluding this character
		getline(fin1, type, '|');
		getline(fin1, status); // read until enter/space
		
		Resource resource(id, name, type, status);
		resources.push_back(resource);
	}
	
	// close resources
	fin1.close();
	// successful reading
	return true;
}
/*File reading logic for Reservation and */

bool ReservationManager::loadReservationsFromFile(string fileName)
{
    ifstream fin2;
	fin2.open(fileName);
	
	if (fin2.fail())
	{
		cout << "File error" << endl;
		return false; // error of file-reading
	}

	string ReservationID, StudentID;
    string Name, ResourceID, ReservationDate;
	while (getline(fin2, ReservationID, '|'))
	{
		getline(fin2, StudentID, '|'); // reads until '|' excluding this character
		getline(fin2, Name, '|');
        getline(fin2, ResourceID, '|');
		getline(fin2, ReservationDate); // read until enter/space
		
		//Reservation reservation(ReservationID, StudentID, ResourceID, Name, ReservationDate);
        createReservation(ReservationID, StudentID, ResourceID, Name, ReservationDate);
    }
    // close resources
    fin2.close();
    // successful reading
    return true;
}


/*Just a basic print function which will accept a pointer object in it's parameter
and then would print out the reservation Information for that object*/
void ReservationManager::printReservatonInfo(Reservation* tempreservationptr)const
{
    cout << "Name is : " << tempreservationptr->get_Name()
         << "Reservation Data is : " << tempreservationptr->get_ReservationDate()
         << "Reservation ID is : " << tempreservationptr->get_ReservationID()
         << "Resource ID is : " << tempreservationptr->get_ResourceID()
         << "Student ID is : " << tempreservationptr->get_StudentID() << endl;
}

/*This function shows all the Resources that this reservation system offers
it shows resources off all status either available or unavailable*/
void ReservationManager::viewResources() const
{
    {
        cout << "===== Resources Info: =====" << endl;

        for (int i = 0; i < (int)resources.size(); i++)
        {
            cout << "Resource ID: " << resources[i].getResourceID() << endl;
            cout << "Resource Name: " << resources[i].getResourceName() << endl;
            cout << "Resource Type: " << resources[i].getResourceType() << endl;
            cout << "Resource Availability Status: " << resources[i].getAvailabilityStatus() << endl;
        }
        cout << endl;
    }
}

void ReservationManager::createReservation(string ReservationID, string StudentID, string ResourceID, string Name, string ReservationDate)
{
    /*Here we will ask the user first to input all the required
    input; then we will check if the resourceId is available
    base on the status of resourceID we will either push the reservation into the
    ReservationList(linked list) or we could add the reservation info to the waiting queue */


    

    // int ReservationID;
    // int StudentID;
    // string ResourceID;
    // string Name;
    // string ReservationDate;

    // cout << "Enter the Reservation ID : " << endl;
    // cin >> ReservationID;

    // cout << "Enter the Student ID : " << endl;
    // cin >> StudentID;

    // cout << "Enter the Resource ID : " << endl;
    // cin >> ResourceID;

    // cin.ignore();

    // cout << "Enter student Name : " << endl;
    // getline(cin, Name);

    // cout << "Enter the Reservation Date : " << endl;
    // getline(cin, ReservationDate);

    /*this is logic which determins if the reservation is added to the linked list or queue*/
    Reservation* reservptr;
    bool resourceFound = false;
    
    for (int i = 0; i < (int)resources.size(); i++)
    {
        if (resources[i].getResourceID() == ResourceID)
        {
            /*creating a Reservation class pointer; and using DMA to store the info*/
            reservptr = new Reservation(ReservationID,
                                        StudentID,
                                        ResourceID,
                                        Name,
                                        ReservationDate);
            resourceFound = true;
            if (resources[i].getAvailabilityStatus() == "Available")
            {
                currentReservation.push_back(reservptr);
                cout << "Reservation sucessfully made!";
            }
            else
            {
                cout << "Resource ID : " << ResourceID
                     << "is currently unavailable!. Putting your request in a wating queue!" << endl;
                waitingQueue.push(reservptr);
            }
            break;
        }
    }
    if (!resourceFound)
    {
        cout << "Requested Resource was not available or invalid!" << endl;
    }
}


void ReservationManager::cancelReservaton(string ReservationID)
{
    /*Here I create a object holder cancelNode which would hold the data for
    the Reservatio ID which the user wants to cancel.
    and if the reservation they would like to cancel is
    succesfully found we would save that reservation node to the cancelNode and break out of the loop.
    Then push that copyed node to the cancellation stack then remove it from the original linked list!*/
    Reservation *cancelNode = NULL;

    for (auto ptr : currentReservation)
    {
        if (ptr->get_ReservationID() == ReservationID)
        {
            cout << "Reservation Found canceling user....." << endl;
            cancelNode = ptr;
            break;
        }
    }
    if (cancelNode == NULL)
    {
        cout << "Reservation Not found... Please try again!" << endl;
        return;
    }

    cancellationStack.push(cancelNode);
    currentReservation.remove(cancelNode);
}

/*Here I've created a temp queue;
 so we would not loose the origianl data in the waiting queue
 we are only displaying the Name and ResourceId which the students are waiting for! */
void ReservationManager::waitingList() const
{
    cout << "Displaying the Waiting list for the Reservations" << endl;
    queue<Reservation *> tempqueue = waitingQueue;

    while (!tempqueue.empty())
    {
        cout << "Displaying Waiting list!" << endl;
        cout << tempqueue.front()->get_Name() << " is wating for : " << tempqueue.front()->get_ResourceID() << endl;
        tempqueue.pop();
    }
}

void ReservationManager::undoReservation(string ReservationID)
{
    /*For the undo function, We first create a temp stack which we can use to iterator over
    and find the requestion ReservationNumber and not loose the original data in the cancellation stack,
     also create a temp Reservation class pointer
    to store the reservation which holds the requestion Reservation ID
    if the reservation is found successfully then we would push_back that into the Reservatio Linkedlist
    */
    stack<Reservation *> tempstack = cancellationStack;
    Reservation *undoptr;
    bool reservationFound = false;
    while (!tempstack.empty())
    {
        undoptr = tempstack.top();
        if (undoptr->get_ReservationID() == ReservationID)
        {
            reservationFound = true;
            cout << "Resrevation found... Restoring Reservation..." << endl;
            currentReservation.push_back(undoptr);
            break;
        }
        tempstack.pop();
    }

    /*If the reservation actually exist then do the original stack object removal process else just print the
    message that Reservation Don't exist!*/
    if (reservationFound)
    {
        /*Clearing whole temp stack here; so I could use it again to get rid of
        reservation which got cancled and pop that reservation from the original cancellationStack*/
        while (!tempstack.empty())
        {
            tempstack.pop();
        }

        /*Here im going to iterate the whole cancellationStack and find for that
        specific reservationId to pop it out if the stack; if the reservation is not found, we would
        keep in iterating and poping the cancellation stack data to push into tempstack, so we don't loose
        the required data for the original temp stack*/
        while (!cancellationStack.empty())
        {
            if (cancellationStack.top()->get_ReservationID() == ReservationID)
            {
                cancellationStack.pop();
                break;
            }
            else
            {
                tempstack.push(cancellationStack.top());
                cancellationStack.pop();
            }
        }
        /*When we have succesfully poped the reservation from the original cancellation stack
        we would then copy the stored data from tempstack to cancellationstack*/
        while (!tempstack.empty())
        {
            cancellationStack.push(tempstack.top());
            tempstack.pop();
        }
    }
    else
    {
        cout << "Reservation is either invalid or doesn't exist in the system!" << endl;
    }
}

/* Here I'm using Linear Search to find the requested ID by the user
We would iterate over the whole linked list and if the Reservation ID matches with the one we are looking for
we would send that objects pointer to the object!*/
void ReservationManager::searchReservation(string ReservationID) const
{
    cout << "Serching for Reservation : " << ReservationID << "..." << endl;
    for (auto ptr : currentReservation)
    {
        if (ptr->get_ReservationID() == ReservationID)
        {
            printReservatonInfo(ptr);
            return;
        }
    }
    /*If the reservation is invaild or doesn't exist We would print this message!*/
    cout << "Reservation : " << ReservationID
         << " is not in the system" << endl;
}

void ReservationManager::generateReport() const
{
    // make sure to add a adder to the know how many active reservations we have!
}

void ReservationManager::Run()
{
    int choice;
    string ReservationID;

    do
    {
        cout << "===== Campus Resource Reservation System =====" << endl;
        cout << "1. View Resources" << endl;
        cout << "2. Create Reservation" << endl;
        cout << "3. Cancel Reservation" << endl;
        cout << "4. View Waiting Lists" << endl;
        cout << "5. Undo Cancellation" << endl;
        cout << "6. Search Reservations" << endl;
        cout << "7. Sort Resources" << endl;
        cout << "8. Generate Report" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            viewResources();
            break;

        case 2:
            createReservation();
            break;

        case 3:
            cout << "Enter the Reservation ID : ";
            getline(cin, ReservationID);
            cancelReservaton(ReservationID);
            break;

        case 4:
            waitingList();
            break;

        case 5:
            cout << "Enter the Reservation ID : ";
            getline(cin, ReservationID);
            undoReservation(ReservationID);
            break;

        case 6:
            cout << "Enter the Reservation ID : ";
            getline(cin, ReservationID);
            searchReservation(ReservationID);
            break;

        case 7:
            sortResources();
            break;

        case 8:
            generateReport();
            break;

        case 9:
            cout << "Exiting Program .... Thank you for Using!" << endl;
            break;

        default:
            cout << "Invalid Choice. Please Try again!" << endl;
        }

    } while (choice != 9);
}
