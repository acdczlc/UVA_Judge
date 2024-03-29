/*
Zac Conley : Vertex : 280 : acdczlc

Data structure required : vector, queue, string, stringstream

Tricks of the trade : uses complicated input method to call BFS and print
unvisited nodes. program was printing blank line when no prints were requested
causing wrong answer*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

class graph
{
	int vertexes; //number of vertexes in graph
	vector<vector<int>> close; //class variable for nodes with edges to current
public:
	graph(int vertexes) //constructor, receives number of vertexes
	{
		this->vertexes = vertexes;
		vector<vector<int> > close(vertexes, vector<int>(vertexes));
		this->close = close; //fixes size of 2d vector and stores
	}
	void addEdge(int x, int y) 
	{
		close[x].push_back(y); //adds an edge from x to y
	}
	void BFS(int current) //BFS that then finds the unvisited nodes, and prints
	{                     //all of them
		vector<int> visit(vertexes); //a vector of all nodes that shows whether
		for (int i = 0; i < vertexes; i++) //or not they have been visited
		{
			visit[i] = 0; //marks all nodes unvisited
		}
		queue<int> q; //declares queue to store vertexes in
		q.push(current); //pushes current vertex to get loop to start
		while (q.empty()==false) //while values are in the queue
		{
			current = q.front(); //pops current vertex back out of the queue
			q.pop();
			for (int i = 0; i < close[current].size(); i++) 
			{  //for each node current shares an edge with
				int temp = close[current][i]; //get node
				if (visit[temp]==0)  //if node is not yet visited
				{
					visit[temp] = 1; //visit
					q.push(temp); //add node to queue
				}
			}
		}
		vector<int> counter; //vector to count the number of unvisited nodes
		for (int i = 1; i < this->vertexes; i++)
		{
			if (visit[i] == 0) //if node is not visited
			{
				counter.push_back(i); //add it to counter vector
			}
		}
		if (counter.size() != 0) //if the counter has a node in it
		{
			cout << counter.size() << " "; //cout size of counter
			for (int i = 0; i < counter.size(); i++) 
			{
				cout << counter[i]; //print each node in counter
				if (i != counter.size() - 1)
				{
					cout << " "; //if not last node print space
				}
			}
			cout << endl; //print endline for end of case
		}
		else {
			cout << "0" << endl; //if all nodes visited, print 0
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int v;  //read input
	string line; //input line
	getline(cin, line); //gets line of input
	v = stoi(line);
	while (v != 0) //while the number of vertexes is above 0
	{
			graph g(v+1); //declares graph
			bool stop = false; //stops if the end of case is reached
			int f; //used to add edge
			getline(cin, line); //gets line of input
			while ( stop == false) //while in a case
			{
				if (line[0] != '0') //if line is not 0
				{
					bool first = true; //first number in line
					stringstream ss(line); //stringstream the input
					string num;
					while (ss >> num) //put next number into string
					{
						if (num != "0")
						{
							int temp = stoi(num); //turn string to int
							if (first == true) //if first number in line
							{
								f = temp; //all edges will be added to f
								first = false; //now ints will not be first
							}
							else {
								g.addEdge(f, temp); //add edge to f
							}
						}
					}
					getline(cin, line); //get the next line of input
				}
				else { //if line is 0
					
					getline(cin, line); //gets the next line
					stringstream ss(line); //stringstreams the line
					int amount;
					string x;
					ss >> x; //finds the number of vals in the line
					amount = stoi(x);
					if (amount != 0) {
						for (int i = 0; i < amount; i++) //for each number in line,
						{                 //runs a BFS on that number
								   //at the end of bfs a loop prints unreached nodes
							ss >> x;
							int y = stoi(x);

							g.BFS(y);
						}
						getline(cin, line); //gets next line which is the amount of
						v = stoi(line);     //vertexes in the next graph
						stop = true; //stops the loop
					}
					else {
						getline(cin, line); //gets next line which is the amount of
						v = stoi(line);     //vertexes in the next graph
						stop = true; //stops the loop
				}
			}
		} 
	}
}