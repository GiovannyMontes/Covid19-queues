//
//  queue.cpp
//  Covid19Lines
//
//  Created by Gio Montes on 5/6/20.
//  Copyright © 2020 Gio Montes. All rights reserved.
//

#include <iostream>
#include "queue.hpp"

using namespace std;

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    numPeople = 0;
}

Queue::~Queue() {
    while (!isEmpty())
           dequeue();
}

void Queue::enqueue(int num) {
    
    Person *newNode = nullptr;
     
     newNode = new Person;
     newNode->age = num;
     newNode->next = nullptr;
    
     if (isEmpty())
     {
        front = rear = newNode;
     }
     else
     {
        rear->next = newNode;
        rear = rear->next;
     }
     numPeople++;
    
}

int Queue::dequeue() {
    
    Person *temp = nullptr;
    int value = -1;
    
    if (!isEmpty())
    {
       value = front->age;
       temp = front;
       front = front->next;
       delete temp;
    }
    numPeople--;
    return value;
    
}

bool Queue::isEmpty() {
    
   return (numPeople == 0);
    
}

void Queue::print() {
    Person *printPtr;
    printPtr = front;
    
    while (printPtr) {
        cout << printPtr->age;
        if(printPtr != rear)
            cout << ", ";
        printPtr = printPtr->next;
    }
}

