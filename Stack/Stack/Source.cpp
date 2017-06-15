#include "Stack.h"
using namespace std;
void main()
{
	Stack * s = new Stack();
	s->push(1);
	s->push(2);
	s->push(3);
	s->printAll();
	s->pop();
	s->printAll();
}