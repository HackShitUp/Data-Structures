//
//  Node.cpp
//  HW1
//
//  Created by Joshua Choi on 2/8/19.
//  Copyright © 2019 Capsule LLC. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

///**
// Abstract: Node used for Linked List
// */
//struct Node {
//    /// Initialized Data used
//    int data;
//
//    /// Pointer
//    Node* next;
////    // MARK: - Init
////    Node(int data) {
////        this->data = data;
////        next = nullptr; // <=> next = NULL;
////    };
//};

//class LinkedList {
//public:
//    LinkedList();
//    virtual ~LinkedList();
//    bool isEmpty();
//    void add(int dataEntry); //add at the beginning of the linked list
//    void remove(); //remove at the beginning of the linked list
//    void clear();
//    void removeFromEnd(int n);
//    void display();
//    //void insert(int pos, int dataEntry);
//    //void remove(int pos);
//private:
//    Node* head;
//    int length; //itemCount
//};
//
//LinkedList::LinkedList()
//{
//    head = NULL;
//    length = 0;
//}
//
//LinkedList::~LinkedList()
//{
//    clear();
//}
//
//bool LinkedList::isEmpty()
//{
//    return length == 0;
//}
//
//void LinkedList::add(int dataEntry)
//{
//    Node* cur = new Node();
//
//    cur->data = dataEntry;
//    cur->next = head;
//    head = cur;
//    length++;
//}
//
//void LinkedList::remove()
//{
//    Node* cur = head;
//
//    head = head->next;
//    cur->next = NULL;
//    delete cur;
//    cur = NULL;
//    length--;
//}
//
//void LinkedList::clear()
//{
//    while(!isEmpty())
//        remove();
//}
//
//void LinkedList::removeFromEnd(int n)
//{
//    Node* prevPtr = head;
//
//    for (int i = 1; i < length - n; i++)
//        prevPtr = prevPtr->next;
//
//    Node* curPtr = prevPtr->next;
//    prevPtr->next = curPtr->next;
//    curPtr->next = NULL;
//    delete curPtr;
//    curPtr = NULL;
//    length--;
//}
//
//void LinkedList::display()
//{
//    Node* cur = head;
//    int i = 1;
//    while (cur != NULL)
//    {
//        cout << i << ": " << cur->data << endl;
//        cur = cur->next;
//        i++;
//    }
//}
