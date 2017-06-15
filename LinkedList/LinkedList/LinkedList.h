#pragma once
using namespace std;
class Node
{
public:
	int data;
	Node * next;
	Node();
	~Node();

};
class LinkedList
{
	Node * head;
public:
	LinkedList();
	int length;
	bool sorted;
	void insert(int data);
	void remove(int data);
	int search(int data);
	void printList();
};