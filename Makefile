CXX = g++
CXXFLAGS = -Wall -std=c++17 -Iinclude

main: src/main.cpp src/Resource.cpp src/Reservation.cpp src/ReservationManager.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp src/Resource.cpp src/Reservation.cpp src/ReservationManager.cpp -o main

clean:
	rm -f main