#include "LinkedList.h"
#include <iostream>
using namespace std;
Node::Node()
{
	data = 0;
	next = nullptr;
}
Node::~Node()
{
	delete next;
}
LinkedList::LinkedList()
{
	head = nullptr;
	sorted = false;
	length = 0;
}

void LinkedList::insert(int d)
{
	if (sorted == false)
	{
		if (head == nullptr)
		{
			head = new Node();
			head->data = d;
			head->next = nullptr;
			length++;
		}
		else
		{
			Node * newNode = new Node();
			newNode->data = d;
			newNode->next = head;
			head = newNode;
			length++;
		}
	}
	else
	{
		if (head == nullptr)
		{
			head = new Node();
			head->data = d;
			head->next = nullptr;
			length++;
		}
		else if (length == 1)
		{
			Node * newNode = new Node();
			newNode->data = d;
			newNode->next = nullptr;
			head->next = newNode;
			length++;
		}
		else
		{
			bool done=false;
			Node * newNode = new Node();
			newNode->data = d;
			Node * currNode = head;
			Node * prev = head;
			while (currNode != nullptr)
			{
				if (currNode->data > d)
				{
					prev->next = newNode;
					newNode->next = currNode;
					length++;
					done = true;
					break;
				}
				prev = currNode;
				currNode = currNode->next;
			}
			if (done == false)
			{
				length++;
				prev->next = newNode;
				newNode->next = nullptr;
			}
		}
	}
}

void LinkedList::remove(int d)
{
	if (length == 0)
		cout << "List is empty!\n";
	if (length == 1)
	{
		delete head;
		length--;
	}
	else
	{
		bool done = false;
		Node * currNode = head;
		Node * prev = head;
		Node * temp = new Node();
		while (currNode != nullptr)
		{
			if (currNode->data == d)
			{
				temp = currNode->next;
				prev->next = temp;
				delete currNode;
				//delete temp;
				length--;
				done = true;
				break;
			}
			prev = currNode;
			currNode = currNode->next;
		}
		if (!done)
		{
			cout << "Data not found!\n";
		}
	}
}
int LinkedList::search(int d)
{
	if (length == 0)
	{
		cout << "List is empty!";
		return -1;
	}
	else if (length == 1)
	{
		if (head->data == d)
			return head->data;
		else
			return -1;
	}
	else
	{
		bool done = false;
		Node * currNode = head;
		while (currNode != nullptr)
		{
			if (currNode->data == d)
			{
				return currNode->data;
			}
			currNode = currNode->next;
		}
		if (!done)
			return -1;
	}
}
void LinkedList::printList()
{
	Node *currNode = head;
	for (int i = 0; i < length; i++)
	{
		cout << currNode->data << " -> ";
		currNode = currNode->next;
	}
	cout << endl;
}