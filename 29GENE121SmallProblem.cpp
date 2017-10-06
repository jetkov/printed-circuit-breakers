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
	return acos((200 * 200 + L * L - 210 * 210)/(2 * 200 * L));
}

// Calculates the max value of angle 1
double maxAngle1(double L)
{
	return acos((200 * 200 + L * L - 310 * 310)/(2 * 200 * L));
}

int main() 
{
	int targetX2[3] = {20, 33, 37};
	int targetY2[3] = {10, 31, 45};
	
	int x2[3] = {0, 0, 0};
	int y2[3] = {0, 0, 0};
	
	cout << "Enter tolerance: ";
	double x2y2Tol = 0;
	cin >> x2y2Tol;
	
	int maxR1 = 240, maxR2 = 240, maxAngle2 = 90;
		
	double x2 = 0, y2 = 0;
	
	boolean reachesAllPoints = false;
	
	for(int i = 0; i < 4; i++)
	{
		for(int R1 = 80; R1 <= maxR1; R1 += 16) 
		{
			for(int R2 = 64; R2 <= maxR2; R2 += 16) 
			{
				for(int L = 80; L <= R1; L += 16) 
				{
					for(int Angle2 = 0; Angle2 <= maxAngle2; Angle2++)
					{
						
						double Angle2R = Angle2 / 180.0 * M_PI;
						
						// Testing with minAngle1
						
						x2[i] = xEnd(xEnd(0, R1, minAngle1(L)), R2, Angle2);
						y2[i] = yEnd(yEnd(0, R1, minAngle1(L)), R2, Angle2);
			
			
						if (fabs(targetX2 - x2) <= x2y2Tol && fabs(targetY2 - y2) <= x2y2Tol) 
						{
							printf("\nL: %d, R1: %d, R2 %d, Angle 1: %f Angle 2: %f", L, R1, R2, minAngle1(L) * 180 / M_PI, Angle2);
							printf("\nX2: %f, Y2: %f \n", x2, y2);
						} 
						
						// Testing with maxAngle1
						
						x2 = xEnd(xEnd(0, R1, maxAngle1(L)), R2, Angle2);
						y2 = yEnd(yEnd(0, R1, maxAngle1(L)), R2, Angle2);
			
						if (fabs(targetX2 - x2) <= x2y2Tol && fabs(targetY2 - y2) <= x2y2Tol) 
						{
							printf("\nL: %d, R1: %d, R2 %d, Angle 1: %f Angle 2: %f", L, R1, R2, maxAngle1(L) * 180 / M_PI, Angle2);
							printf("\nX2: %f, Y2: %f \n", x2, y2);
						} 
					}
				} 
			}
		}
		
	}
	
	return EXIT_SUCCESS;	

}
