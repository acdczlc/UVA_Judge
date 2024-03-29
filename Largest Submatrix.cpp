/*
Zac Conley : Largest Submatrix : 836 : acdczlc
NOT ACCEPTED BY UVA- despite appearing right for all test cases tried 
Data structure required : Matrices and strings

Tricks of the trade : iterate through subarrays finding max number of 1's
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	cin >> cases;
	cin.ignore(); //skips blank line
	cin.ignore();
	string line; 
	for (int caseno = 0; caseno < cases; caseno++) //for each case
	{
		int N = 1; //size starts at 1 to put in matrix
		getline(cin, line); //gets input
		int x=line.length();
		int ones[26][26]; //array where ones are stored
		int answer[26][26]; //array to get answer
		for(int a=0; a<x; a++) //get next input line) //while case is going
		{
			for (int i = 1; i < line.length()+1; i++)  
			{
				ones[N][i] = line[i-1]-'0'; //convert char to int and put in arr
			}
			getline(cin, line); //gets input
			N++;
		}
		N--; //subtracts one to get size since size started at 1 originally
		int max_size = 0; //max size to print later
		for (int i = 1; i < N; i++) 
		{
			for (int j = 1; j <= N; j++)
			{
				if (ones[i + 1][j] == 1) //if next row number is a 1 
				{                        //add current row number to it
					ones[i + 1][j] = ones[i][j] + 1;
				}
			}
		}
		for (int i = 1; i <= N; i++) //iterate through one's array
		{                       //tracking the width of subarray's
			for (int j = 1; j <= N; j++)
			{
				int w = 1;
				for (int l = j - 1;ones[i][l]>=ones[i][j] && j!=0 ; l--)
				{ //increase width for answer
					w++;
				}
				for (int r = j + 1; ones[i][r] >= ones[i][j] && r <= N; r++)
				{ //increase width for answer
					w++;
				}
				answer[i][j] = w*ones[i][j]; //store size of subarray
				if (answer[i][j] > max_size) //if size of array is 
				{        //bigger than max size store current size
					max_size = answer[i][j];
				}
			}
		}
		cout << max_size << endl; //output
		if (caseno != (cases-1)) //if case is not final case
		{
			cout << endl; //print blank line
		}
	}
}