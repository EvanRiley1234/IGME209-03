#pragma once
#include <iostream>
// Define the default capacity of the queue
#define SIZE 10

template <class T>
class MyQueue
{
public:
	MyQueue(); //default constructor
	MyQueue(int length); //normal constructor
	MyQueue(const MyQueue& source); //copy cosntructor
	MyQueue& operator =(const MyQueue& source); //assignement operator
	~MyQueue(); //destructor
	void push(T data);
	void pop();
	void print();
	int GetSize();
	bool isEmpty();
	bool isFull();
	T* queue;
	int numEntries;
	int queueLength;
};

//default constructor
template <class T>
MyQueue<T>::MyQueue()
{
	queue = new T[1];
	queueLength = 1;
	numEntries = 0;
}

//normal constructor
template <class T>
MyQueue<T>::MyQueue(int length)
{
	queue = new T[length];
	queueLength = length;
	numEntries = 0;
	for (int i = 0; i < queueLength; i++)
	{
		queue[i] = NULL;
	}
}

//copy constructor
template <class T>
MyQueue<T>::MyQueue(const MyQueue& source)
{
	queueLength = source.queueLength;
	numEntries = source.numEntries;
	queue = new T[queueLength];

	for (int i = 0; i < queueLength; i++)
	{
		queue[i] = source.queue[i];
	}
}

//assignment operator
template <class T>
MyQueue<T>& MyQueue<T>::operator =(const MyQueue& source)
{
	if (this == &source)
	{
		return *this;
	}
	queueLength = source.queueLength;
	numEntries = source.numEntries;

	for (int i = 0; i < queueLength; i++)
	{
		queue[i] = source.queue[i];
	}

	return *this;
}

//destructor
template <class T>
MyQueue<T>::~MyQueue()
{
	delete[] queue;
}


//push function
template <class T>
void MyQueue<T>::push(T data)
{
	T* tempQueue;
	if (isFull())
	{
		tempQueue = queue;
		queueLength++;
		queue = new T[queueLength];
		for (int i = 0; i < queueLength - 1; i++)
		{
			queue[i] = tempQueue[i];
		}
	}
	queue[numEntries] = data;
	numEntries++;
}

//pop function
template <class T>
void MyQueue<T>::pop()
{
	if (isEmpty())
	{
		//say the queue is empty
		std::cout << "The Queue is already empty\n";
		return;
	}
	else
	{
		//move everything forward one
		for (int i = 0; i < queueLength; i++)
		{
			//if their is no more data set equal to nullptr
			if (queue[i + 1] == NULL)
			{
				queue[i] = NULL;
			}
			//otherwise just move each piece of data up a place
			else
			{
				queue[i] = queue[i + 1];
			}
		}
		numEntries--;
	}
	
}

//print function
template <class T>
void MyQueue<T>::print()
{
	if (isEmpty())
	{
		//say the queue is empty
		std::cout << "The Queue is already empty\n";
		return;
	}
	else
	{
		for (int i = 0; i < numEntries; i++)
		{
			std::cout << queue[i] << "  ";
		}
		std::cout << "\n";
	}
}

//getSize function
template <class T>
int MyQueue<T>::GetSize()
{
	return numEntries;
}

//isEmpty function
template <class T>
bool MyQueue<T>::isEmpty()
{
	if (numEntries == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
bool MyQueue<T>::isFull()
{
	return (numEntries == queueLength);
}