#pragma once
#ifndef Stack_H
#define Stack_H

#include "Point.h"

struct point;

class stack {
	point* arr;
	int top;
	int maxSize;
public:
	stack(int _maxSize = 100);
	~stack();
	void push(point _point);
	void pop();
	void reverse();
	point getTop();
	point getPrevTop();
	bool isEmpty();
	bool isFull();
};

#endif