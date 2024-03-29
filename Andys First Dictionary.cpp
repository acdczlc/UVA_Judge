/*
Zac Conley : Andy's First Dictionary : 10815 : acdczlc
Data structure required : sets, strings
Tricks of the trade : use strings to search for capital and non capital letters
*/
#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	string input; 
	set<string> dict; //The dictionary used to store all the words
	while (cin >> input) //while !Eof
	{
		string word = ""; //initializes word to an empty string
		for (int i = 0; i < input.size(); i++) //while iterating through letters
		{
			if (input[i] > 96 && input[i] < 123) //if letter is lowercase
			{
				word += input[i]; //add letter to word
			}
			else if (input[i] > 64 && input[i] < 91) //if letter is capital
			{
				input[i] += 32; //make lowercase using ascii
				word += input[i]; //add letter to word
			}
			else if (word != "") //if word is not empty and something else is
			{                    //reached put word in dictionary
				dict.insert(word);
				word = ""; //reset word
			}
		}
		if (word != "") //if word is not empty add word to dictionary
			dict.insert(word);
	}
	for (set<string>::iterator it = dict.begin(); it != dict.end(); it++) 
		cout << *it << endl; //prints dictionary in alphabetical order
}