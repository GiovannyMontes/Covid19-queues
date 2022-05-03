//
/*************************************************************************************

  CIS 22B

    Lab2: [ This program allocates 2 customers at a time to their designated lines (Adult/Senior)

                Everytime 2 new costumers are added, 2 that are in front of line are removed

                

  Author: [Giovanny Montes ]

  Date: [5-8-20]

******************************************************************************************/

#include <iostream>
#include "queue.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int random(int, int);
void starters(Queue, Queue);
void line(Queue, Queue);

int const MIN = 20, MAX = 100;


int main() {
    
    // initializing random number generator
    srand(time(0));
    
    Queue Senior;
    Queue Adult;

    // Add 10 random people to lines according to age
    int i = 0;

    while (i < 10) {
        int num = random(MIN, MAX);
        
        if (num < 59)
            Adult.enqueue(num);
        else if (num >= 59)
            Senior.enqueue(num);
        i++;
    }
    
    // Print the 10 random people in line
    cout << "Initial Adult Line: ";
    Adult.print();
    cout << "\nInitial Senior Line: ";
    Senior.print();
    
    // User interface to add/remove people
    line(Adult, Senior);
    
    
    return 0;
}



int random(int lower_bound, int upper_bound)
{
    int n = rand();
    n %= (upper_bound - lower_bound + 1);
    n += lower_bound;
    return n;
}


/*****************************************|
 
 Inserts/Removes people from lines
 
 Prints current lines
 
********************************************/
void line(Queue A, Queue S)
{
    cout << "\nPress enter or 'e' to exit";
    while (cin.get() != 'e') {
        
        int num1 = random(MIN, MAX);
        int num2 = random(MIN, MAX);
        //cout << num << endl;
        if (num1 < 59) {
            A.enqueue(num1);
        }
        else if (num1 >= 59) {
            S.enqueue(num1);
        }
        if (num2 < 59) {
            A.enqueue(num2);
        }
        else if (num2 >= 59) {
            S.enqueue(num2);
        }
        
        // Print the new/leaving customers
        cout << "Entered Store: " << A.dequeue() << ", "
            << S.dequeue() << endl;
        cout << "New Arrivals: " << num1 << ", " << num2 << endl;
        
        // Print current lines
        cout << "Current Adult Line: " << endl;
        A.print();
        cout << "\nCurrent Senior Line: " << endl;
        S.print();
        
        cout << "\n\nPress enter or 'e' to exit";
    }
}


/****************
 Output
******************
 
 Initial Adult Line: 54, 40, 22, 57, 40, 38, 26
 Initial Senior Line: 80, 100, 92
 Press enter or 'e' to exit
 Entered Store: 54, 80
 New Arrivals: 35, 21
 Current Adult Line:
 40, 22, 57, 40, 38, 26, 35, 21
 Current Senior Line:
 100, 92

 Press enter or 'e' to exit
 Entered Store: 40, 100
 New Arrivals: 95, 39
 Current Adult Line:
 22, 57, 40, 38, 26, 35, 21, 39
 Current Senior Line:
 92, 95

 Press enter or 'e' to exit
 Entered Store: 22, 92
 New Arrivals: 51, 24
 Current Adult Line:
 57, 40, 38, 26, 35, 21, 39, 51, 24
 Current Senior Line:
 95

 Press enter or 'e' to exit
 Entered Store: 57, 95
 New Arrivals: 90, 90
 Current Adult Line:
 40, 38, 26, 35, 21, 39, 51, 24
 Current Senior Line:
 90, 90

 Press enter or 'e' to exit
 Entered Store: 40, 90
 New Arrivals: 24, 38
 Current Adult Line:
 38, 26, 35, 21, 39, 51, 24, 24, 38
 Current Senior Line:
 90

 Press enter or 'e' to exit
 
 ********************************************/
