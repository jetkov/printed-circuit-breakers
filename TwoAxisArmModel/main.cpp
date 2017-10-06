// TRON Days Group #29

#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#include "ccc_win.h"

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

int ccc_win_main() 
{
	// Setting up output file
	ofstream fout("model.txt");
	
	int targetX2[3] = {200, 330, 370};
	int targetY2[3] = {100, 310, 450};
	
	fout << "Target Points: \n";
	for(int i = 0; i < 3; i++) {
		fout << "\t(" << targetX2[i] << ", " << targetY2[i] << ") \n";             
	} 
	fout << "\n\n";
		
	fout << "X2       Y2       L       R1       R2       Angle 1       Angle 2"
		 << "\n\n";
	
	double x2y2Tol = 10;
	int maxR1 = 240, maxR2 = 240, maxAngle2 = 90;
	double xMid = 0, x2 = 0, yMid = 0, y2 = 0, angle1 = 0, angle2Rad = 0;
	
	Point pointOrigin(-5, 0), pointMid, pointEnd;
	Line baseLine(Point(-5, 0), Point(5, 0));

	for(int R1 = 80; R1 <= maxR1; R1 += 16) 
	{
		for(int R2 = 64; R2 <= maxR2; R2 += 16) 
		{
			for(int L = 80; L <= R1; L += 16) 
			{
				for(int angle2 = -90; angle2 <= maxAngle2; angle2++)
				{
					angle2Rad = angle2 / 180.0 * M_PI;
					
					for(int j = 0; j < 2; j++) 
					{
						if (j == 0) angle1 = minAngle1(L);
						else angle1 = maxAngle1(L);
						
						xMid = xEnd(0, R1, minAngle1(L));
						x2 = xEnd(xMid, R2, angle2);
						yMid = yEnd(0, R1, minAngle1(L));
						y2 = yEnd(yMid, R2, angle2);
						
						Point pointMid(xMid/50 -5, yMid/50);
						Point pointEnd(x2/50 -5, y2/50);
						
						Line LR1(pointOrigin, pointMid);
						Line LR2(pointMid, pointEnd);
						
						for(int i = 0; i < 3; i++) 
						{
							if (fabs(targetX2[i] - x2) <= x2y2Tol 
								&& fabs(targetY2[i] - y2) <= x2y2Tol) 
							{
								// Formatting to table and outputting data
								fout << fixed << left 
									<< setw(9) << setprecision(2) << x2
									<< setw(9) << setprecision(2) << y2
									<< setw(8) << L
									<< setw(9) << R1
									<< setw(9) << R2 
									<< setw(13) << minAngle1(L) * 180 / M_PI
									<< setw(13) << angle2 << endl;
									
								cwin << LR1 << LR2 << baseLine;
							} 
						}
					}
				}
			} 
		}
	}
		
	
	return EXIT_SUCCESS;	

}
