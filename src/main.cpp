#include "ReservationManager.h"

int main(){
    ReservationManager manager;
    manager.loadResourcesFromFile("data/resources.txt");
    manager.loadReservationsFromFile("data/reservations.txt");
    
    manager.Run();

    return 0;
}