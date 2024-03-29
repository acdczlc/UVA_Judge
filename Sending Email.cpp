/*
Zac Conley : Sending Email : 10986 : acdczlc

Data structure required : vector, pair, queue

Tricks of the trade : Use modified function from p. 148 to get distance
*/

#include <iostream>
#include <vector>
#include <queue>  //priority queue
#include <utility> //used for pair
using namespace std;

vector<int> Dijkstra(int, vector<vector<pair<int, int>>> &AdjList);

int main()
{
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	int cases;
	int n, m, s, t,s1,s2,w; //ints read
	cin >> cases; //get number of cases
	for (int caseno = 0; caseno < cases; caseno++) //for each case
	{
		cin >> n; //get values
		cin >> m;
		cin >> s;
		cin >> t;
		//declares Adjacency list of pairs to work with function from book
		vector<vector<pair<int, int>>> AdjList(n, vector<pair<int, int>>(0));
		for (int line = 0; line < m; line++) //for each of the m lines
		{
			cin >> s1; //get servers and latency
			cin >> s2;
			cin >> w;
			AdjList[s1].push_back(pair<int, int>(s2, w)); //add edges both ways
			AdjList[s2].push_back(pair<int, int>(s1, w));
		}
		vector<int>distance;
		distance = Dijkstra(s, AdjList); //saves distance vector from function
		if (distance[t] != 2147483647) //if there is a valid distance
		{ 
			cout << "Case #"<<caseno+1<<": "<<distance[t]<<endl;
		}
		else { //if server is unreachable
			cout << "Case #" << caseno+1 << ": unreachable" << endl;
		}
	}
}
//Slightly modified function from p. 148 that uses Dijkstra's algorithm using the
//Priority key decrease modification explained in the book
vector<int> Dijkstra(int s, vector<vector<pair<int, int>>> &AdjList)
{
	vector<int> dist(20001, 2147483647); //initializes with max values
	dist[s] = 0;                    
	priority_queue<pair<int,int>, vector<pair<int,int>>,
		greater<pair<int,int>> > pq; //declare queue
	pq.push(pair<int,int>(0, s));
	while (!pq.empty()) {  // main loop
		pair<int,int> front = pq.top(); pq.pop(); //get shortest unvisited vertex
		int d = front.first, u = front.second;
		if (d == dist[u]) // this is a very important check
			for (int j = 0; j < (int)AdjList[u].size(); j++) {
				pair<int,int> v = AdjList[u][j]; // all outgoing edges from u
				if (dist[u] + v.second < dist[v.first]) {
					dist[v.first] = dist[u] + v.second; //relax operation
					pq.push(pair<int,int>(dist[v.first], v.first));
				}
			}
	}
	return dist; //returns distances vector to print
}