//
//  VectorBag.h
//  Mini-Project-1
//
//  Created by Joshua Choi on 2/14/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//
#ifndef VECTOR_H
#define VECTOR_H
#include "BagInterface.h"

// MARK: - VectorBag
template<class ItemType>
class VectorBag : public BagInterface<ItemType> {
private:
    vector<ItemType> items;
    
    /// Returns either the index of the element in the vector items that contains the given target or -1, if the vector does not contain the target.
    int getIndexOf(const ItemType& target) const;
    
public:
    // MARK: - Method Definitions
    int getCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    bool contains(const ItemType& anEntry) const;
    int getFrequencyOf(const ItemType& anEntry) const;
    vector<ItemType> toVector() const;
    VectorBag<ItemType> operator+(VectorBag<ItemType> &anotherBag); // Union
    VectorBag<ItemType> operator*(VectorBag<ItemType> &anotherBag); // Intersection
    VectorBag<ItemType> operator-(VectorBag<ItemType> &anotherBag); // Difference
};
#endif
