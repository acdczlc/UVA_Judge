/*
Zac Conley : Unique Snowflakes : 11572 : acdczlc

Data structure required : Maps,vector

Tricks of the trade : read snowflakes into vector, and put them into map
and delete them using the order of the vector.
*/
#include <iostream>
#include <map>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases; //number of cases
	cin >> cases;
	int n; //number of inputs in each case
	for (int i = 0; i < cases; i++)
	{
		vector<int> order; //vector that adds each snowflake in order
		int count = 0; //keeps track of number of snowflakes in map
		int x = 0; //used later for erasing from map
		cin >> n;
		int inp;
		map<int, int> Snowflakes;//map that holds snowflakes
		int countMax = 0; ////the highest the counter gets
		for (int j = 0; j < n; j++)
		{
			cin >> inp; //get snowflake from file
			order.push_back(inp); //push snowflake to end of vector
			map<int, int>::iterator it= Snowflakes.find(inp);
			if (it != Snowflakes.end()) { //it checks to see if inp is in map
				if (count > countMax) //if in map loop
				{
					countMax = count; //updates counter
				}
				while (order[x] != inp) { //erases everything in map before inp
						Snowflakes.erase(order[x]);
						count--; //decreases counter for deleted snowflake
						x++;
				}
				x++; //increment x to its new value
			}
			else //add new snowflake to map
			{
				count++; //increases number of snowflakes in map by 1
				Snowflakes[inp] = 1; //adds new snowflake
			}
		}
		if (count > countMax) //if current count is bigger than max count
		{ 
			countMax = count; //makes count the new max count
		}
		cout << countMax << endl; //output
	}
}

