#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int ReservationCounter = 0; // Keeps track of the number of active reservations

// vector<Resource> resources;
ReservationManager::ReservationManager() {}; // Default constructor

// DESTRUCTOR
ReservationManager::~ReservationManager()
{
    /*Here we are deleting Dma initilized stuff Linkedlist data, Stack data, and Waiting Queue data*/
    for (auto ptr : currentReservation)
    {
        delete ptr; // Delete
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






/*File reading logic for resource  --- Rodion*/
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






/*File reading logic for Reservation  --Rodion*/

bool ReservationManager::loadReservationsFromFile(string fileName)
{
    ifstream fin2;
    fin2.open(fileName);

    if (fin2.fail())
    {
        cout << "File error" << endl;
        return false;
    }

    string ReservationID, StudentID;
    string Name, ResourceID, dateStr;

    //Pipe formation here "|"
    while (getline(fin2, ReservationID, '|'))
    {
        getline(fin2, StudentID, '|'); // Read student ID as string
        getline(fin2, Name, '|');
        getline(fin2, ResourceID, '|');
        getline(fin2, dateStr);           // Read date until newline

        int reservationID = stoi(ReservationID);
        int studentID = stoi(StudentID);

        //using stringstram to phrase date
        stringstream dateStream(dateStr);
        int month, day, year;
        char slash1, slash2;
        dateStream >> month >> slash1 >> day >> slash2 >> year;

        Date ReservationDate(month, day, year);

       // Call createReservation with matching types
        createReservation(reservationID, studentID, ResourceID, Name, ReservationDate);
    }

    fin2.close();
    return true;
}







/*Just a basic print function which will accept a pointer object in it's parameter
and then would print out the reservation Information for that object --Arumit*/
void ReservationManager::printReservatonInfo(Reservation *tempreservationptr) const
{
    Date printdate = tempreservationptr->get_ReservationDate();

    cout << "Name is : " << tempreservationptr->get_Name()<<endl
         << "Reservation Data is : " << printdate.get_month() <<"/"<<printdate.get_day()<<"/"<<printdate.get_year()<<endl
         << "Reservation ID is : " << tempreservationptr->get_ReservationID()<<endl
         << "Resource ID is : " << tempreservationptr->get_ResourceID()<<endl
         << "Student ID is : " << tempreservationptr->get_StudentID() << endl;
}







/*This function shows all the Resources that this reservation system offers
it shows resources off all status either available or unavailable --Rodion*/
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
            cout<<"\n";
        }
        cout << endl;
    }
}







/*
This is the key function:
First, we iterate over the currentReservation linked list to check whether the Reservation ID already exists and prevent duplicate reservations, then
we iterate over the Resources vector to make sure the userEntred Resource ID is valid!
If the Resource ID is found, we create a new Reservation object using DMA
then, we check the resources availability status. Base on that If the resource is available, we add the reservation pointer to the currentReservation linked lisk and mark the resrouce unaviable in the linked list
If the resource is unavailable we will be adding the reservation pointer to the waitingQueue.
If the Resource ID is not found after checking the entire Resources vector we display an error message!.
--Arumit
*/
void ReservationManager::createReservation(int ReservationID, int StudentID, string ResourceID, string Name, Date ReservationDate)
{

    // Check for duplicate reservationID here
    for (auto ptr : currentReservation)
    {
        if (ptr->get_ReservationID() == ReservationID)
        {
            cout << "Can't add duplicate Reservations ID; please try again!" << endl;
            return;
        }
    }

    //if the resource matches then check for availiblity status and based on that either add
    //to the linked list or waiting queue!
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i].getResourceID() == ResourceID)
        {
            Reservation *reservptr = new Reservation(
                ReservationID,
                StudentID,
                ResourceID,
                Name,
                ReservationDate);

            if (resources[i].getAvailabilityStatus() == "Available")
            {
                currentReservation.push_back(reservptr);
                resources[i].setAvailabilityStatus("Unavailable");
                ReservationCounter++;
            }
            else
            {
                waitingQueue.push(reservptr);
            }
            return;
        }
    }
    // if resrouce ID was not found after checking the wole vector
    cout << "Invalid Resource ID!; please try again!" << endl;
}







/*This is the same function as Create Reservation but this one is for user inputs
so this would actually ask user for inputs one by one and then send those inputed data to the create Reservation function
*/

void ReservationManager::createReservation()
{
    int ReservationID;
    int StudentID;
    string ResourceID;
    string Name;
    string dateSrt;

    cout << "Enter Reservation ID : ";
    cin>>ReservationID;
    cin.ignore();

    cout << "Student ID : ";
    cin>>StudentID;
    cin.ignore();

    cout << "Resource ID : ";
    getline(cin, ResourceID);

    cout << "Name : ";
    getline(cin, Name);

    //Here we will make sure that the date correct!
    cout << "Reservation Date (MM/DD/YYYY): ";
    getline(cin, dateSrt);

    // Convert the date string into month, day, and year
    stringstream dateStream(dateSrt);
    int month, day, year;
    char slash1, slash2;

    if (!(dateStream >> month >> slash1 >> day >> slash2 >> year) ||
        slash1 != '/' || slash2 != '/')
    {
        cout << "Invalid date format please enter the data in ---->> MM/DD/YYYY  <--- format; Thank you!" << endl;
        return;
    }

    // Reject any extra chars after year!
    char extra;
    if (dateStream >> extra)
    {
        cout << "Invalid date format, please use --> MM/DD/YYYY <-- format" << endl;
        return;
    }

    //Create a date object with integer inputs!
    Date ReservationDate(month, day, year);

    //if the inputed date is not valid based on the isValid function!
    if (!ReservationDate.isValid())
    {
        cout << "The inputed Date was invalid plesae enter a valid date!" << endl;
        return;
    }
    
    //Send all this info to the CreateReservation funciton to further inspection
    createReservation(ReservationID, StudentID, ResourceID, Name, ReservationDate);
    cout<<"Reservation created successfully!"<<endl;
}   





/*
Here I create an object holder called cancelNode which will hold the pointer
to the reservation that the user wants to cancel.
If the reservation is successfully found, we save that reservation pointer to
cancelNode and break out of the loop.
Then we push that pointer to the cancellation stack and remove it
from the original linked list.
Next, we check the waiting queue to see if any student is waiting for the
resource that was just freed. We use a temporary queue to hold the other
waiting reservations while we search for a match.
If a waiting student needs the freed resource, we move their reservation
to the currentReservation linked list and update the ReservationCounter.
Finally, we will store the cancelation stack data back to what it was!
--Arumit
*/
void ReservationManager::cancelReservaton(int ReservationID)
{

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
    ReservationCounter--;

    queue<Reservation *> tempqueue;
    bool foundWaiting = false; // tracks if the freed reservation has been claimed yet or not!
    while (!waitingQueue.empty())
    {
        Reservation *frontStudent = waitingQueue.front();// holds the top Reservation in the stack
        waitingQueue.pop();

        if (frontStudent->get_ResourceID() == cancelNode->get_ResourceID() && foundWaiting == false)
        {
            currentReservation.push_back(frontStudent);
            ReservationCounter++;
            foundWaiting = true;
            cout << "Resource automatically given to waiting student : " << frontStudent->get_Name() << endl;
        }
        else
        {
            tempqueue.push(frontStudent);
        }
    }
    while (!tempqueue.empty())
    {
        waitingQueue.push(tempqueue.front());
        tempqueue.pop();
    }

    // if no one in waiting queue want the freed resource then mark that resouce back to Available
    if (foundWaiting == false)
    {
        for (int i = 0; i < resources.size(); i++)
        {
            if (resources[i].getResourceID() == cancelNode->get_ResourceID())
            {
                resources[i].setAvailabilityStatus("Available");
                break;
            }
        }
    }
}







/*Here I've created a temp queue;
 so we would not loose the origianl data in the waiting queue
 we are only displaying the Name and ResourceId which the students are waiting for! */
void ReservationManager::waitingList() const
{
    cout << "Displaying the Waiting list for the Reservations" << endl;
    queue<Reservation *> tempqueue = waitingQueue;
    cout << "Displaying Waiting list!" << endl;
    int countwaitinglist = 1;
    while (!tempqueue.empty())
    {

        cout <<countwaitinglist<< ". "<<  tempqueue.front()->get_Name() << " is wating for : " << tempqueue.front()->get_ResourceID() << endl;
        tempqueue.pop();
        countwaitinglist++;

    }
}






/*This fucntion first makes sure that cancellation stack is not empty!
then creates temp pointer which hold the top Reservation of the cancellation stack and pops that cancelation from the stack
then we iterate over the resource vector to make get the index of that particular resource;
so we could check if it is currently available or unavailable; and based on the availibality we either add
that to the cancellation stack or waiting queue - Arumit*/
void ReservationManager::undoReservation()
{
    if (cancellationStack.empty())
    {
        cout << "Cancellation Stack is empty. Cannot restore." << endl;
        return;
    }

    // getting the top reservation from the cancelled reservation stack
    Reservation *restoreNode = cancellationStack.top();
    cancellationStack.pop();

    // checking if the Resource we want to restore is available;
    int restoreidx = -1;
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i].getResourceID() == restoreNode->get_ResourceID())
        {
            restoreidx = i;
            break;
        }
    }

    if (restoreidx != -1 && resources[restoreidx].getAvailabilityStatus() == "Available")
    {
        currentReservation.push_back(restoreNode);
        resources[restoreidx].setAvailabilityStatus("Unavailable");
        ReservationCounter++;
        cout << "Reservation Restored Successfully!" << endl;
    }
    else
    {
        waitingQueue.push(restoreNode);
        cout << "Resource is currently occupied. Restored Reservation request placed in waiting queue!" << endl;
    }
}







/* Here I'm using Linear Search to find the requested ID by the user
We would iterate over the whole linked list and if the Reservation ID matches with the one we are looking for
we would send that objects pointer to the print Function! -Arumit*/
void ReservationManager::searchReservation(int ReservationID) const
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





//void ReservationManager::sortResources();--Rodions 

//This was supposed to be vicks function
void ReservationManager::generateReport() const
{
    // make sure to add a adder to the know how many active reservations we have!

    cout << "Total reservations in the system are : " << ReservationCounter << endl;
}

void ReservationManager::Run()
{
    int choice;
    int ReservationID;

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
            cin>>ReservationID;
            cancelReservaton(ReservationID);
            break;

        case 4:
            waitingList();
            break;

        case 5:
            undoReservation();
            break;

        case 6:
            cout << "Enter the Reservation ID : ";
            cin>>ReservationID;
            searchReservation(ReservationID);
            break;

        case 7:
            // sortResources();
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
