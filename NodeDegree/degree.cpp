// The degree of a node is the amount of outgoing or incoming paths from and to that node
// Example: node 1 has a path to 2 and 3, therefore, node 1 has a degree of 2 and nodes 2 and 3 have a degree of 1
// Input will consist of a file starting with number N (number of nodes), followed by the paths
// Ex:
// 3
// 1 2
// 1 3
// Meaning there are 3 nodes (1, 2, 3) and we have the same adjacencies as the example above
// Output should be the degree of each node

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
	int count, a, b;
	ifstream input("input.txt");

	if(input){
		input >> count;
		vector<int> paths(count, 0);	// List with N zeros (N == count)
		while(input >> a >> b){
			paths[a]++;					// Adding degree to first
			paths[b]++;					// and second nodes
		}
		for(int i = 1; i <= count; i++){
			cout << "Node " << i << " has a degree of " << paths[i] << "." << endl;
		}
	}else{
		cerr << "Input.txt was not successfully opened." << endl;
	}
}