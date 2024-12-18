#include "Graham.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

int Graham::Lowest_point(hull* value, const int n)
{
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        if (value[i].y < value[k].y)
        {
            k = i;
        }
    }
    return k;
}

void Graham::Angle(vector<double>& ps2, hull* point, const int n)
{
    ps2.resize(n);
    int j = Lowest_point(point, n);
    for (int i = 0; i < n; i++)
        ps2[i] = atan2(point[i].y - point[j].y, point[i].x - point[j].x) * 180 / PI;
}

double Graham::result(const hull& p1, const hull& p2, const hull& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool Graham::leftTurn(const hull& a, const hull& b, const hull& c)
{
    return result(a, b, c) > 0;
}

void Graham::Stack(vector<double>& ang, hull* point)
{
    stack<int> S;
    S.push(0);
    S.push(1);

    for (int c = 2; c < ang.size(); c++)
    {
        int a, b;
        do
        {
            b = S.top();
            S.pop();
            a = S.top();
        } while (!leftTurn(point[a], point[b], point[c]));

        S.push(b);
        S.push(c);
    }

    cout << "\nТочки, входящие в оболочку:\n";
    cout << std::fixed << std::setprecision(0);
    while (!S.empty())
    {
        cout << "(" << point[S.top()].x << ", " << point[S.top()].y << ")" << endl;
        S.pop();
    }
}

int QuickSort::partition(vector<double>& arr, hull* b, int low, int high) {
    double pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swap(b[i], b[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    swap(b[i + 1], b[high]);
    return (i + 1);
}

void QuickSort::quickSort(vector<double>& arr, hull* b, int low, int high) {
    if (low < high) {
        int pi = partition(arr, b, low, high);
        quickSort(arr, b, low, pi - 1);
        quickSort(arr, b, pi + 1, high);
    }
}

QuickSort::QuickSort() {
    const int N = 1000;
    hull* b = new hull[N];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; i++) {
        b[i].x = rand() % 1000;
        b[i].y = rand() % 1000;
    }

    /*cout << "Исходные точки (QuickSort):\n";
    cout << std::fixed << std::setprecision(0);
    for (int i = 0; i < N; i++) {
        cout << "(" << b[i].x << ", " << b[i].y << ")\n";
    }*/

    vector<double> a(N);
    Angle(a, b, N);
    unsigned int start_time = clock();
    quickSort(a, b, 0, N - 1);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Quick Sort Time: " << search_time << " ms\n";
    Stack(a, b);
    delete[] b;
}

void heap::heapify(vector<double>& arr, hull* b, int n, int i)
{
    int largest = i;
    int l = 3 * i + 1;
    int c = 3 * i + 2;
    int r = 3 * i + 3;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (c < n && arr[c] > arr[largest])
        largest = c;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        swap(b[i], b[largest]);
        heapify(arr, b, n, largest);
    }
}

void heap::heapSort(vector<double>& arr, hull* b, int n)
{
    for (int i = n / 3 - 1; i >= 0; i--)
        heapify(arr, b, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        swap(b[0], b[i]);
        heapify(arr, b, i, 0);
    }
}

heap::heap()
{
    const int N = 1000;
    hull* b = new hull[N];
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < N; i++)
    {
        b[i].x = rand() % 1000;
        b[i].y = rand() % 1000;
    }

    /*cout << "Исходные точки:\n";
    cout << std::fixed << std::setprecision(0);
    for (int i = 0; i < N; i++)
    {
        cout << "(" << b[i].x << ", " << b[i].y << ")\n";
    }*/

    Angle(a, b, N);
    unsigned int start_time = clock();
    heapSort(a, b, N);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Heap Sort Time: " << search_time << " ms\n";
    Stack(a, b);
    delete[] b;
}

