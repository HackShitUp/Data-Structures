//
//  EventList.cpp
//  Mini-Project-3
//
//  Created by Joshua Choi on 4/12/19.
//  Copyright © 2019 Nanogram LLC. All rights reserved.
//

#include "EventList.hpp"

/// Boolean operator used to compare between the left hand and right hand Event object's time values (used to determine which of the two events have greater priority). This operator sorts the Event objects in a given EventList's queue by their time values. We define this operator in the EventList class because this is a Top-level (Nonmember) function.
bool operator<(const Event& e1, const Event& e2) {
    return e1.time > e2.time;
}



/// Read the data from a given file and update the 'eventsQueue' queue in the EventList class.
/// \param fileName A string value representing the file's absolute path.
bool EventList::fillQueueFromFileData(string fileName) {
    // Setup the file and attempt to read from it
    ifstream file;
    file.open(fileName);
    
    if (!file) {
        //
        // Invalid File
        //
        cerr << "Unable to open file named " << "\"" << fileName << "\". Please try again.\n";
        file.close();
        return false;
    } else {
        //
        // Valid File - Update the queue
        //

        // Initialized values used to store the data read from the file representing 'a' as an Event's time and 'b' as an Event's transaction.
        int a, b;

        // Set the data, line by line
        while (file >> a >> b) {
            // MARK: - Queue
            eventsQueue.push(Event(arrival, a, b));
        }
        
        file.close();
        return true;
    }
}




/// Simulate the event-driven simulation of a bank having one teller. Read from the data-0, data-1, or data-2 files and update the 'eventsQueue' queue in the EventList class.
void EventList::simulate() {
    
    // MARK: - Queue<Event> (priority copy of eventsQueue)
    priority_queue<Event> eventsQueueCopy = eventsQueue;
    
    /// Initialized Int values used to calculate the arrival, departure, and wait times per person at the bank
    int startTime = 0;
    int dispatchWaitDuration = 0;
    int totalProcessed = 0;
    
    // Loop through the original queue
    while (eventsQueue.empty() == false) {
        // MARK: - Event (top event)
        Event topEvent = eventsQueue.top();
        
        /// Update the Event in the queue for those that are arrivals
        if (topEvent.type == arrival) {
            
            // Calculate the new time of the arrival event
            startTime = max(topEvent.time, startTime);
            dispatchWaitDuration += startTime - topEvent.time;
            startTime += topEvent.transaction;
            
            // Insert the next element
            eventsQueue.push(Event(departure, startTime, 0));
        }
        
        // Log the output of the arrival or departure times
        cout << "Processing " << (topEvent.type == arrival ? "arrival" : "departure") << " at time: " << topEvent.time << endl;
        
        // Remove next element
        eventsQueue.pop();
    }
    
    // Loop through the copy
    while(eventsQueueCopy.empty() == false) {
        // Get the top element in the queue
        Event topEvent = eventsQueueCopy.top();
        
        // MARK: - Event
        if (topEvent.type == arrival) {
            totalProcessed++;
        }
        
        // Remove the next element of the copy
        eventsQueueCopy.pop();
    }
    
    // Log the results
    cout << "\nFinal Statistics:\n"
    << "- Total number of people processed: " << totalProcessed << endl
    << "- Average amount of time spent waiting: "
    << abs((double)dispatchWaitDuration/(double)totalProcessed) << endl << endl;
};
