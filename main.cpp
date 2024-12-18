#include <iostream>
#include <ctime>
#include "Graham.h"
#include <chrono>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int q = 10 ^ 6, w = 10 ^ 6; // Заданные размеры прямоугольника
    int n_values[] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 1000000 }; // Степени роста n
    bool on_border = true; // Режим (1) или (2)
    
    // Для каждого n провести эксперименты
    for (int n : n_values) {
        cout << "\n\nExperiment for n = " << n << " points\n";

        // Измерить время работы для алгоритма A (HeapSort)
        HeapSort heap_sort(n, q, w, on_border);

        // Измерить время работы для алгоритма B (QuickSort)
        QuickSort quick_sort(n, q, w, on_border);
    }

    return 0;
}

//int main() {
//    setlocale(LC_ALL, "Russian");
//    HeapSort heap_sort;
//    QuickSort quick_sort;
//    return 0;
//}