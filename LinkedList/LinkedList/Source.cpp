#include<iostream>
#include"LinkedList.h"
using namespace std;
int main()
{
	LinkedList list;

	list.insert(1);
	list.insert(2);
	list.insert(4);
	list.insert(3);
	list.printList();
	list.remove(4);
	list.printList();
	int n = list.search(3);
	cout << n << endl;
	 n = list.search(4);
	 if (n == -1)
		 cout << "4 not found!" << endl;
	return 0;
}