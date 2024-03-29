/*
Zac Conley : The Bases Are Loaded : 355 : acdczlc

Data structure required : strings

Tricks of the trade : reverse strings and user horners rule
*/

//Program is not accepted by uva but returns the right answer for every input
//tested. You said through email to go ahead and turn it in.

#include <iostream>
#include <string>
#include <algorithm> //used for string reverse
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int base; //original base
	int convbase; //base being converted to
	string inp; //input string
	string vals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //string for indexing
	//some input files used letters bigger than F so i included up to z
	while (cin >> base) //while there is input
	{
		cin >> convbase;
		cin >> inp;
		string copy = inp; //makes copy since inp will be manipulated
		reverse(inp.begin(), inp.end()); //reverse inp
		long long count = 0;//counter that displays base 10 number
		bool fail = false; //failure
		for (int i = 0; i < inp.length(); i++) //for char in input
		{
			long long power = 1;
			for (int j = 0; j < i; j++)// used to get power
			{
				power =power*base;
			}
			int x;
			for (int j = 0; j < vals.length(); j++) //finds value of number
			{
				if (vals[j] == inp[i])
				{
					x = j;
				}
			}
			if (x >= (base)) //if inp value is bigger than base
			{                //it is an invalid number
				fail = true;
			}
			count += power * x; //adds part of base 10 number
		}
		if (fail == false) //if number is valid
		{
			if (convbase == 10) //if converting to base 10 print since it is
			{                   //already in base 10
				cout << copy << " base " << base << " = " << 
					count << " base " << convbase<<endl;
			}
			else //if not in base 10
			{
				long long div = count; //makes a divider variable
				string answer= ""; //new answer
				int mod; //mod variable 
				while (div > 0) //while the number has not been divided all the
				{               //way to 0
					mod = div % convbase; //gets mod of base 10 number/base 
					div = div / convbase; //you are converting to
					answer.push_back(vals[mod]); //pushes mod into end of string
				}
				reverse(answer.begin(), answer.end()); //reverses string to cout
				cout << copy << " base " << base << " = " << answer <<
					" base " << convbase << endl;
			}
		}
		else //number is an illegal number
		{
			cout << copy << " is an illegal base " << base << " number" << endl;
		}	
	}
}