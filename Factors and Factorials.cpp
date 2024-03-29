/*
Zac Conley : Factors and Factorials : 160 : acdczlc

Data structure required : Iomanip,Bitset,Vectors

Tricks of the trade : Use function to get all factors of a factorial number,
and use iomanip for printing output
*/
#include <iostream>
#include <iomanip> //used for spacing
#include <bitset> //used in seive function
#include <vector> //stores all primes
using namespace std;
long long sieve_size; //size of sieve
bitset<10000010> bs; //bitset used in sieve function
vector<int> primes; //vector of all primes
void sieve(long long upperbound); //book function
vector<int> primeFactors(long long N);//book function
int main() {
	ios_base::sync_with_stdio(false); //disables sync between c and c++ streams
	cin.tie(NULL); //unties cin from cout
	sieve(100); //gets all primes inside 100
	int inp; //input
	vector<int>factors; //vector for storing factors
	cin >> inp;
	while (inp != 0) //while there are more cases
	{
		factors = primeFactors(inp); //gets all factors and stores in vector
		int maximum = 0;  //largest factor
		for (int i = 0; i < factors.size(); i++) //finds largest factor
		{
			if (factors[i] > maximum) //replace max with current factor
			{
				maximum = factors[i];
			}
		}
		int endspot=0; //location of max factor
		for (int i = 0; i < primes.size(); i++) //finds where max factor is in
		{                                       //the list of primes
			if (primes[i] == maximum)
				endspot = i; //saves location
		}
		
		vector <int> res; //results vector that will be printed
		for (int i = 0; i <= endspot; i++) 
		{
			int count = 0; //counts number of times a factor appears in case
			for (int j = 0; j < factors.size(); j++)
			{
				if (factors[j] == primes[i]) //if factor is equal to 
				{      //the factor that is currently being counted
					count++; //increment counter
				}
			}
			res.push_back(count); //push back the number of times factor appears
		}
		cout << setw(3) << inp << "! ="; //uses iomanip to display number                              
		for (int i = 0; i < res.size(); i++) //print loop
		{
			if(i==15) //if number in 16th position, indents
			{
				cout << endl << setw(6) << " ";
			}
			cout << setw(3)<< res[i]; //prints next number in set
		}
		cout << endl; //blank line between inputs
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
//modified function from the book p. 213 function now returns the factors of the
//factorial of the input, instead of returning only the input's factors.
vector<int> primeFactors(long long N) {   
	vector<int> factors;  //vector for storing all factors   
	for (int i = N; i > 1; i--) //runs for all factorials not just input
	{
		int x = i; //copies i since it is manipulated later
		long long PF_idx = 0, PF = primes[PF_idx];//gets first prime number
		while (x != 1 && (PF * PF <= x)) { //stop at sqrt of x
			while (x % PF == 0) //while x is divisible by current prime
			{
				x /= PF; //decrease x
				factors.push_back(PF); //add prime to factor list
			}
			PF = primes[++PF_idx]; //get next prime in list
		}
		if (x != 1) factors.push_back(x); //add x as factor
	}
	return factors; //return all factors
}