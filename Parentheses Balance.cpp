/*

Zac Conley : Parentheses Balance : 673 : acdczlc

Data structure required : Stacks, strings

Tricks of the trade : iterate through input and compare

*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
bool compare(char, char,bool); //function to check type of parentheses
int main()
{
	int cases; //number of strings
	cin >> cases;
	cin.ignore(); //skip to next line
	for (int i = 0; i < cases; i++) 
	{
		stack<char> balancer; //stack of parentheses
		string parentheses;
		getline(cin, parentheses); //gets line of input
		bool fail = false; //if fail is true outputs no
		for (int j = 0; j < parentheses.size(); j++) //iterate through line
		{
			if (parentheses[j] == '(' || parentheses[j] == '[')
			{ //pushes ( or [
				balancer.push(parentheses[j]);
			}
			else if (parentheses[j] == ')'&& balancer.empty() == false)
			{ //if ) and stack is empty, checks that popped element is a
				//parentheses of the same type
				char x;
				x = balancer.top();
				balancer.pop();
				fail=compare('(', x,fail);

			}
			else if (parentheses[j] == ']'&& balancer.empty()==false)
			{//if ] and stack is empty, checks that popped element is a
				//parentheses of the same type
				char x;
				x = balancer.top();
				balancer.pop();
				fail = compare('[', x,fail);
			}
			else if ((parentheses[j] == ')'&& balancer.empty() == true)||
				(parentheses[j] == ']'&& balancer.empty() == true))
			{ // if stack is empty and an end piece is reached it fails
				fail = true;
			}
		}
		if (balancer.empty() == true && fail==false)
		{ //if stack is empty and no failure
			cout << "Yes" << endl;
		}
		else
		{ //if stack is not empty or if there was failure
			cout << "No" << endl;
		}
	}
}
//Compare function checks to see if a parentheses or bracket is of
//the same type as the item at the top of the stack.
//If so, nothing happens. If it is not, the line fails.
bool compare(char x, char y,bool fail)
{
	if(x!=y)
	{
		fail = true;
	}
	return fail;
}