#pragma once
using namespace std;
class Node
{
public:
	int item;
	Node * next;
};
class Stack
{
public:
	Stack();
	Node * top;
	void push(int n);
	int pop();
	int peek();
	void printAll();
	bool isEmpty();
};