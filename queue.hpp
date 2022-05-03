//
//  queue.hpp
//  Covid19Lines
//
//  Created by Gio Montes on 5/6/20.
//  Copyright © 2020 Gio Montes. All rights reserved.
//

#ifndef queue_hpp
#define queue_hpp

#include <stdio.h>

struct Person {
         int age;
         Person *next;
      };

class Queue {
    private:
       Person *front;
       Person *rear;
       int numPeople;
    public:
       Queue();
       ~Queue();
       void enqueue(int);  // adds a person to the end of the queue
       int dequeue();   // removes a person from the beginning of the queue
       bool isEmpty();   // returns true if the queue is empty;
       void print(); // prints the queue on the screen in one line, each person (age) separated by a space
};

#endif /* queue_hpp */
