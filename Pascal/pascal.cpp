// Writing Pascal's triangle on a file

#include <iostream>
#include <fstream>

using namespace std;

long factorial(int n){
	if(n > 1){
		return n * factorial(n-1);
	} else {
		return 1;
	}
}

int main(){
    int n;

    cout << "Number of rows: ";
    cin >> n;

    if(n > 13){
    	cout << "Triangle Structure Compromised but Still Readable..." << endl;
    	if(n > 21){
    		cout << "Number too big. Have mercy! (presenting 21 -> max)" <<endl;
    		n = 21;
    	}
    }

    if(cin.fail()){
    	cerr << "Number of rows MUST be and INT!" << endl;
    	return 1;
    }

    ofstream results("results.txt");

    if(results){
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j <= (n - i - 2); j++){
    			results << "\t";
    		}
    		for(int k = 0; k <= i; k++){
    			results << factorial(i) / (factorial(k) * factorial(i-k)) << "\t\t";
    		}
    		results << "\n";
    	}
    	cout << "Process Completed." << endl;
    } else{
    	cerr << "Could not create 'results.txt' file." << endl;
    }

	return 0;
}