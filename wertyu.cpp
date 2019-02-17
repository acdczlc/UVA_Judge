/*

Zac Conley : WERTYU : 10082 : acdczlc

Data structure required : Array for keys

Tricks of the trade : compare input string to array

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	const char keys[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ nn"; //all keys
	string line; //input line
	int index=0;
	bool found = false; //if a key has been found in the array
	while (getline(cin, line)) //gets next line
	{
		int size = line.length(); //size of input
		for (int i = 0; i < size; i++)
		{
			found = false; 
			index = 0;
			while (found == false) //while not found in array
			{
				if (line[i] == keys[47]) //if char is a space
				{
					found = true;
				}
				else if (line[i] == keys[index])
				{
					line[i] = keys[index - 1]; //get char to the left
					found = true;
				}
				else index++;
			}
		}
		cout << line<<endl; //prints final line
	}
	
}

