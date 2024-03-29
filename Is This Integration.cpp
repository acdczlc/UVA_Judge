/*
Zac Conley : Is This Integration? : 10209 : acdczlc

Data structure required : none

Tricks of the trade :Computes the areas of the cubed region the dotted region.
Then uses both areas to compute area of the striped region by subtracting them
from the total area of the square.
*/
#include <iostream>
#include <cmath> //used for sqrt(3.0) and pi
#include <iomanip> //used for printing 3 digits
using namespace std;

int main() {
	double inp; //input
	double pi = acos(-1); //stores pi how you showed us in class
	double x = pi / 3; //stores pi/3 
	double root = sqrt(3.0); //square root of 3
	while(cin>>inp) //while there are more inputs
	{
		double square = (inp*inp); //total area of entire abcd square

		//calculates the dotted area using the square root of 3 and the total
		double dottedArea= square*((2*root)+x-4); //area of the square

		//calculates the cubed/rest area using the square root of 3 and the 
		double cubedArea = square*(4-root-(2*x)); //total area of the square

		//calculates the striped area by taking total area of square and 
		//subtracting all other regions
		double stripeArea = square - (dottedArea + cubedArea);

		cout << setprecision(3) << fixed; //makes doubles print with 3 decimals
		cout << stripeArea << " " << dottedArea << " " << cubedArea << endl;
	}
}