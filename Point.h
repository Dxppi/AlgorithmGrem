#pragma once
#ifndef Point_H
#define Point_H

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "Stack.h"

class stack;

struct point {
	double x, y;
	point operator-(const point& _point);
	point operator+(const point& _point);
	bool operator==(const point& _point);
	bool operator<(const point & _point);
	bool operator>(const point& _point);
};
std::istream& operator>>(std::istream& is, point& _point);
std::ostream& operator<<(std::ostream& os, const point& _point);

void pointsInputExceptions(int pointsCount);

void pointsFieldCompletion(point* arr, int pointsCount);

void pointsSwap(point* arr, int i, int j);

void lexicographicallyMinimalPoint(point* arr, int size);

bool pointsCompare(const point& referencePoint, const point& i, const point& j);

static point transfer;
void transferCoordinateSystem(point* arr, int pointsCount);

void determinePointsFormingMaxConvexHull(point* arr, int pointsCount, stack& maxConvexHull);

void printMaxConvexHull(stack& maxConvexHull);

point getRandomPoint();

#endif