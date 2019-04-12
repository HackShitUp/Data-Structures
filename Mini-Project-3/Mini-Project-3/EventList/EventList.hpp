//
//  EventList.hpp
//  Mini-Project-3
//
//  Created by Joshua Choi on 4/12/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#ifndef EventList_hpp
#define EventList_hpp
#include <sstream>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include "../Event/Event.hpp"
using namespace std;


/**
 Abstract:
 */
class EventList {
public:
    /// MARK: - Queue<Event>
    /// Queue of Event objects
    priority_queue<Event> eventsQueue;
    
    // MARK: - Class Methods
    bool fillQueueFromFileData(string fileName);
    bool priorityQueueIsSorted();
    void simulate();
};

#endif /* EventList_hpp */
