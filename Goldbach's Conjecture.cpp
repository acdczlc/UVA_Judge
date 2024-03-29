/*
Zac Conley : Goldbach's Conjecture : 543 : acdczlc

Data structure required : bitset, vector, algorithm

Tricks of the trade : get all primes at once and 
then go through one prime at a time using binary 
search to see if there is a number that can add up to sum.
*/
#include <iostream>
#include <bitset> //used in seive function
#include <vector> //stores all primes
#include <algorithm> //needed for binary search
using namespace std;
long long sieve_size; //size of sieve
bitset<10000010> bs; //bitset used in sieve function
vector<int> primes; //vector of all primes
void sieve(long long upperbound); //book function
void SumAdd(long long n); //function to find 2 prime numbers that equal the input

int main() {
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	sieve(1000000); //sieves to 1 million as specified in problem
	long long inp; //input
	cin >> inp;
	while (inp != 0)//while there are more cases
	{
		SumAdd(inp); //gets two primes that add up to input
		cin >> inp; //gets next input
	}
}
// function from book that stores primes in vector
void sieve(long long upperbound) {          
	sieve_size = upperbound + 1;                
	bs.set();                                                
	bs[0] = bs[1] = 0;                                
	for (long long i = 2; i <= sieve_size; i++) if (bs[i]) {
		for (long long j = i * i; j <= sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);  
	}
}
//function finds two prime numbers that when added together equal input
void SumAdd(long long s)
{
	int i = 0; //starts at first prime value
	while( primes[i] <= s / 2) //checks primes that are up to half of input as
	{//those values of input added to another value would be larger than input
		int adder = s - primes[i]; //finds input - current prime 
		//checks if input-current prime is a prime aswell
		if (binary_search(primes.begin(), primes.end(), adder)==true)
		{ //if so prints values
			cout << s << " = " << primes[i] << " + " << adder << endl;
			return;
		}
		i++; //continue to next prime if adder is not a prime
	}
}