/*

Zac Conley : Hay Points : 10295 : acdczlc

Data structure required : maps, strings

Tricks of the trade : insert values into map and get their values when needed

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int words; //number of words
	int descriptions; //number of descriptions
	cin >> words;
	cin >> descriptions;
	map<string, int> wordvalues; //map that holds words and descriptions
	string word; //word that is read in
	int pay; //amount that is read in
	for (int i = 0; i < words; i++)
	{
		cin >> word;
		cin >> pay;  //read in job title and amount and put in map
		wordvalues.insert(pair<string, int>(word, pay));
	}
	string entry; //word in description
	map<string, int>::iterator it; //iterator to find if word is in map

	for (int i = 0; i < descriptions; i++)
	{
		cin >> entry; //get first word in description
		int count=0; //total amount
		while (entry != ".") //while description is not over
		{
			it = wordvalues.find(entry);//searches map for word
			if (it != wordvalues.end()) //if value found
			{
				count += wordvalues[entry]; //add value to total
			}
			cin >> entry; //get next word in description
		}
		cout << count<<endl; //output final total
	}

}

