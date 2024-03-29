/*
Zac Conley : Compromise : 531 : acdczlc

Data structure required :  Vectors, Strings, Matrices for DP

Tricks of the trade : Use DP to find longest set of words
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	string word; //input word
	while (cin >> word) //while there are more test cases
	{
		int size1 = 1; //size of 1st input
		int size2 = 1; //size of 2nd input
		vector<string> s1(101); //declares vector of strings for input
		vector<string> s2(101); //101 is used for the 100 words
		int common[101][101] = { 0 }; //declares DP matrices and sets one to 0's
		int matches[101][101];
		while (word != "#") //while words remain in set
		{
			s1[size1] = word; //add word to vector starting at pos 1
			size1++; //increment int keeping track of size of vector
			cin >> word; //get next word
		}
		cin >> word;
		while (word != "#") //while words remain in set
		{
			s2[size2] = word; //add word to vector starting at pos 1
			size2++; //increment int keeping track of size of vector
			cin >> word; //get next word
		}
		for (int r = 1; r < size1; r++) { //start at 1 
			for (int c = 1; c < size2; c++) {
				if (s1[r] == s2[c]) { //compare words to see if they are equal
					matches[r][c] = 0; //mark as found
					common[r][c] = common[r - 1][c - 1] + 1;
				}
				else if(s1[r]!=s2[c]) //if words are not equal
				{
					if (common[r - 1][c] <= common[r][c - 1]) {
						matches[r][c] = 1; //mark as not equal and go left a col
						common[r][c] = common[r][c - 1];
					}
					else if (common[r - 1][c] > common[r][c - 1]) { 
						matches[r][c] = 2; //mark as not equal and go up a row
						common[r][c] = common[r - 1][c];
					}
				}
			}
		}
		int row = size1 - 1; //start at end of DP Matrix
		int col = size2 - 1; //and work backwards adding words to string
		vector<string> answer;
		while (row>0 && col>0) { //while rows and columns are positive
			if (matches[row][col] == 0) //if words are equal
			{
				answer.push_back(s1[row]); //add word to start of vector
				row--; //vector will be printed in reverse order
				col--;//decrement row and col
			}
			else if (matches[row][col] == 1) //marked as not equal
			{
				col--; //decrement col going left
			}
			else if (matches[row][col] == 2) //marked as not equal
			{
				row--; //decrement row going up
			}
		}
		for (int i = answer.size() - 1; i >= 0; i--) //prints answer by iterating
		{                                         //backwards through vector
			cout << answer[i];
			if (i > 0) //added to prevent a blank at the end of each line
			{          //after causing 2 wrong answers
				cout << " ";
			}
		}
		if (size1 != 1&& answer.size()!=0) //prevents printing blank line if 
		{
			cout << endl;                  //case is empty
		}
	}
}