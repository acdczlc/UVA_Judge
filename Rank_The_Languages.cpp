/*

Zac Conley : Rank The Languages : 10336 : acdczlc

Data structure required : Vectors and Strings

Tricks of the trade : Use methods shown in class to visit every letter

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void CleanBlob(int, int, vector<vector<char>> &,char);
char CleanBlob(int, int, vector<vector<char>> &);

int main() {
	int cases; //number of cases
	cin >> cases;
	int height; //height of each case
	int width; //width of each case
	string line; //current line for filling with border
	for (int i = 0; i < cases; i++)
	{
		vector<int> table(150, 0); //table for counting
		cin >> height; //get height and width of each case
		cin >> width;                   //leave room for border
		vector<vector<char>> graph(height+2, vector<char>( width+2));
		for (int r = 0; r < height+2; r++)
		{
			for (int c = 0; c < width+2; c++) //fill graph with .
			{
				graph[r][c] = '.';
			}
		}
		for (int l = 0; l < height; l++) //fill graph with border around it
		{
			cin >> line;
			for (int r = l+1; r < height + 2; r++)
			{
				for (int c = 1; c < width + 2; c++)
				{
					
					if (r!=height+1&&c != width+1) //add letters
					{
						graph[r][c] = line[c - 1];
					}
				}
			}
		}
		for (int r = 1; r < height + 1; r++) 
		{  //for each value in graph
			for (int c = 1; c < width + 2; c++)
			{  //look for letters in state
				char ch = CleanBlob(r, c, graph);
				table[ch]++; //increment found letters
			}
		}
		cout << "World #" << i + 1 << endl; //case no+1
		for (int loop = 0; loop < 150; loop++) //for each letter in table
		{
			int max = 0; //set max number and associated letter
			char maxletter;
			bool maxfound = false; //if a max is found, if not you are done
			for (int val = 0; val < 150; val++) 
			{
				if (table[val] > max && val!=35) //if a letter has most states
				{                                // and is not a #
					max = table[val]; //largest number of states
					maxletter = val; //saves letter that has most states
					maxfound = true; //a max was found
				}
			}
			if (maxfound == true) //if a max was found
			{
				table[maxletter] = 0; //set that state to 0 and print the state
				cout << maxletter << ": " << max << endl;
			}
		}
	}
}
//function you showed us in class
void CleanBlob(int r, int c, vector<vector<char>>&graph, char ch)
{
	if (graph[r][c] != '.') //if not visited state
	{
		graph[r][c] = '.'; //visit state
		if (graph[r + 1][c] == ch) //if more of state below
		{
			CleanBlob(r + 1, c, graph, ch);
		}
		if (graph[r - 1][c] == ch) //if more of state above
		{
			CleanBlob(r - 1, c, graph, ch);
		}
		if (graph[r][c + 1] == ch) //if more of state right
		{
			CleanBlob(r, c + 1, graph, ch);
		}
		if (graph[r][c - 1] == ch) //if more of state left
		{
			CleanBlob(r, c - 1, graph, ch);
		}
	}
}

char CleanBlob(int r, int c, vector<vector<char>>&graph)
{
	char ch = graph[r][c]; //save char in graph
	if (ch!='.')  //if not border or visited state
	{
		CleanBlob(r, c, graph, ch); //start searching
		return ch; //return letter of state
	}
	else
	{
		return '#'; //return # to show no state
	}
}
