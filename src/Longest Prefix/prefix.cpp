/*
ID: hwchiu1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int *counter;
	vector<string> primitives;
	string input;
	string prefix; 
    ofstream fout ("prefix.out");
    ifstream fin ("prefix.in");

	while(getline(fin, input)) {
		if (1 == input.length() && '.' == input[0]) {
			break;
		}

		string temp;
		stringstream ss(input);
		while(getline(ss, temp, ' ')) {
			primitives.push_back(temp);
		}
	}

	while(getline(fin, input)) {
		prefix += input;
	}

	counter = new int[prefix.length()+1];

	for (size_t i = 0; i <= prefix.length(); ++i) {
		counter[i] = 0;
	}


// F(X) = L + F(X+L), try to match the data from tail to head
	for (int i = prefix.length()-1; i >= 0; --i) {
		for(size_t j =0; j < primitives.size(); ++j) {
			bool match = true;
			string &primitive = primitives.at(j);
			//try to match
			if ((primitive.length() + i -1) >= prefix.length()) {
				continue;
			}

			for(size_t k =0; k < primitive.length(); ++k) {
				if (prefix[i + k] != primitive[k]) {
					match = false;
					break;
				}
			}
			if (!match) {
				continue;
			}

			int tarLen = i + primitive.length();
			if (counter[i] < counter[tarLen] + (int)primitive.length()) {
				counter[i] = counter[tarLen] + (int)primitive.length();
			}
		}

	}

	cout << counter[0] << endl;
	delete []counter;
    return 0;
}
