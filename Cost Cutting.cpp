/*

Zac Conley : Cost Cutting : 11727 : acdczlc

Data structure required :

Tricks of the trade :

*/

#include <iostream>
using namespace std;

int main() {
	int x, a, b, c; 
	cin >> x;
	for (int i = 0; i < x; i++) 
	{
		int max, min, med; //variables used for comparisons
		cin >> a;
		cin >> b;
		cin >> c;
		if(a==b) //checks if two inputs are = making one the middle value
		{
			med = b;
		}
		else if(a==c) //checks if two inputs are = making one the middle value
		{
			med = c;
		}
		else if (b == c) //checks if two inputs are = making one the middle value
		{
			med = b;
		}
		else //if inputs are not equal, comparisons begin
		{
			max = a;
			min = a;
			if (b > max)
				max = b;
			if (b < min)
				min = b;
			if (c > max)
				max = c;
			if (c < min)
				min = c;
			if (a != max && a != min)
				med = a;
			else if (b != max && b != min)
				med = b;
			else if (c != max && c != min)
				med = c;
		}
		cout << "Case " << i + 1 << ": " << med<<endl;
	}

}