#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <cstdlib>
using std::malloc;

int find_max(const string& infilename);
void sieve(const int size, bool primes[]);

/**
* Read numbers from `infilename`, and if they are prime, output them to
* `outfilename`, separated by newlines.
*
* Arguments:
* - `size`: The size of (the number of elements in) the array.
* - `primes`: An array of boolean values, with each element set to `true` if
*   its index is prime, and `false` otherwise.
* - `infilename`: A string representing the file path to read from.
* - `outfilename`: A string representing the file path to write to.
*
* Returns:
* - 0 on success, or -1 on error.
*/

int main() {
	int max = find_max("C:\\Users\\ce-student\\Desktop\\input.txt");
	if (max == -1) {
		cout << "ERROR in `find_max()`" << endl;
		return 1;  // error
	}
	cout << max;

	bool * primes = (bool *) malloc( sizeof(bool) * (max+1) );
	sieve(max + 1, primes);
	
	system("PAUSE");
	return 0;  // success
}

int find_max(const string& infilename){ //Finding the max number
	int x, y = 0;
	ifstream infile(infilename);
	if (infile.is_open())
	{
		while (!infile.eof()){
			infile >> x;
			if (x >= y){
				y = x;
			}
		}
		infile.close();
	}
	
	return y;
}

void sieve(const int size, bool primes[]){ //finding the prime numbers
	for (int i = 0; i < size; i++){
		primes[i] = true;
	}

	primes[0] = false;
	primes[1] = false;
	for (int i = 2; i < size; i++){//outer loop looks for primes
		
		for (int g = i * 2; g < size; g += i){//inner loop marks the multiples of the primes
			primes[g] = false;
		}
	}
}

