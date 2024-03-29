/*
Zac Conley : Magic Numbers : 471 : acdczlc
Data structure required : bitsets
Tricks of the trade : use function to determine if there are repeating digits
*/
#include <iostream>
#include <bitset> //used for tracking digits
using namespace std;
bool isUnique(unsigned long long); //function used
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	cin >> cases;
	cin.ignore(); //skips blank line after cases
	for (int i = 0; i < cases; i++)
	{
		unsigned long long input; //input entered
		cin >> input;
		unsigned long long maximum = 10000000000; //11 digit number, to have no
		                     //repeats, a number must be at most 10 digits long
		for (unsigned long long j = 1; j*input < maximum; j++)
		{ //loop runs while j*input is smaller than 11 digits
			bool fail = false; //if fail is true there are repeating digits
			fail=isUnique(j); //checks j
			if (fail != true) //if j has no repeats
			{
				unsigned long long multiple = j * input; 
				if (multiple < maximum) //checks if j *  input is smaller than
				{                       //11 digits
					fail = isUnique(multiple); //checks multiple for repeats
					if (fail == false) //if no repeats prints the output for
					{                  //this value of j
						cout << multiple << " / " << j << " = " << input << endl;
					}
				}
			}
		}
		if (i + 1 != cases) { //if this is not the last case, prints a blank line
			cout << endl;
		}
	}
}
bool isUnique(unsigned long long j)
{
	bitset<64> s2Check; //used to keep track of numbers of digits
	bool fail = false; //if fail is true there are repeating digits
	while (j != 0 && fail==false) //extracts a digit at a time
	{                             //while there are no repeats
		if (j >= 10) 
		{
			if(s2Check[j%10]==1) //if there are repeats it fails
			{
				fail = true;
			}
			else 
			{
				s2Check[j % 10] = 1; //extract digit
				j = j / 10;          // and decrease j
			}
		}
		else if (j < 10)
		{
			if (s2Check[j] == 1) //if there are repeats it fails
			{
				fail = true;
			}
			else
			{ 
				s2Check[j] = 1; //extract final digit
				j = 0; 
			}
		}
	}
	return fail; //returns status, if fail is true there are repeats
}