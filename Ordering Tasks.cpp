/*
Zac Conley : Ordering Tasks : 10305 : acdczlc

Data structure required : vectors, queue

Tricks of the trade : Keep count of the number of dependencies, and use them to
print in correct order.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int tasks; //input
	int relations;
	int task1, task2; //used later for input
	cin >> tasks;
	cin >> relations;
	while (tasks > 0 || relations > 0) //while not reading in 0 0
	{
		vector<vector<int>>order(101, vector<int>(101)); //for relations
		vector<int> counter(101,0); //keeps count fo number of dependencies
		vector <int> sorted; //displays answer later on
		for (int i = 0; i < relations; i++) //for each relation get input
		{
			cin >> task1;
			cin >> task2;
			counter[task2]++; //add a dependency to the task that comes second
			order[task1].push_back(task2); //add relation
		}
		queue <int> q; //queue to determine order
		for (int i = 1; i <= tasks; i++) 
		{
			if (counter[i] == 0) //if there are no dependencies, add to queue
			{
				q.push(i);
			}
		}
		int num,x; //ints used later
		while (q.empty()==false) //while there are nums in the queue
		{
			num = q.front(); //get first number in queue
			sorted.push_back(num); //add number to print vector
			q.pop(); //remove number from queue
			for (int i = 0; i < order[num].size(); i++) 
			{
				x = order[num][i]; 
				counter[x]--; //remove a dependency
				if (counter[x] == 0) //if no more dependencies,
				{
					q.push(x); //add the number to queue
				} //else keep going until no more dependencies
			}
		}
		for (int i = 0; i < sorted.size(); i++) //print loop
		{
			cout << sorted[i]; //print number from vector
			if (i != sorted.size() - 1) //add space if not last number
			{
				cout << " ";
			}
		}
		cout << endl; //next line
		cin >> tasks; //get next values
		cin >> relations;
	}
}