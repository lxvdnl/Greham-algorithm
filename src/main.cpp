#include "../headers/AVL_Tree.h"
#include "../headers/Point.h"
#include "../headers/QuickSort.h"
#include "../headers/Stack.h"

int main()
{
	int pointsCount;
	std::cout << "Finding the maximum convex hull using Graham's method\n\n";
	std::cout << "Enter 1 - to use quick sort, 2 - to use avl tree sort: ";
	int choice;
	std::cin >> choice;
	if (choice != 1 && choice != 2)
		return 0;
	std::cout << "Enter the number of points: ";
	std::cin >> pointsCount;
	std::cout << "Enter " << pointsCount << " dots separated by spaces\n";
	if (pointsCount < 3) {
		pointsInputExceptions(pointsCount);
		return 0;
	}
	point* pointsField = new point[pointsCount];
	pointsFieldCompletion(pointsField, pointsCount);
	lexicographicallyMinimalPoint(pointsField, pointsCount);
	transferCoordinateSystem(pointsField, pointsCount);
	if (choice == 1)
		quickSort(pointsField, 1, pointsCount - 1);
	else
		treeSort(pointsField, pointsCount);
	stack st(pointsCount);
	determinePointsFormingMaxConvexHull(pointsField, pointsCount, st);
	st.reverse();
	printMaxConvexHull(st);
	delete[] pointsField;
	return 0;
}