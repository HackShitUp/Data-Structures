//
//  proj1.cpp
//  Mini-Project-1
//
//  Created by Joshua Choi on 2/14/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <string>
#include "VectorBag.cpp"
using namespace std;

// MARK: - Method Template Definitions
template<class ItemType> void displayBag(VectorBag<ItemType>& bag);
template<class ItemType> void bagTester(VectorBag<ItemType>& bag);
void newOpsTester();

// MARK: - Main
int main() {
    VectorBag<string> bag;
    cout << "Testing the Vector-Based Bag:" << endl;
    cout << "The initial bag is empty." << endl;
    bagTester(bag);
    newOpsTester();
    cout << "All done!" << endl;
    
    return 0;
}

template<class ItemType>
void displayBag(VectorBag<ItemType>& bag) {
    cout << "The bag contains " << bag.getCurrentSize()
    << " items:" << endl;
    vector<ItemType> bagItems = bag.toVector();
    
    int numberOfEntries = static_cast<int>(bagItems.size());
    sort(bagItems.begin(), bagItems.end());
    
    for (int i = 0; i < numberOfEntries; i++)
        cout << bagItems[i] << " ";
    cout << endl << endl;
}


template<class ItemType> void bagTester(VectorBag<ItemType>& bag) {
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 1 (true)" << endl;
    displayBag(bag);
    
    string items[] = {"one", "two", "three", "four", "five", "one"};
    unsigned int itemsSize = sizeof(items)/sizeof(items[0]);
    cout << "Adding " << itemsSize << " items to the bag: " << endl;
    for (unsigned int i = 0; i < itemsSize; i++)
        bag.add(items[i]);
    
    displayBag(bag);
    
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 0 (false)" << endl;
    
    cout << "getCurrentSize: returns " << bag.getCurrentSize()
    << "; should be " << itemsSize << endl;
    
    cout << "Try to add another entry: add(\"extra\") returns "
    << bag.add("extra") << endl;
    
    cout << "contains(\"three\"): returns " << bag.contains("three")
    << "; should be 1 (true)" << endl;
    cout << "contains(\"ten\"): returns " << bag.contains("ten")
    << "; should be 0 (false)" << endl;
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one") << " should be 2" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 1 (true)" << endl;
    cout << "getFrequencyOf(\"one\"): returns "
    << bag.getFrequencyOf("one") << " should be 1" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 1 (true)" << endl;
    cout << "remove(\"one\"): returns " << bag.remove("one")
    << "; should be 0 (false)" << endl;
    cout << endl;
    
    displayBag(bag);
    
    cout << "After clearing the bag, ";
    bag.clear();
    
    cout << "isEmpty: returns " << bag.isEmpty()
    << "; should be 1 (true)" << endl;
}


/**
 Tests new VectorBag operations (union, intersection, difference)
 */
void newOpsTester() {
    cout << "\nLet's test the new bag operations.\n\n";
    int firstItems[] = {2, 4, 6, 6, 8, 10, 12, 15, 15};
    VectorBag<int> firstBag;
    int firstSize = sizeof(firstItems)/sizeof(int);
    cout << "Adding " << firstSize << " items to first bag: " << endl;
    for (int i = 0; i < firstSize; i++)
        firstBag.add(firstItems[i]);
    cout << "First bag: ";
    displayBag(firstBag);
    
    int secondItems[] = {3, 6, 9, 12, 12, 15, 15, 18};
    VectorBag<int> secondBag;
    int secondSize = sizeof(secondItems)/sizeof(int);
    cout << "Adding " << secondSize << " items to second bag: " << endl;
    for (int i = 0; i < secondSize; i++)
        secondBag.add(secondItems[i]);
    cout << "Second bag: ";
    displayBag(secondBag);
    
    VectorBag<int> unionBag = firstBag + secondBag;
    cout << "firstBag union secondBag: \n";
    displayBag(unionBag);
    
    
    VectorBag<int> intersectBag = firstBag * secondBag;
    cout << "firstBag intersect secondBag: \n";
    displayBag(intersectBag);
    
    VectorBag<int> diffBag = firstBag - secondBag;
    cout << "firstBag minus secondBag: \n";
    displayBag(diffBag);
    
    diffBag = secondBag - firstBag;
    cout << "secondBag minus firstBag: \n";
    displayBag(diffBag);
}

