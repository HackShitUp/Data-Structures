//
//  VectorBag.cpp
//  Mini-Project-1
//
//  Created by Joshua Choi on 2/14/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//

#include "VectorBag.h"

/**
 Returns the current size of the vector
 */
template<class ItemType>
int VectorBag<ItemType>::getCurrentSize() const {
    return items.size();
}

/**
 Determines if vector is empty
 */
template<class ItemType>
bool VectorBag<ItemType>::isEmpty() const {
    return items.size() == 0;
}

/**
 Adds item to the back
 */
template<class ItemType>
bool VectorBag<ItemType>::add(const ItemType& newEntry) {
    items.push_back(newEntry);
    return true;
}

/**
 Remove item
 */
template<class ItemType>
bool VectorBag<ItemType>::remove(const ItemType& anEntry) {
    for (int i = 0; i < items.size(); ++i)
        if (items[i] == anEntry)
        {
            items[i] = items[items.size() - 1];
            items.pop_back();
            return true;
        }
    
    return false;
}


/**
 Clear all items
 */
template<class ItemType>
void VectorBag<ItemType>::clear() {
    items.clear();
}

/**
 Gets the n-number of instances a given item exists in the list
 */
template<class ItemType>
int VectorBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    
    for (int i = 0; i < items.size(); ++i) {
        if (items[i] == anEntry) {
            frequency++;
        }
    }
    
    return frequency;
}

/**
 Determines if an item is contained in the vector
 */
template<class ItemType>
bool VectorBag<ItemType>::contains(const ItemType& anEntry) const {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i] == anEntry) {
            return true;
        }
    }
    
    return false;
}

/**
 Gets all items in vector
 */
template<class ItemType>
vector<ItemType> VectorBag<ItemType>::toVector() const {
    return items;
}

/**
 Adds an item
 */
template<class ItemType>
VectorBag<ItemType>
VectorBag<ItemType>::operator+(VectorBag<ItemType> &anotherBag) {
    VectorBag<ItemType> newBag;
    
    for (int i = 0; i < items.size(); i++) {
        newBag.add(items[i]);
    }
    
    for (int i = 0; i < anotherBag.items.size(); i++) {
        newBag.add(anotherBag.items[i]);
    }
    
    return newBag;
}

/**
 Get the index of the element
 */
template<class ItemType>
VectorBag<ItemType>
VectorBag<ItemType>::operator*(VectorBag<ItemType> &anotherBag) {
    VectorBag<ItemType> newBag;
    int i = 0, j = 0;
    
    while (i < items.size() && j < anotherBag.items.size()) {
        if (items[i] < anotherBag.items[j]) {
            i++;
        } else if (anotherBag.items[j] < items[i]) {
            j++;
        } else {
            newBag.add(anotherBag.items[j++]);
            i++;
        }
    }

    return newBag;
}


/**
 Returns a new bag
 */
template<class ItemType>
VectorBag<ItemType>
VectorBag<ItemType>::operator-(VectorBag<ItemType> &anotherBag) {
    VectorBag<ItemType> newBag;
    int i = 0, j = 0;
    
    while (i < items.size()) {
        if (items[i] < anotherBag.items[j]) {
            newBag.add(items[i++]);
        } else if (anotherBag.items[j] < items[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    return newBag;
}

/**
 Get the index of the element
 */
template<class ItemType>
int VectorBag<ItemType>::getIndexOf(const ItemType& target) const {
    bool found = false;
    int result = -1;
    int searchIndex = 0;
    
    // If the bag is empty, itemCount is zero, so loop is skipped
    while (!found && (searchIndex < items.size())) {
        if (items[searchIndex] == target) {
            found = true;
            result = searchIndex;
        } else {
            searchIndex++;
        }
    }
    
    return result;
}
