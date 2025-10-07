						/********************************/
						/*								*/
						/*				BSP				*/
						/*	Binary Space Partitioning	*/
						/*								*/
						/********************************/

#include "Point.hpp"
#include "Fixed.hpp"

int main()
{
	// Define the triangle vertices
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 10);

	Point p1(5, 5);		// inside
	Point p2(10, 10);	// outside
	Point p3(5, 0);		// on edge

	// Test points
	std::cout << "p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle\n";
	std::cout << "p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle\n";
	std::cout << "p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle\n";

	return (0);
}
