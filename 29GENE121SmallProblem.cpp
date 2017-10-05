// TRON Days Group #29

#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

// Accepts a starting x value (xS), a radius (R), and an angle, and returns xE
double xEnd(double xStart, double radius, double angle) 
{
	return xStart + radius * cos(angle);
}

// Accepts a starting y value (yS), a radius (R), and an angle, and returns yE
double yEnd(double yStart, double radius, double angle) 
{
	return yStart + radius * sin(angle);
}

// Calculates min value of angle 1
double minAngle1(double L) 
{
	return acos((20 * 20 + L * L - 21 * 21)/(2 * 20 * L));
}

// Calculates the max value of angle 1
double maxAngle1(double L)
{
	return acos((20 * 20 + L * L - 31 * 31)/(2 * 20 * L));
}

int main() 
{
	cout << "Enter target X2, target Y2, and tolerance: ";
	double x2y2Tol = 0, targetX2 = 0, targetY2 = 0;
	cin >> targetX2 >> targetY2 >> x2y2Tol;
	
	int R1 = 80, maxR1 = 240, R2 = 64, maxR2 = 240, 
		L = 80, maxL = maxR1, Angle2 = -90, maxAngle2 = 90;
		
	int x2 = 0, y2 = 0;
	
	for(; R1 <= maxR1; R1 += 16) 
	{
		for(; R2 <= maxR2; R2 += 16) 
		{
			for(; L <= maxL; L += 16) 
			{
				for(; Angle2 <= maxAngle2; Angle2 += 1)
				{
					// Testing with minAngle1 
					x2 = cos(minAngle1(L) * R1 + cos(Angle2) * R2);
					y2 = sin(minAngle1(L) * R1 + sin(Angle2) * R2);
					
					cout << x2 << " " << y2 << endl;
					
					if (fabs(targetX2 - x2) <= x2y2Tol && fabs(targetY2 - y2) <= x2y2Tol) 
					{
						printf("\nL: %d, R1: %d, R2 %d, Angle 2: %d", L, R1, R2, Angle2);
						printf("\nX2: %d, Y2: %d", x2, y2);
					} 
					
					// Testing with maxAngle1 
					x2 = cos(maxAngle1(L) * R1 + cos(Angle2) * R2);
					y2 = sin(maxAngle1(L) * R1 + sin(Angle2) * R2);
					
					cout << x2 << " " << y2 << endl;
					
					if (fabs(targetX2 - x2) <= x2y2Tol && fabs(targetY2 - y2) <= x2y2Tol) 
					{
						printf("\nL: %d, R1: %d, R2 %d, Angle 2: %d", L, R1, R2, Angle2);
						printf("\nX2: %d, Y2: %d", x2, y2);
					} 
				}
			} 
		}
	}
	
	return EXIT_SUCCESS;	

}
