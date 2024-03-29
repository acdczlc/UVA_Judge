/*
Zac Conley : Stern-Brocot Tree : 11350 : acdczlc

Data structure required :  strings,pairs

Tricks of the trade : use recursion to find median
*/
#include <iostream>
#include <string>
#include <utility> //used for pairs and makepair

using namespace std;
pair<long long, long long> SBTree(string, pair<long long, long long>,
	pair<long long, long long>); //function decloration
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	cin >> cases; //number of cases
	pair <long long, long long> left(0, 1); //original left value
	pair <long long, long long> right(1, 0); //original right value
	pair <long long, long long> result; //output pair
	for (int i = 0; i < cases; i++)
	{
		string inp;
		cin >> inp; //string of RL's
		result=SBTree(inp, left, right);//start function with original values
		cout << result.first << "/" << result.second << endl; //ouput
	}
}
//function returns pair of middle values
pair<long long, long long> SBTree(string inp, pair<long long, long long> L,
	pair<long long, long long> R)
{
	char x; //first letter in string
	if (inp.length() != 0) //if string is not empty
	{
		x = inp[0]; //x is first letter
	}
	else //if string is empty x becomes an unused char to prevent the string
	{   //from being erased again later which was previously causing an error
		 x = 'x';
	}
	long long medianNum, medianDen; //median numerator and denominator
	medianNum = L.first + R.first; //median numerator=left numerator+right num
	medianDen = L.second + R.second;//median denominator=left denom+right denom
	pair <long long, long long> med; //pair to store median
	med = make_pair(medianNum, medianDen);//makes pair out of numbers
	if (x != 'x')//if string is not empty the first letter is erased
	{  //if it is empty nothing is done and it is not sent to function
		inp.erase(inp.begin());
	}
	if (x == 'L') //if next char is L 
	{             //traverse tree to left
		med = SBTree(inp, L, med);
	}
	else if (x == 'R') //if next char is R
	{                  //traverse tree to right
		med = SBTree(inp, med, R);
	}
	return med; //returns median pair
}