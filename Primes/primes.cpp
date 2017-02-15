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
// MAX RECORDED: 200000000

#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

int main(){
	int n;

	cout << "Input number: ";
	cin >> n;

	vector<pair<int, bool> > A;
	ofstream results("results.txt");

	for(int i = 2; i <= n; i++){
		A.push_back(make_pair(i, true));
	}

	for(int i = 2; i < sqrt(n); i++){
		if(A[i-2].second){
			for(int j = i * i; j < n; j += i){
				A[j-2].second = false;
			}
		}
	}

	for(int k = 0; k < A.size(); k++){
		if(A[k].second){ results << A[k].first << endl; }
	}

	return 0;
}