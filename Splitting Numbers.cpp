/*
Zac Conley : Splitting Numbers : 11933 : acdczlc
Data structure required : bitsets
Tricks of the trade : iterate through bitset taking turns
*/
#include <iostream>
#include <bitset>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int inp; //captures input
	cin >> inp; //gets first input
	while (inp != 0)
	{
		bitset<32> aBits; //declares 2 bitsets with 32 bits
		bitset<32> bBits; 
		aBits = inp; //places input into a bitset
		int turn = 0; //starts by changing the first bitset
		for (int i = 0; i < aBits.size(); i++) //iterate through aBits
		{ 
			if (aBits[i] == 1 && (turn==1)) //if a bit is 1 and it is time to
			{                               //place it in the second bitset
				aBits[i] = 0; //makes bit 0 in 1st bitset
				bBits[i] = 1; //moves the 1 bit to the second bitset
				turn = 0; //makes it the first bitset's turn again.
			}
			else if (aBits[i] == 1 && (turn == 0)) //if a bit is 1 and it is 
			{                                      //the first bitset's turn
				turn = 1;                      //nothing happens because the
			}                //bit is already in the bitset, and the turn ends
		}
		unsigned long long a, b; //output variables
		a = aBits.to_ullong(); //places decimal number into variables
		b = bBits.to_ullong();
		cout << a<< " "<<b<< endl;
		cin >> inp; //gets next input number
	}
}