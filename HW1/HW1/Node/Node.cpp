//
//  Node.cpp
//  HW1
//
//  Created by Joshua Choi on 2/8/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>

/**
 Abstract: Node used for Linked List
 */
class Node {
public:
    /// Initialized Data used
    int data;

    /// Pointer
    Node* next;
    
    // MARK: - Init
    Node(int data) {
        // Set the pointer
        this->data = data;
        next = nullptr;
    };
};
