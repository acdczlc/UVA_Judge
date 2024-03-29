/*

Zac Conley : Rails : 514 : acdczlc

Data structure required : Queue, Stack

Tricks of the trade : use queues for entry and output
 stacks for middle stack
*/
#include <iostream>
#include <stack>
#include<queue>
using namespace std;

int main()
{
	int length; //lenght of input lines
	cin >> length;

	int temp = 1; //hardcoded value to start the loop
	bool fail = false; //if a second 0 in a row is detected
	bool pass = false; //after first pass helps with input
	while (fail == false)
	{

		while (temp != 0) //while next line is not 0
		{

			queue<int> entry; //1 2 3 4 5 ... queue
			queue<int> output; //output queue
			stack<int> stacker; //middle stack

			if (pass == false) //runs first pass through only
			{
				cin >> temp;
			}
			for (int i = 1; i < length + 1; i++) //fills entry queue with
			{                                    // 1 2 3 4 5 ...
				entry.push(i);
			}
			int x;
			output.push(temp); //fills output queue with temp
			for (int i = 0; i < length - 1; i++) //fills rest of output queue
			{
				cin >> x;
				output.push(x);
			}

			while (entry.empty() == false) //while entry queue contains numbers
			{
				if (entry.front() == output.front()) //if first number is first
				{                         //in output deletes both and moves on
					entry.pop();
					output.pop();
				}
				else if (stacker.empty() == false && stacker.top() ==
					output.front()) //if number on top of stack is first in 
				{                   //output deletes both and moves on
					stacker.pop();
					output.pop();
				}
				else if (entry.front() != output.front())
				{ //if front of entry is different than front of output and 
					int x = entry.front(); //top of stack is different 
					entry.pop();           //stores front of entry in stack
					stacker.push(x);
				}

			}
			bool fail = false; // checks for 2 0's in a row
			while (stacker.empty() == false && fail == false)
			{ //while stack is not empty and not failing

				if (stacker.top() == output.front())
				{ //if top of stack is front of output
					stacker.pop(); //pop both and move on
					output.pop();
				}
				else if (stacker.top() != output.front())
				{ //if stack does not match output cout no
					fail = true;
				}
			}
			if (fail == true)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes" << endl;
			}
			pass = true;
			cin >> temp;

		}
		cin >> length;
		cin >> temp;
		if (length == 0)
		{
			fail = true;
		}
		cout << endl;
	}
}
