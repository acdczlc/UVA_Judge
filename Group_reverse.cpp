/*

Zac Conley : Group Reverse : 11192 : acdczlc

Data structure required : 

Tricks of the trade : 

*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string line = "";
	bool go = true;
	while (go)
	{
		int groups;
		cin >> groups;
		if (groups != 0) {
			cin.ignore();
			cin >> line;
			int size = line.length();
			int subgroups = size / groups;
			for (int i = 0; i < groups; i++)
			{

				for (int j = subgroups; j > 0; j--)
				{
					cout << line[(i*subgroups) + j-1];

				}
			}
			cout << endl;
		}
		else {
			go = false;
		}
	}
}