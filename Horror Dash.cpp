/*

Zac Conley : Horror Dash : 11799 : acdczlc

Data structure required : Vector, sorting algorithm

Tricks of the trade : Sorting and getting the last value

*/
#include <vector>
#include <iostream>
#include <algorithm> //needed for sort
using namespace std;

int main()
{
	int x,y;
	cin >> x; // #of cases
	for (int i = 0; i < x; i++)
	{
		cin >> y; //number of runners in case
		vector<int> speed; //vector of runner's speeds
		for (int j = 0; j < y; j++)
		{
			int temp;
			cin >> temp;
			speed.push_back(temp); //pushes each speed into vector
		}
		sort(speed.begin(),speed.begin() + y); //sorts vector
		int topspeed = speed[y-1]; //gets last number in sorted vector
		cout << "Case " << i + 1 << ": " << topspeed << endl;
	}
}

