/*
ID: hwchiu1
PROG: combo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main() {
    ofstream fout ("combo.out");
    ifstream fin ("combo.in");
	int N;
	int farmer[3],master[3];
	set<vector<int> >used;
	fin >> N;
	fin >> farmer[0] >> farmer[1] >> farmer[2];
	fin >> master[0] >> master[1] >> master[2];

	for(int i=-2 ; i <= 2; ++i) {
		for(int j=-2; j<= 2; ++j) {
			for(int k=-2; k<=2; ++k){
				vector<int> combination;
				combination.push_back((i+farmer[0]+N)%N);
				combination.push_back((j+farmer[1]+N)%N);
				combination.push_back((k+farmer[2]+N)%N);
				used.insert(combination);
				combination.clear();
				combination.push_back((i+master[0]+N)%N);
				combination.push_back((j+master[1]+N)%N);
				combination.push_back((k+master[2]+N)%N);
				used.insert(combination);
			}
		}
	}
	fout << used.size()<<endl;
    return 0;
}
