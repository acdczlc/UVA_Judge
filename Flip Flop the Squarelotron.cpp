/*

Zac Conley : Flip Flop the Squarelotron : 10016 : acdczlc

Data structure required : Vectors 

Tricks of the trade : uses switch to choose operation

*/
#include <iostream>
#include <vector>
using namespace std;
void upsideDownFlip(vector<vector<int>> &matrix, int, int);
void leftRightFlip(vector<vector<int>> &matrix, int, int);
void mainDiagonalFlip(vector<vector<int>> &matrix, int, int);
void mainInverseDiagonalFlip(vector<vector<int>> &matrix, int, int);
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	cin >> cases; //number of cases
	for (int i = 0; i < cases; i++) //for each case
	{
		int size;
		cin >> size; //size of matrix n*n
		vector<vector<int>> M(size, vector<int>(size)); //declares matrix M
		for (int r = 0; r < size; r++) //fill matrix
		{
			for (int c = 0; c < size; c++)
			{
				cin >> M[r][c];
			}
		}
		
		int rings = ((size / 2)+(size % 2)); //calculates number of rings
		for (int x = 0; x < rings; x++) //for each ring
		{
			int ringops;
			cin >> ringops; //number of operations
			for (int y = 0; y < ringops; y++) //for each operation
			{
				int op;
				cin >> op; //enter operation
				switch (op) //choose operation
				{
				case 1: upsideDownFlip(M,size,x);
					break;       
				case 2: leftRightFlip(M, size, x);
					break;
				case 3: mainDiagonalFlip(M, size, x);
					break;
				case 4: mainInverseDiagonalFlip(M, size, x);
					break;
				}
			}
		}
		for (int r = 0; r < size; r++) //print matrix
		{
			for (int c = 0; c < size; c++)
			{
				cout << M[r][c];
				if (c != (size - 1)) //if last in line, doesn't need space
				{
					cout << " ";
				}
			}
			cout << "\n"; 
		}
	}
}
//flips matrix vertically
void upsideDownFlip(vector<vector<int>> &matrix, int size, int rings)
{
	for (int i = rings; i <= (size-rings-1); i++)
		swap(matrix[rings][i], matrix[(size - rings - 1)][i]);
	for (int i = rings + 1; i < (size - i - 1); i++) {
		swap(matrix[i][rings], matrix[(size - i - 1)][rings]);
		swap(matrix[i][(size - rings - 1)], matrix[(size - i - 1)][(size -
			rings - 1)]);
	}
}
//flips matrix horizontally
void leftRightFlip(vector<vector<int>> &matrix, int size, int rings)
{
	for (int i = rings; i <= (size - rings - 1); i++)
		swap(matrix[i][rings], matrix[i][(size - rings - 1)]);
	for (int i = rings + 1; i < (size - i - 1); i++) {
		swap(matrix[rings][i], matrix[rings][(size - i - 1)]);
		swap(matrix[(size - rings - 1)][i], matrix[(size - rings - 1)][(size - i - 1)]);
	}
}
//transposes matrix
void mainDiagonalFlip(vector<vector<int>> &matrix, int size, int rings)
{
	for (int i = rings; i <= (size - rings - 1); i++)
		swap(matrix[rings][i], matrix[i][rings]);
	for (int i = rings + 1; i < (size - rings - 1); i++)
		swap(matrix[(size - rings - 1)][i], matrix[i][(size - rings - 1)]);
}
//flips across rings
void mainInverseDiagonalFlip(vector<vector<int>> &matrix, int size, int rings)
{
	for (int i = rings; i <= (size-rings-1); i++)
		swap(matrix[rings][i], matrix[(size - i - 1)][(size - rings - 1)]);
	for (int i = rings + 1; i < (size - rings - 1); i++)
		swap(matrix[i][rings], matrix[(size - rings - 1)][(size - i - 1)]);
}