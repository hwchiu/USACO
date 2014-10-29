/*
ID: hwchiu1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

unsigned long computehamming(unsigned long src1, unsigned long  src2) 
{
	int tmp = src1 ^ src2;
	int count = 0;
	while(tmp){
		tmp = (tmp-1)&(tmp);
		++count;
	}
	return count;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
	unsigned long N,B,D;
	int limit;
	bool success;
	vector<int> used;
	fin >> N >> B >> D;
	limit = 1<<B;
	used.push_back(0);
	for(int i =1; i < limit; ++i) {
		success = true;
		for(size_t j = 0; j < used.size(); ++j) {
			if( computehamming(used[j],i) <D){
				success = false;
				break;
			}
		}
		if( true == success) {
			used.push_back(i);
			if ( N == used.size() ){
				break;
			}
		}
	}
	for(size_t i =0; i < used.size(); ++i) {
        if( 0 == i % 10){
            fout<<used[i];
        }else {
            fout<<" "<<used[i];
        }
        if( 0 == (i+1)%10){
            fout<<endl;
        } 

	}
	if( 0 != used.size() %10)
		fout<<endl;
    return 0;
}
