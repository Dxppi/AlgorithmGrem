#include "Point.h"
#include "QuickSort.h"


void getPointsCount(int& pointsCount) {
    std::cout << "Enter the number of points: ";
    std::cin >> pointsCount;
}

void inputPoints(point* pointsField, int pointsCount) {
    std::cout << "Enter " << pointsCount << " points separated by spaces:\n";
    pointsFieldCompletion(pointsField, pointsCount);
}

void generateRandomPoints(point* pointsField, int pointsCount) {
    std::cout << "Generated random points:\n";
    for (int i = 0; i < pointsCount; ++i) {
        pointsField[i] = getRandomPoint(); // √енераци€ случайной точки
        std::cout << "Point " << i + 1 << ": (" << pointsField[i].x << ", " << pointsField[i].y << ")\n";
    }
}

void printPoints(const point* pointsField, int pointsCount) {
    std::cout << "Points:\n";
    for (int i = 0; i < pointsCount; ++i) {
        std::cout << "Point " << i + 1 << ": (" << pointsField[i].x << ", " << pointsField[i].y << ")\n";
    }
}

int main()
{
    std::cout << "Finding the maximum convex hull using Graham's method\n\n";

    int pointsCount;
    getPointsCount(pointsCount);

    if (pointsCount < 3) {
        pointsInputExceptions(pointsCount);
        return 0; // Ќедостаточно точек дл€ построени€ выпуклой оболочки
    }

    point* pointsField = new point[pointsCount];

    int inputChoice;
    std::cout << "Choose input method:\n1 - Manual input\n2 - Random points\n";
    std::cin >> inputChoice;

    if (inputChoice == 1) {
        inputPoints(pointsField, pointsCount);
    }
    else if (inputChoice == 2) {
        srand(static_cast<unsigned int>(time(0)));
        generateRandomPoints(pointsField, pointsCount);
    }
    else {
        std::cout << "Invalid choice. Exiting.\n";
        delete[] pointsField;
        return 0;
    }
    
    int sortChoice;
    std::cout << "Choose sorting method:\n1 - Quick sort\n2 - Heap sort\n3 - Heap sort and Quick sort\n";
    std::cin >> sortChoice;

    lexicographicallyMinimalPoint(pointsField, pointsCount);
    transferCoordinateSystem(pointsField, pointsCount);

    if (sortChoice == 1) {
        quickSort(pointsField, 1, pointsCount - 1);
        printPoints(pointsField, pointsCount);
    }
    else if  (sortChoice == 2) {
        
       
        printPoints(pointsField, pointsCount);
    }
    else if (sortChoice == 3) {
        point* pointsFieldCopy = new point[pointsCount];
        std::copy(pointsField, pointsField + pointsCount, pointsFieldCopy);

        
        std::cout << "\nPoints sorted using Heap Sort:\n";
        printPoints(pointsFieldCopy, pointsCount);

        stack st1(pointsCount);
        determinePointsFormingMaxConvexHull(pointsFieldCopy, pointsCount, st1);
        st1.reverse();
        printMaxConvexHull(st1);

        quickSort(pointsField, 0, pointsCount - 1);
        std::cout << "\nPoints sorted using Quick Sort:\n";
        printPoints(pointsField, pointsCount);

        delete[] pointsFieldCopy;
    }
    else  {
        std::cout << "Invalid choice. Exiting.\n";
        delete[] pointsField;
        return 0;
    }

    stack st(pointsCount);
    determinePointsFormingMaxConvexHull(pointsField, pointsCount, st);
    st.reverse();
    printMaxConvexHull(st);

    delete[] pointsField;
    return 0;
}