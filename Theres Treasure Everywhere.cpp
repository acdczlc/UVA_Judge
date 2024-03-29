/*
Zac Conley : There's Treasure Everywhere : 587 : acdczlc

Data structure required : string, pair

Tricks of the trade : iterate through string parsing input. Use pairs to track
location.
*/
#include <iostream>
#include <string> //used for input
#include <cmath>  //needed for sqrt
#include <iomanip> //used for printing 3 digits
using namespace std;

int main()
{
	string line; //line of input
	getline(cin, line); //gets line
	pair <double, double> location; //stores current location
	location.first = 0; //initializes to 0
	location.second = 0;
	int counter = 1; //map #
	while (line != "END") 
	{
		string length = line.substr(0,1); //gets 1st digit guaranteed to be int
		line.erase(0, 1); //erase int from string
		bool end = false; 
		while (end == false) //while there are more ints to be grabbed
		{
			if (line[0] > 47 && line[0] < 58)//if int add int to string
			{
				length += line[0]; //add int to string
				line.erase(0, 1); //erase int from input
			}
			else //if letter is reached/ no more ints
			{
				end = true;
			}
		}
		int dist = stoi(length);//turns distance string into number
		string direction = line.substr(0, 1); //gets 1st letter of direction
		line.erase(0, 1); //removes from input
		if (direction[0] == 'N' || direction[0] == 'S') //if N or S there could
		{                                //be a second letter like NW or SE
			if (line[0] != ','&&line[0]!='.') //if next char is a letter
			{
				direction += line.substr(0, 1); //add letter to direction
				line.erase(0, 1); //remove from input
			}
		}
		double res = dist * sqrt(2) / 2; //calculate distance for multi direction
		                                 //inputs like NW and SE
		if (direction == "N") //if North
		{
			location.second += dist;
		}
		else if (direction == "S")//if South
		{
			location.second -= dist;
		}
		else if (direction == "W")//if West
		{
			location.first -= dist;
		}
		else if (direction == "E") //if East
		{
			location.first += dist;
		}
		else if (direction == "NW")//if NorthWest
		{
			location.first -= res;
			location.second += res;
		}
		else if (direction == "NE")//if NorthEast
		{
			location.first += res;
			location.second += res;
		}
		else if (direction == "SW") //if SouthWest
		{
			location.first -= res;
			location.second -= res;
		}
		else if (direction == "SE") //if SouthEast
		{
			location.first += res;
			location.second -= res;
		}
		 double x = (location.first); //used to find distance between 0 and final
		 double y = (location.second); //point at the end of line
		 res = sqrt((x*x) + (y*y)); //distance formula
		if (line[0] == ',') //if one input ends
		{
			line.erase(0, 1);//gets rid of comma
		}
		else if (line[0] == '.') //if whole line ends
		{
			line.erase(0, 1); //removes .
			cout << "Map #"<<counter<<endl; //shows map count
			cout << setprecision(3) << fixed; //makes doubles print with .000
			cout << "The treasure is located at (" << location.first << "," <<
				location.second << ")." << endl;
			cout << "The distance to the treasure is "<<res <<"."<<endl;
			location.first = 0; //reset location
			location.second = 0;
			counter++; //increment map #
			getline(cin, line); //get next line
			cout << endl;
		}
	}
}