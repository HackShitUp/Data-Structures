//
//  Event.hpp
//  Mini-Project-3
//
//  Created by Joshua Choi on 4/12/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

/**
 MARK: - EventType
 Enum used to delegate whether an Event object's type indicates an arrival or departure
 */
enum EventType {
    arrival,
    departure
};



/**
 Abstract: Custom object used to delegate the priority queue of a given Event
 */
class Event {
public:
    // MARK: - Class Vars
    
    // MARK: - EventType
    EventType type  = arrival;
    /// Initialized Int value used to store the time of the event.
    int time = 0;
    /// Initialized Int value used to store the transaction time of the event.
    int transaction = 0;
    
    // MARK: - Init
    Event(EventType type, int time, int transaction);
};

#endif /* Event_hpp */
