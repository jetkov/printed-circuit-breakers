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
	return acos((200.0 * 200.0 + L * L - 210.0 * 210.0)/(2.0 * 200.0 * L));
}

// Calculates the max value of angle 1
double maxAngle1(double L)
{
	return acos((200.0 * 200.0 + L * L - 310.0 * 310.0)/(2.0 * 200.0 * L));
}

int ccc_win_main() 
{
	// Setting up output file
	ofstream fout("model.txt");
	
	const int TARGET_X2[3] = {200, 330, 370};
	const int TARGET_Y2[3] = {100, 310, 450};
	const double X2Y2_TOL = 10;
	
	fout << "Target Points: \n";
	for(int i = 0; i < 3; i++) {
		fout << "(" << TARGET_X2[i] << ", " << TARGET_Y2[i] << ") \n";             
	} 
	fout << "\nTolerance: " << X2Y2_TOL << "\n\n\n";
		
	fout << "X2       Y2       L       R1       R2       Angle 1       Angle 2"
		 << "\n\n";
	
	const int MAX_R1 = 240, MAX_R2 = 240, MAX_ANGLE2 = 90;
	double xMid = 0, x2 = 0, yMid = 0, y2 = 0, angle1 = 0, angle2Rad = 0;
	
	Point pointOrigin(-5, 0), pointMid, pointEnd;
	Line baseLine(Point(-5, 0), Point(5, 0));

	for(int R1 = 80; R1 <= MAX_R1; R1 += 16) 
	{
		for(int R2 = 64; R2 <= MAX_R2; R2 += 16) 
		{
			for(int L = 80; L <= R1; L += 16) 
			{
				for(int angle2 = -90; angle2 <= MAX_ANGLE2; angle2++)
				{
					angle2Rad = angle2 / 180.0 * M_PI;
					
					for(int j = 0; j < 2; j++) 
					{
						if (j == 0) {
							angle1 = minAngle1(L);
						}
						else {
							angle1 = maxAngle1(L);
						}
						
						xMid = xEnd(0, R1, angle1);
						x2 = xEnd(xMid, R2, angle2);
						yMid = yEnd(0, R1, angle1);
						y2 = yEnd(yMid, R2, angle2);
						
						Point pointMid(xMid/50 -5, yMid/50);
						Point pointEnd(x2/50 -5, y2/50);
						
						Line LR1(pointOrigin, pointMid);
						Line LR2(pointMid, pointEnd);
						
						for(int i = 0; i < 3; i++) 
						{
							if (fabs(TARGET_X2[i] - x2) <= X2Y2_TOL 
								&& fabs(TARGET_Y2[i] - y2) <= X2Y2_TOL) 
							{
								// Formatting to table and outputting data
								fout << fixed << left 
									<< setw(9) << setprecision(2) << x2
									<< setw(9) << setprecision(2) << y2
									<< setw(8) << L
									<< setw(9) << R1
									<< setw(9) << R2 
									<< setw(13) << angle1 * 180 / M_PI
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
