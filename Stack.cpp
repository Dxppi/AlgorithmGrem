#include "Stack.h"

stack::stack(int _maxSize) : maxSize(_maxSize), top(-1) {
	arr = new point[maxSize];
}

stack::~stack()
{
	delete[] arr;
}

void stack::push(point _point)
{
	if (!isFull())
		arr[++top] = _point;
	else
		std::cout << "Stack is full" << std::endl;
}

void stack::pop()
{
	if (!isEmpty())
		top--;
	else
		std::cout << "Stack is empty" << std::endl;
}

void stack::reverse()
{
	int size = top + 1;
	point* _arr = new point[size];
	for (int i = 0; i < size; ++i)
	{
		_arr[i] = getTop();
		pop();
	}
	for (int i = 0; i < size; ++i)
	{
		push(_arr[i]);
	}
	delete[] _arr;
}

point stack::getTop()
{
	return arr[top];
}

point stack::getPrevTop()
{
	return arr[top - 1];
}

bool stack::isEmpty()
{
	return top == -1;
}

bool stack::isFull()
{
	return top == maxSize - 1;
}