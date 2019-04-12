//
//  main.cpp
//  Mini-Project-3
//
//  Created by Joshua Choi on 4/12/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include "Event/Event.hpp"
#include "EventList/EventList.hpp"

using namespace std;


/**
 Abstract: This program simulates
 - A trace of the arrival or departure events executed, one line per event, and
 - A summary statistics, consisting of the number of customers and the average time spent waiting in line.
 */
int main() {
    
    /// Initialized String value used to get the user's input
    string input = "";

    while(true) {
        // MARK: - Event
        EventList eventList;
        
        /**
         /Users/JoshMChoi/desktop/mini-project-3/mini-project-3/data-0
         */
        cout << "Please enter the name of the file to read data from. Enter \"!Q\" to quit.\nAbsolute path to file: ";
        getline(cin, input);
        
        // Quit the program
        if (input == "!Q") {
            break;
        } else if (eventList.fillQueueFromFileData(input)) {
            // MNARK: - EventList
            eventList.simulate();
        }
    }
    
    return 0;
}
