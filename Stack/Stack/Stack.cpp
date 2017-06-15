#include "Stack.h"
#include<iostream>
using namespace std;
Stack::Stack()
{
	top = nullptr;
}
void Stack::push(int n)
{
	bool empty = isEmpty();
	if (empty)
	{
		top = new Node();
		top->item = n;
		top->next = nullptr;

	}
	else
	{
		Node * temp = new Node();
		temp->item = n;
		temp->next = top;
		top = temp;
	}
}
int Stack::peek()
{
	return top->item;
}
bool Stack::isEmpty()
{
	if (top == nullptr)
		return true;
	else
		return false;
}
int Stack::pop()
{
	int data;
	data = top->item;
	top = top->next;
	return data;
}
void Stack::printAll()
{
	Node * nodes = top;
	while (nodes != nullptr)
	{
		cout << nodes->item << " -> ";
		nodes = nodes->next;
	}
}