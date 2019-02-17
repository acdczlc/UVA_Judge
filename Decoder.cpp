/*
Zac Conley : Decoder : 458 : acdczlc

Data structure required : strings.

Tricks of the trade : subtract 7 from string
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line)) //get input
	{
		int size = line.length(); //size of input
		for (int i = 0; i < size; i++)
		{
			line[i] = line[i] - 7; //decode input
		}
		cout << line; 
		cout << endl;
	}
}