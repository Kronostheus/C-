// MAIN IDEA: Using Letters in argv[1] are you able to form the word argv[2]?

// if argv[1] has less letters than argv[2], then no
// parsing through argv[1] we can get letter individually
// check every letter from argv[2] against array of letters
// if at the end, we managed to remove all letters from word, we got a match

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]){
	if (argc < 3) { 
        cerr << "Usage: " << argv[0] << " LETTERS WORD" << endl;
        return 1;
    }

    string letters = argv[1];
    string word = argv[2];
    int hits = 0;

    if(letters.length() < word.length()){
    	cout << "FALSE" << endl;
    	return 0;
    }

    vector<char> v(letters.begin(), letters.end());	// array with letters

    for(int i = 0; i < word.length(); i++){
    	if(find(v.begin(), v.end(), word[i]) != v.end()) {
    	/* v contains x */
    		vector<char>::iterator it = find(v.begin(), v.end(), word[i]);	//
			iter_swap(it, v.end() - 1);										// Erasing the letter word[i] from v
			v.erase(v.end() - 1);											//
			hits++;
			if(hits == word.length()){
				cout << "TRUE" << endl;
				break;
			}

		} else {
    	/* v does not contain x */
			cout << "FALSE" << endl;
			break;
		}
    }

	return 0;
}