//
//  Event.cpp
//  Mini-Project-3
//
//  Created by Joshua Choi on 4/12/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include "Event.hpp"

/// MARK: - Init
/// \param type An EventType enum.
/// \param time An Int value representing the time of the event.
/// \param transaction An Int value representing the transaction of the event.
Event::Event (EventType type, int time, int transaction) {
    // Set the EventType enum
    this->type = type;
    // Set the time
    this->time = time;
    // Set the transaction time
    this->transaction = transaction;
};

