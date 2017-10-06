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
	int targetX2[3] = {200, 330, 370};
	int targetY2[3] = {100, 310, 450};
	
	cout << "Enter tolerance: ";
	double x2y2Tol = 0;
	cin >> x2y2Tol;
	
	int maxR1 = 240, maxR2 = 240, maxAngle2 = 90;
		
	double xMid = 0, x2 = 0, yMid = 0, y2 = 0, angle2R = 0;

	for(int R1 = 80; R1 <= maxR1; R1 += 16) 
	{
		for(int R2 = 64; R2 <= maxR2; R2 += 16) 
		{
			for(int L = 80; L <= R1; L += 16) 
			{
				for(int angle2 = -90; angle2 <= maxAngle2; angle2++)
				{
					angle2R = angle2 / 180.0 * M_PI;
					
					// Testing with minAngle1
					
					xMid = xEnd(0, R1, minAngle1(L));
					x2 = xEnd(xMid, R2, angle2);
					yMid = yEnd(0, R1, minAngle1(L));
					y2 = yEnd(yMid, R2, angle2);
					
					for(int i = 0; i < 3; i++) {
						if (fabs(targetX2[i] - x2) <= x2y2Tol && fabs(targetY2[i] - y2) <= x2y2Tol) 
						{
							printf("\nL: %d, R1: %d, R2 %d, Angle 1: %f Angle 2: %d", L, R1, R2, minAngle1(L) * 180 / M_PI, angle2);
							printf("\nX2: %f, Y2: %f \n", x2, y2);
						} 
					}
					
					// Testing with maxAngle1
					
					x2 = xEnd(xEnd(0, R1, maxAngle1(L)), R2, angle2);
					y2 = yEnd(yEnd(0, R1, maxAngle1(L)), R2, angle2);
		
					for(int i = 0; i < 3; i++) {
						if (fabs(targetX2[i] - x2) <= x2y2Tol && fabs(targetY2[i] - y2) <= x2y2Tol) 
						{
							printf("\nL: %d, R1: %d, R2 %d, Angle 1: %f Angle 2: %d", L, R1, R2, minAngle1(L) * 180 / M_PI, angle2);
							printf("\nX2: %f, Y2: %f \n", x2, y2);
						} 
					}
				}
			} 
		}
	}
		
	
	return EXIT_SUCCESS;	

}
