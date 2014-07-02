/*
ID: hwchiu1
PROG: beads
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
	int num,max_ans=-1;
	int left,right;
	int ind_left,ind_right;
	char curr;
	char* data;
	fin >> num;
	data = new char[num];
	for(int i=0;i<num;++i){
		fin >> data[i];
	}
	for(int i=0;i<num;++i){
		left = right =1;
		curr = data[i+1];
		//right,
		for(int j=i+2;right < num-1;++j,++right){
			ind_right = j%num;
			if ( curr == 'w')  curr = data[ind_right];
			else if( data[ind_right] != curr && data[ind_right] !='w' ) break;
		}

		curr = data[i];
		//left
		for(int j=i-1;(left+right) < num;--j,++left){
			ind_left = (j+num)%num;
			if ( curr == 'w') curr = data[ind_left];
			else if( data[ind_left] != curr && data[ind_left] !='w' ) break;
		}
		max_ans = max(max_ans,left+right);

	}
	fout<<max_ans<<endl;
    return 0;
}
