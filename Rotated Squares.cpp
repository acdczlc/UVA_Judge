/*

Zac Conley : Rotated Squares : 10855 : acdczlc

Data structure required : Vectors, strings

Tricks of the trade : use rotate function and find function to reduce code

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void rotateM(vector< vector<char> > &matrix,int);
void findM(vector<vector<char>>&BigM, vector<vector<char>>&SmallM,
	int &counter, int, int);
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int bigsize, smallsize;
	cin >> bigsize; //size of large matrix
	cin >> smallsize; //size of small matrix
	while (bigsize != 0) //while input remains
	{
		vector<vector<char>> BigM(bigsize, vector<char>(bigsize));
		vector<vector<char>> SmallM(smallsize, vector<char>(smallsize));
		string inp; //input

		for (int r = 0; r < bigsize; r++) { //fill big matrix
			cin >> inp;
			for (int c = 0; c < bigsize; c++)
			{
				BigM[r][c] = inp[c];
			}
		}
		for (int r = 0; r < smallsize; r++) { //fill small matrix
			cin >> inp;
			for (int c = 0; c < smallsize; c++)
			{
				SmallM[r][c] = inp[c];
			}
		}
		int counter=0, counter90=0, counter180=0, counter270=0; //counters for find
		findM(BigM,SmallM,counter,bigsize,smallsize); //finds matrix with unrotated matrix
		rotateM(SmallM,smallsize);
		findM(BigM,SmallM,counter90,bigsize,smallsize); //finds matrix with 90 matrix
		rotateM(SmallM, smallsize);
		findM(BigM,SmallM,counter180,bigsize,smallsize); //finds matrix with 180 matrix
		rotateM(SmallM, smallsize);
		findM(BigM,SmallM,counter270,bigsize,smallsize); //finds matrix with 270 matrix
		cout << counter << " "<<counter90<<" "<<counter180<<" "<<counter270<<endl;
		cin >> bigsize;
		cin >> smallsize;
	}


}
/*
function rotates smaller matrix by 90 degrees clockwise
by transposing the matrix and then by switching the 
matrix's columns
*/
void rotateM(vector<vector<char>>&SmallM, int smallsize)
{
	char temp; //temporary storage
	for (int r = 0; r < smallsize; r++) { //transposes
		for (int c = r + 1; c < smallsize; c++) {
			temp = SmallM[r][c];
			SmallM[r][c] = SmallM[c][r];
			SmallM[c][r] = temp;
		}
	}
	for (int r = 0; r < smallsize; r++) { //swaps columns
		for (int c = 0; c < smallsize / 2; c++) {
			temp = SmallM[r][c];
			SmallM[r][c] = SmallM[r][smallsize - 1 - c];
			SmallM[r][smallsize - 1 - c] = temp;
		}
	}
}
/*
finds how many times the small matrix is in the big matrix
and increments a counter which is returned through reference
*/
void findM(vector<vector<char>>&BigM, vector<vector<char>>&SmallM,
	int &counter,int bigsize,int smallsize)
{
	int newsize=((bigsize-smallsize)+1); //sets bounds for search
	for (int r = 0; r < newsize; r++) //increment through big matrix
	{
		for (int c = 0; c < newsize; c++)
		{
			bool stop = false; //checksfor matches
			for (int minir = 0; minir < smallsize; minir++) 
			{ //increment through small matrix
				for (int minic = 0; minic < smallsize; minic++)
				{
					if (BigM[r + minir][c + minic] != SmallM[minir][minic])
					{ //if not in big matrix
						stop = true;
					}
				}
			}
			if (stop == false) //if match is found
			{
				counter++;
			}
			
		}
	}
}
