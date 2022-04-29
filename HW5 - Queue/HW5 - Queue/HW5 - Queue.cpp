// HW5 - Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyQueue.h"

//testing area
int main()
{
    MyQueue<int> lotsOfNumbers = MyQueue<int>(2);
    //check size of queue based on what data is in it
    std::cout << "The current size of the queue lotOfNumbers is " << lotsOfNumbers.GetSize() << "\n";
    std::cout << "Lets add the numbers 12 and 15 \n";
    //add some numbers
    lotsOfNumbers.push(12);
    lotsOfNumbers.push(15);
    std::cout << "Now lets print out the queue and check the size \n";
    //print
    lotsOfNumbers.print();
    //check size of queue based on what data is in it
    std::cout << "The current size of the queue lotOfNumbers is " << lotsOfNumbers.GetSize() << "\n";
    std::cout << "Now lets add two more numbers, 18 and 25, print the queue and then remove a number with pop and print out the queue\n";
    //add some numbers
    lotsOfNumbers.push(18);
    lotsOfNumbers.push(25);
    //print
    lotsOfNumbers.print();
    //remove a data point
    lotsOfNumbers.pop();
    //print
    lotsOfNumbers.print();
    std::cout << "now lets run getsize again and check if it is empty";
    //check size of queue based on what data is in it
    std::cout << "The current size of the queue lotOfNumbers is " << lotsOfNumbers.GetSize() << "\n";
    std::cout << "The queue is currently not empty: "<<lotsOfNumbers.isEmpty();
    lotsOfNumbers.~MyQueue();
}
