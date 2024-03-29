/*
Zac Conley : The Jackpot : 10684 : acdczlc

Data structure required : vector

Tricks of the trade : Enter all bets into a vector and use a modified algorithm
from the book p. 104 to find the maximum streak.
*/
#include <iostream>
#include <vector> //used to store bets
using namespace std;

int main()
{
	int bets; //number of bets in each case
	cin >> bets; //gets first case bets
	
	while (bets != 0) //while != EOF
	{
		vector<int>bet(bets); //vector to store the bets of each case
		for (int i = 0; i < bets; i++)
		{
			cin >> bet[i]; //enter bets into a vector
		}
		int sum = 0, ans = 0;          //modified algorithm from book p. 104
		for (int i = 0; i < bets; i++) //for each bet in vector
		{
			sum += bet[i]; //add bet to sum
			if (sum > ans) //if sum is larger than current answer make the answer
			{              //the sum
				ans = sum;
			}
			if (sum < 0) //if the sum is negative reset the sum to 0
			{
				sum = 0;
			}
		}
		if (ans> 0) //if the largest streak is at least 1 print winnning message
		{
			cout << "The maximum winning streak is " << ans << "." << endl;
		}
		else { //if largest streak is 0 print losing streak
			cout << "Losing streak." << endl;
		}
		cin >> bets; //get the next case of bets
	}
}