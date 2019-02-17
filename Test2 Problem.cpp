#include <iostream>
#include <array>
using namespace std;

int main() {
	array<int, 1000> arr;
	int num;
	int count=0;
	while (cin >> num)
	{
		arr[count] = num;
		count++;
	}
	int maxstart = 0;
	int maxend = 0;
	int maxlength = 0;
	for (int i = 0; i < count; i++)
	{
		int first = arr[i];
		int second, length = 0;
		int j = i;
		bool found = false;
		while(found==false && j<count)
		{
			if(arr[j] != first)
			{
				second = arr[j];
				found = true;
			}
			else { j++; }
		}
		//if (found == true)
		{
			bool fail = false;
			for (int x = i; x < count&&fail==false; x++)
			{
				if ( (arr[x] == first || arr[x] == second))
				{
					length++;
				}
				else {
					fail = true;
				}
			}
			if (length > maxlength)
			{
				maxlength = length;
				maxstart = i;
				maxend = maxstart + maxlength-1;
			}
		}
	}
	cout << "Length: "<<maxlength <<" Start Position: "<< maxstart << " End Position: "<<maxend;
}