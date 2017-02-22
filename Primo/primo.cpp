// Utilize Sieve of Eratosthenes' pseudocode to find all primes up to a certain inputted value
// Should output to a file with each number
//
// Pseudocode:
//
// Input: an integer n > 1
// Let: A be an array of Boolean values, indexed by integers 2 to n, initially all set to true
// 
// for i = 2, 3, ..., not exceding sqrt(n):
//		if A[i] is true:
//			for j = i², i²+i, i²+2i, ..., not exceeding n:
//				A[j] := false.
//
// Output: all i such that A[i] is true
//
// I have decided to rebuild my previous implementation due to several inefficiencies 
// What used to struggle past 200M now has, at least, been tested to 10B
// Considering data type used "unsigned long int", it's theoretically possible
// to achieve primes up to 18,446,744,073,709,551,615 although machine constraints are 
// more than likely.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	unsigned long int N;
	cout << "Input number: ";
	cin >> N;

	/*
	Calling sqrt() only once to avoid doing it during the loop.

	N casted to double since sqrt doesn't really take an int for arg
	but rather is overloaded to allow that behaviour.
	*/
	unsigned long int sz = (int)sqrt((double)N);

	/*
	Previous implementation had vector<pair<int, bool>> that I considered very poorly 
	optimized code for the problem at hand.

	By doing it this way, no need for calls on pairs or unnecessary memory usage from it. 

	Also avoid the loop to fill in the vector's numbers, which is nice.
	*/
	vector<bool> primes (N, true);


	/*
	Besides the already mentioned single-use sqrt() function I skip even numbers since,
	by their own definition, none of them will ever be a prime.

	This reduces calculations by half and will, obviously, optimize the previous implementation
	that looped through all numbers from 2 to N (like demonstarted in the pseudocode).
	*/
	for(unsigned long int i = 3; i < sz; i += 2){
		if(primes[i])
			for(unsigned long int j = i * i; j < N; j += i)
				primes[j] = false;
	}

	cout << "*** Completed! ***" << endl;

	/*
	Commented code below works but should only be used for now so high numbers N < 500000000 for
	time reasons.

	Reason I opted to output numbers to the console rather than to a file was because for very 
	high number like the example above, regular text editors could not open the text file with 
	something like 500Mb (example for 1B).

	Uncommented code will output the biggest prime below N. This is because I wanted to see if I 
	could get all primes below any N (the biggest prime only came into place for N > 1B, for 
	example).

	Uncomment commented code at your own risk if trying extremely high numbers.
	*/

	//cout << 2 << endl;
	unsigned long int biggest = 0;

	// Again, we skip even indexes since they won't be primes anyways.
	for(unsigned long int i = 3; i < N; i += 2)	
		if(primes[i])
			biggest = i;
			//cout << i << endl;

	cout << "Biggest prime found: " << biggest << endl;

	return 0;
}