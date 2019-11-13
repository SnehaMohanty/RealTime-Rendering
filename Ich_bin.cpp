// Example program
#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#define pdd pair<double, double>
using namespace std; 

void displayPoint(pdd P) 
{ 
    cout << "(" << P.first << ", " << P.second 
         << ")" << endl; 
} 

float area(pdd A, pdd B, pdd C)
{
	return abs((A.first*(2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	/* Calculate area of triangle ABC */
	float A = area(x1, y1, x2, y2, x3, y3);

	/* Calculate area of triangle PBC */
	float A1 = area(x, y, x2, y2, x3, y3);

	/* Calculate area of triangle PAC */
	float A2 = area(x1, y1, x, y, x3, y3);

	/* Calculate area of triangle PAB */
	float A3 = area(x1, y1, x2, y2, x, y);

	/* Check if sum of A1, A2 and A3 is same as A */
	return (A == A1 + A2 + A3);
}

int main()
{

	char a[201][221];
	for (int i = 20; i > -1; i--) {
		for (int j = 0; j < 21; j++)
		{
			a[i][j] = '.';
			if (isInside(1, 1, 10, 1, 1, 10
				, j, i)) {
				a[i][j] = '*';
			}
			std::cout << a[i][j];
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	for (int i = 20; i > -1; i--) {
		for (int j = 0; j < 21; j++)
		{
			a[i][j] = '.';
			if (isInside(5, 5, 7, 5, 6, 6
				, j, i)) {
				a[i][j] = '*';
			}
			std::cout << a[i][j];
		}
		std::cout << "\n";
	}
	system("pause");
}
