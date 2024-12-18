#pragma once
#include <iostream>
#include<vector>
#include <ctime>
#include<stack>
#include<cmath>
using namespace std;
const double PI = 3.14159265;
struct hull
{
	double x;
	double y;
};
class Graham
{
public:
	vector<double>a;
	int Lowest_point(hull* value, const int n);
	void Angle(vector<double>& ps2, hull* point, const int n);
	double result(const hull& p1, const hull& p2, const hull& p3);
	bool leftTurn(const hull& a, const hull& b, const hull& c);
	void Stack(vector<double>& ang, hull* point);
	
};
class heap : public Graham
{
public:
	void heapify(vector <double>& arr, hull* b, const int n, int i);
	void heapSort(vector <double>& arr, hull* b, const int n);
	heap();
	
};
class QuickSort :public Graham {
public:
	QuickSort();
	void quickSort(vector<double>& arr, hull* b, int low, int high);
	int partition(vector<double>& arr, hull* b, int low, int high);
};
