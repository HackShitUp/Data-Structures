//
//  MinStack.cpp
//  HW2
//
//  Created by Joshua Choi on 3/12/19.
//  Copyright © 2019 Joshua Choi. All rights reserved.
//

#include <algorithm>
#include <array>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdio.h>
using namespace std;

/**
 Abstract: Class used to manage 2 stacks.
 */
class MinStack {
private:
    
    /// MARK: - Stacks
    stack<int> baseStack;
    stack<int> minStack;
    
public:
    
    // MARK: - Class Methods
    
    /// Append an int element to the top of the two 'baseStack'
    /// - Parameter x: An Int value.
    void push(int val) {
        // Append to the 'baseStack'
        baseStack.push(val);
        // Append to 'minStack' if it's empty or if the integer is <= the top value of the 'minStack'
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    /// Removes the last element from the 'minStack' and 'baseStack'.
    void pop() {
        // Remove from the 'minStack'
        if (baseStack.top() <= minStack.top()) {
            minStack.pop();
        }
        
        // Remove from the base stack
        baseStack.pop();
    }
    
    /// Get the top value of the 'baseStack'
    int top() {
        return baseStack.top();
    }
    
    /// Get the top value of the 'minStack'
    int getMin() {
        return minStack.top();
    }
};
