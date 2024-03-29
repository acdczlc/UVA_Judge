/*
Zac Conley : Robot Motion : 10116 : acdczlc

Data structure required : vector, string, pair

Tricks of the trade : use vectors and pairs to keep track of
robot as well as visited letters
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility> //pairs
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int row; //number of rows in matrix
	int col; //number of columns in matrix 
	int start; //starting position of matrix
	cin >> row; //get values
	cin >> col;
	cin >> start;
	string line;
	while (row != 0 && col != 0 && start != 0) //while cases remain
	{
		pair <int, int> current; //robot's current position
		vector<vector<char>>matrix(11, vector<char>(11)); //matrix of directions
		vector<vector<bool>>visited(11, vector<bool>(11));//visited letters
		for(int r=0;r<row;r++) //fill matrix with directions
		{
			cin >> line; //get line of matrix
			for (int c = 0; c < col; c++)
			{
				matrix[r][c] = line[c]; //fill columns of matrix
			}
		}
		bool going = true; //while no exits or loops
		int count = 0; //counts steps
		current.first = 0; //set robot to top row
		current.second = start - 1; //set robot to correct -1:vector starts at 0
		while (going == true) //while no exits or loops
		{
			if (visited[current.first][current.second] == false) //if not visited
			{
				count++; //take step
				visited[current.first][current.second] = true; //set visited
				if (matrix[current.first][current.second] == 'N')
				{ //if going north
					current.first--;
				}
				else if (matrix[current.first][current.second] == 'S')
				{ //if going south
					current.first++;
				}
				else if (matrix[current.first][current.second] == 'W')
				{ //if going west
					current.second--;
				}
				else if (matrix[current.first][current.second] == 'E')
				{ //if going east
					current.second++;
				}
				if (current.first<0 || current.first>row - 1 ||
					current.second<0 || current.second>col - 1)
				{ //if exit
					going = false;
					cout << count << " step(s) to exit" << endl; //print steps
				}
			}
			else //if loop hit
			{
				going = false;
				pair <int, int> loopStart; //creates pair at robots postion
				loopStart.first = current.first; //which must be start of loop
				loopStart.second = current.second;
				current.first = 0; //reset robot to starting position
				current.second = start - 1;
				int befLoop=0; //steps before the loop
				int loop=0; //steps in the loop
				while (current != loopStart) //before robot gets to loop
				{
					befLoop++; //record step
					if (matrix[current.first][current.second] == 'N')
					{ //if north
						current.first--;
					}
					else if (matrix[current.first][current.second] == 'S')
					{ //if south
						current.first++;
					}
					else if (matrix[current.first][current.second] == 'W')
					{ //if west
						current.second--;
					}
					else if (matrix[current.first][current.second] == 'E')
					{ //if east
						current.second++;
					}
				}
				bool first = true; //first letter in loop
				while (current != loopStart||first==true) //until loop is made
				{
					first = false;
					loop++; //record step in loop
					if (matrix[current.first][current.second] == 'N')
					{ //if north
						current.first--;
					}
					else if (matrix[current.first][current.second] == 'S')
					{ //if south
						current.first++;
					}
					else if (matrix[current.first][current.second] == 'W')
					{ //if west
						current.second--;
					}
					else if (matrix[current.first][current.second] == 'E')
					{ //if east
						current.second++;
					}
				}
				cout << befLoop << " step(s) before a loop of " << loop <<
					" step(s)" << endl; //print steps
			}	
		}
		cin >> row; //get next case's values
		cin >> col;
		cin >> start;
	}
}