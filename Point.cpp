#include "Point.h"

point point::operator-(const point& _point)
{
	point res;
	res.x = this->x - _point.x;
	res.y = this->y - _point.y;
	return res;
}

point point::operator+(const point& _point)
{
	point res;
	res.x = x + _point.x;
	res.y = y + _point.y;
	return res;
}

bool point::operator==(const point& _point)
{
	return x == _point.x && y == _point.y;
}

bool point::operator<(const point & _point)
{
	if (y != _point.y) {
		return y < _point.y;
	}
	return x < _point.x;
}

bool point::operator>(const point& _point){
	if (y != _point.y) {
		return y > _point.y;
	}
	return x > _point.x;
}

std::istream& operator>>(std::istream& is, point& _point)
{
	is >> _point.x;
	is >> _point.y;
	return is;
}

std::ostream& operator<<(std::ostream& os, const point& _point) {
	os << "(" << _point.x << "," << _point.y << ")";
	return os;
}

void pointsInputExceptions(int pointsCount)
{
	if (pointsCount == 0)
	{
		std::cout << "Set of points: \n";
		std::cout << "Max convex hull: \n\n";
		return;
	}
	else if (pointsCount < 0)
	{
		std::cout << "Result: There cannot be a negative number of points\n\n";
	}
	else if (pointsCount == 1)
	{
		point res;
		std::cin >> res;
		std::cout << "Set of points: (" << res.x << " , " << res.y << ")\n";
		std::cout << "Max convex hull: (" << res.x << " , " << res.y << ")\n\n";
	}
	else if (pointsCount == 2)
	{
		point a, b;
		std::cin >> a;
		std::cin >> b;
		std::cout << "Max Set of points: (" << a.x << " , " << a.y << ") , (" << b.x << " , " << b.y << ")\n";
		if (a.x == b.x && a.y == b.y)
			std::cout << "Max convex hull: (" << a.x << " , " << a.y << ")\n\n";
		if (a.x < b.x)
		{
			std::cout << "Max convex hull: (" << a.x << " , " << a.y << ") , (" << b.x << " , " << b.y << ")\n\n";
		}
		else
		{
			std::cout << "Max convex hull: (" << b.x << " , " << b.y << ") , (" << a.x << " , " << a.y << ")\n\n";
		}
	}
}

void pointsFieldCompletion(point* arr, int pointsCount)
{
	for (int i = 0; i < pointsCount; i++)
	{
		std::cin >> arr[i];
	}
	std::cout << "Set of points: (" << arr[0].x << " , " << arr[0].y << ")";
	for (int i = 1; i < pointsCount; i++)
	{
		std::cout << " , (" << arr[i].x << " , " << arr[i].y << ")";
	}
	std::cout << "\n";
}

void pointsSwap(point* arr, int i, int j)
{
	point tmp;
	tmp = arr[j];
	arr[j] = arr[i];
	arr[i] = tmp;
}

void lexicographicallyMinimalPoint(point* arr, int size)
{
	if (size < 2)
		return;
	int* minX = new int[size];
	int countMins = 0, res = 0;
	double min = 1.79769e+308;
	for (int i = 0; i < size; i++)
	{
		if (arr[i].x < min)
		{
			delete[] minX;
			minX = new int[size];
			minX[0] = i;
			countMins = 1;
			min = arr[i].x;
		}
		else if (arr[i].x == min)
		{
			minX[countMins] = i;
			countMins++;
		}
	}
	min = 1.79769e+308;
	for (int i = 0; i < countMins; i++)
	{
		if (arr[minX[i]].y < min)
		{
			res = minX[i];
			min = arr[minX[i]].y;
		}
	}
	delete[] minX;
	pointsSwap(arr, 0, res);
}

bool pointsCompare(const point& referencePoint, const point& i, const point& j)
{
	point vec1 = i, vec2 = j;
	if ((vec1.y * vec2.x - vec1.x * vec2.y > 0) || (vec1.y * vec2.x - vec1.x * vec2.y == 0 && i.x > j.x))
		return true;
	return false;
}

void transferCoordinateSystem(point* arr, int pointsCount)
{
	transfer.x = 0 - arr[0].x;
	transfer.y = 0 - arr[0].y;
	for (int i = 0; i < pointsCount; ++i)
	{
		arr[i] = arr[i] + transfer;
	}
}

void determinePointsFormingMaxConvexHull(point* arr, int pointsCount, stack& maxConvexHull)
{
	maxConvexHull.push(arr[0]);
	maxConvexHull.push(arr[1]);
	for (int i = 2; i < pointsCount; i++)
	{
		while (((maxConvexHull.getTop() - maxConvexHull.getPrevTop()).x * (arr[i] - maxConvexHull.getTop()).y - (maxConvexHull.getTop() - maxConvexHull.getPrevTop()).y * (arr[i] - maxConvexHull.getTop()).x < 0) || maxConvexHull.getTop() == arr[i])
			maxConvexHull.pop();
		maxConvexHull.push(arr[i]);
	}
}

void printMaxConvexHull(stack& maxConvexHull)
{
	std::cout << "Max convex hull: (" << maxConvexHull.getTop().x - transfer.x << " , " << maxConvexHull.getTop().y - transfer.y << ")";
	maxConvexHull.pop();
	while (!maxConvexHull.isEmpty())
	{
		std::cout << " , (" << maxConvexHull.getTop().x - transfer.x << " , " << maxConvexHull.getTop().y - transfer.y << ")";
		maxConvexHull.pop();
	}
	std::cout << "\n";
}

point getRandomPoint() {
	point res;
	res.x = (int)rand() % 10;
	res.y = (int)rand() % 10;
	return res;
}

