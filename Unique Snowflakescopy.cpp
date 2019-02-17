/*
Zac Conley : Unique Snowflakes : 11572 : acdczlc

Data structure required : Maps

Tricks of the trade : Check if value is in map and add to map if not
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	cin >> cases;
	int n;
	for (int i = 0; i < cases; i++)
	{
		cin >> n;
		int inp;
		map<int, int> Snowflakes;
		int countmax=0;
		for (int j = 0; j < n; j++)
		{
			cin >> inp;
			map<int, int>::iterator itChecker;
			bool check = true;
			int x = 0;
			for (itChecker = Snowflakes.begin(); itChecker != Snowflakes.end(); itChecker++)
			{
				if (itChecker->second == inp) {
					x = itChecker->first;
					check = false;
				}
			}
			if (check) //if value is not in the map
			{
				Snowflakes.insert(pair<int, int>(j, inp));
				if (countmax < Snowflakes.size())
				{
					countmax = Snowflakes.size();
				}	
			}
			else
			{	
					map<int, int>::iterator it = Snowflakes.find(x);
					it++;
					map<int, int>::iterator itStart = Snowflakes.begin();
					Snowflakes.erase(itStart, it);
					Snowflakes.insert(pair<int, int>(j, inp));
			}
		}
		cout << countmax<< endl;
	}
}