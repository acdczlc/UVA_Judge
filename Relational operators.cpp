/*

Zac Conley : Relational Operators : 11172 : acdczlc

Data structure required : 

Tricks of the trade :

*/

#include <iostream>
using namespace std;

int main()
{
	int x,a,b;
	cin >> x;
	for (int i = 0; i < x; i++)
	{
		cin >> a;
		cin >> b;
		if (a < b)
		{
			cout << "<";
		}
		if (a == b) 
		{
			cout << "=";
		}
		if (a > b)
		{
			cout << ">";
		}
		cout << endl;
	}
}

