//
//  main.cpp
//  HW1
//
//  Created by Joshua Choi on 2/8/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//

#include "ElementNode/ElementNode.cpp"
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;



/**
 Joshua M. Choi
 Lisha Zhou
 Data Structures II
 Assignment No. 1
 2/1/19
 ******************************************************************************************************************
 ***************************************** ASSIGNMENT REQUISITES **************************************************
 ******************************************************************************************************************
 
 1. Write a C++ function rotate(int arr[], int d, int n) that rotates arr[] of size n to the left by d elements.
 Example:
 • Input: arr[]={1,2,3,4,5,6,7},d=3,n=7
 • Output: arr[] = {4, 5, 6, 7, 1, 2, 3}.
 
 2. Given an array of random numbers, write a C++ function pushZerosToEnd(int arr[], int n) to push all the zero’s of a given array to the end of the array. Do not change the order of the non-zero elements.
 Example:
 • Input: arr[]={1,2,0,4,3,0,5,0}
 • Output: arr[] = {1, 2, 4, 3, 5, 0, 0, 0}
 
 3. Given a linked list with at least two nodes, remove the last element from the linked list.
 Function prototype: Node* removeLastElement(Node* head)
 Example:
 • Input: 1→2→6→3→4→5
 • Output: 1→2→6→3→4
 
 4. Reverse a singly linked list.
 Function prototype: Node* reverseList(Node* head)
 Example:
 • Input: 1→2→3→4→5→NULL
 • Output: 5→4→3→2→1→NULL
 
 5. Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 Function prototype: Node* mergeTwoLists(Node* n1, Node* n2)
 Example:
 • Input: 1→2→4, 1→3→4
 • Output: 1→1→2→3→4→4
 
 In your main function, please give at least one test case for each of these five questions. You can have multiple .cpp files (e.g. you can put the first two questions in one .cpp file and the last three questions in the other one). All you .cpp files should be runnable (i.e. you have a main function with test cases in it.).
 If you have multiple files to submit, please compress all the files into a zip file with the title “yourFullName_HW1”
 */




// MARK: - Class Vars

/// MARK: - ElementNode (initialized vector of ElementNode objects used to delegate tasks for vector management)
vector<ElementNode> elementNodes;

/// Declared string used for logging
const string marker = "***********************************************************************************************************";

// MARK: - Class Method Definitions

// MARK: - Rotate Array
void getArray();
void rotate(int arr[], int d, int n);
// MARK: - Push Zeros To End
void generateRandomValues();
void pushZerosToEnd(int arr[], int n);
// MARK: -




// MARK: - Main
int main(int argc, const char * argv[]) {
    
    /**
     MARK: - ROTATE ARRAY
     */
    getArray();
    
    /**
     MARK: - PUSH ZERO'S TO END
     */
    generateRandomValues();
    
    return 0;
}


/**
 Requests the user to input an array of integers
 */
void getArray() {
    
    // Clear the ElementNode vector
    elementNodes.clear();
    
    /// Set the quit
    string quit = "q";
    
    /// Initialized int value representing the input value
    int inputValue = 0;
    /// Initialized int value used to delegate the position of the element in the vector
    int counter = 0;
    
    /// Request the user's input and get n-number of integers for the vector
    cout << marker;
    cout << "\n1.) We're going to rotate your array. Please input your integers. Enter \"q\" or hit space and enter to stop.\n";
    cout << marker;
    cout << endl;
    
    /**
     Here, we continuously get input until the input is invalid
     */
    do{
        // Get the input value
        cin >> inputValue;
        // Increment the counter
        counter += 1;
        
        // MARK: - ElementNode
        ElementNode elementNode = ElementNode();
        elementNode.position = counter;
        elementNode.value = inputValue;
        
        if (cin.fail() == false) {
            //
            // Continue
            //
            // Append the object to the end of the vector
            elementNodes.push_back(elementNode);
            
        } else if (cin.fail() == true) {
            //
            // Quit
            //
            
            // Ensure that the vector isn't empty
            if (elementNodes.size() != 0) {
                
                /// Get the size of the vector
                unsigned int size = elementNodes.size();
                
                /// Get the last index in the array
                int lastIndex = size - 1;
                
                // Log the total number of elements in the vector
                cout << "• You added a total of " << size << " elements: ";
                
                /**
                 Here, we take the 'elementNodes' vector and map them into integer arrays. I wish I understood better how to map objects to their values without executing a foor loop.
                 */
                
                /// Initialized int array used to map the 'ElementNode' objects by their int values
                int mappedNodes[size];
                
                for (int i = 0; i < size; ++i) {
                    // Log it
                    cout << elementNodes[i].value;
                    
                    if (i != lastIndex) {
                        cout << ", ";
                    }
                    
                    // Set the value at its index
                    mappedNodes[i] = elementNodes[i].value;
                }
                
                /**
                 MARK: - Algorithim
                 Sort the array from least to greatest.
                 */
                std::sort(mappedNodes, mappedNodes + size);
                
                // Update the positions and their respective values
                for (int i = 0; i < size; ++i) {
                    elementNodes[i].position = i;
                    elementNodes[i].value = mappedNodes[i];
                }
                
                /// Initialized Int value used to represent the total number of elements to shift the elements in the vectory by
                int shiftByN = 0;
                
                // Get the n-total number of elements to rotate the number of elements by
                cout << "\n• Now, we need to get the n-number of elements you want to rotate your input values by: ";
                // Clear the previous inputs
                cin.clear();
                cin.ignore();
                // Pass the input values
                cin >> shiftByN;
                
                // Rotate the array
                rotate(mappedNodes, 0, shiftByN - 1);
                rotate(mappedNodes, shiftByN, size - 1);
                rotate(mappedNodes, 0, size - 1);
                
                cout << "• Rotated array: ";
                // Log the results
                for (int i = 0; i < size; ++i) {
                    cout <<  mappedNodes[i];
                    if (i != lastIndex) {
                        cout << ", ";
                    }
                }
                
                // Exit method
                break;
                
            } else {
                cout << "Quitting program. You have no elements in your vector. See you later! :(";
            }
        }
        
    } while(cin.fail() == false);
}

/**
 Rotates/shifts a given array to the left by n elements.
 
 - Parameter arr: An array of Int values.
 - Parameter d: An Integer value representing the n-number of elements to shift the array by.
 - Parameter n: An Integer value representing the size of the array
 */
void rotate(int arr[], int d, int n) {
    
    int temp = arr[d];
    int start = d;
    int end = n;
    
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 Generates a random array of integers and pushes/shifts the 0's towards the end
 */
void generateRandomValues() {
    /// Initialized Int value representing the size of the user's array
    int sizeOfArray = 0;
    cout << "\n" << marker << "\n";
    cout << marker << "\n";
    cout << "2.) Generating random integers to push all of the 0's to the end of the array. Please input the size of your array: ";
    cin.clear();
    cin.ignore();
    cin >> sizeOfArray;
    cout << "Updating your array...\n";
    
    /// Initialized array of Int values
    int array[sizeOfArray];
    
    cout << "• Your array is: ";
    
    for (int i = 0; i < sizeOfArray; ++i) {
        // Set the value of the array at the index
        int randomInteger = rand() % 10;
        array[i] = randomInteger;
        
        cout << array[i];
        
        if (i != sizeOfArray - 1) {
            cout << ", ";
        }
    }
    
    pushZerosToEnd(array, sizeOfArray);
    
    cout << "\n• Your array with all 0's pushed to the end: ";
    
    for (int i = 0; i < sizeOfArray; ++i) {
        // Set the value of the array at the index
        cout << array[i];
        
        if (i != sizeOfArray - 1) {
            cout << ", ";
        }
    }
    
    cout << "\n";
}

/**
 Pushes all the 0's in array to the back
 
 - Parameter arr: An array of Int values.
 - Parameter n: An Integer value representing the size of the array
 */
void pushZerosToEnd(int arr[], int n) {
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (arr[i] != 0) {
            arr[count++] = arr[i];
        }
    }
    
    while (count < n) {
        arr[count++] = 0;
    }
}
