# Project-1-Campus-Resource-Reservation-System

## Description

This project is a C++ system that lets students reserve campus resources such as study rooms, laptops, calculators, tutoring appointments, and lab equipment. 

The system allows users to: 
-View all available resources
-Create reservations
-Cancel reservations
-Join any wait lists
-Manage any existing reservations

## Features

-Resource Management
-Reservation Management 
-Waiting List Queue
-Reservation Cancellation
-Cancellation History
-Resource Availability

## Data Structures

This project uses several data structures:

- Linked List - stores and manages reservations
- Queue - manages waiting lists
- Stack - stores cancellation history
- Vectors - stores and manages resources

## Files

Project 1-
  data - 
    reservations.txt
    resources.txt
  include - 
    Reservation.h
    Resource.h
    ResourceManager.h
  src - 
    main.cpp
    Reservation.cpp
    ReservationManager.cpp
    Resource.cpp
  README.md

  ## How to compile

Compile: g++ main.cpp Reservation.cpp ReservationManager.cpp Resource.cpp -o main
