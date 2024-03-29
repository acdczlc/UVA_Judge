/*
Zac Conley : Continued Fractions : 834 : acdczlc

Data structure required : none

Tricks of the trade : print based on location user is at
*/
#include <iostream>

using namespace std;

int divider(int, int, int);

int main() {
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int num, den; //numerator and denominator

	while (cin >> num) //while there are still numerators
	{
		cin >> den; //get denominator
		int empty=divider(num, den, 0); //printing location set to 0
		if(empty==1) //prints if not dividing by 0
		{
			cout << "]" << endl; //outputs final bracket after function
		}
	}
}

//function prints the output based on division and printing
int divider(int num, int den, int x) {
	if (den == 0) //if the denominator is 0  
	{
		return 0; //returns and prevents from printing
	}
	int div = num / den;  //divides and saves into int
	int mod = num % den; //gets modulo of fraction
	if (x == 0) //if nothing has been printed yet
	{
		cout << "[" << div; //print open bracket and division answer
		if (mod != 0) //if there is more numbers that will need to be printed
		{
			cout << ";";//prints ; if more needs to be printed
		}
	}
	else if (x == 1) //if on the second number
	{
		cout << div; //print next number without comma
	}
	else  //if on at least the third number
	{ //print next number with comma
		cout << "," << div;
	}
	divider(den, mod, x + 1); //recursive call 
	return 1; //returns 1 letting the program know that the den was not a 0
}
