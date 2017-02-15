// Reading from a text file
// Each line of the text file has 2 numbers
// First line contains Goldilocks' weight and maximum temperature
// Rest of the lines follow this scheme:
// First number: maximum weight of chair; Second number: Temperature of porridge
// If first integer is less than her weight, discard
// If second is heigher than her tolerance, discard

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
	if (argc < 2) { 
        cerr << "Usage: " << argv[0] << " FILENAME" << endl;
        return 1;
    }

    int weight, maxtemp;	// goldilocks vars
    int cW, cT;				// chair vars
    int chair = 0;
    bool found = false;
    string line;

	ifstream input(argv[1]);

	if(input){							// successful opening of file
		input >> weight >> maxtemp;		// read first line
		while(input >> cW >> cT){		// read all future lines
			chair++;
			if(cW >= weight && cT <= maxtemp){
				cout << chair << " ";
				found = true;
			}
		}
		if(!found){
			cout << "No suitable chairs found." << endl;
		}
		else{
			cout << endl;	// add end line after end of program
		}
	} 
	else{
		cerr << argv[1] << " was not successfully opened." << endl;
	}
	return 0;
}