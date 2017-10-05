// TRON Days Group #29

#include <cmath>
#include <cstdlib>

using namespace std;

// Accepts a starting x value (xS), a radius (R), and an angle, and returns xE
double xEnd(double xStart, double radius, double angle) {
	return 0;
}

// Accepts a starting y value (yS), a radius (R), and an angle, and returns yE
double yEnd(double yStart, double radius, double angle) {
	return 0;
}

const double PCYLINDER_MAX = 33, BASE_LENGTH = 20; // cm
const double XY_TOL = 0, targetX2 = 0, targetY2 = 0;

int main() {
	
	double L = 0, R1 = 0, R2 = 0, angle2 = 0, x2 = 0, y2 = 0;
	
	cin >> L >> R1 >> R2 >> angle2;
	
	if (true) // Valid lengths L, R1, and R2, and valid angle 2
	{
		// calculate the resulting (x2,y2)
	}

	if (fabs(targetX2 - x2) <= XY_TOL && fabs(targetY2 - y2) <= XY_TOL) 
	{
		printf("\nL: %d, R1: %d, R2 %d, Angle 2: %d", L, R1, R2, angle2);
		printf("\nX2: %d, Y2: %d", x2, y2);
	} else 
	{
		cout << "X2 and Y2 not within tolerance."
	}

}
