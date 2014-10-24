/*
ID: hwchiu1
PROG: skidesign
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define SIZE 101
using namespace std;
int main() {
    ofstream fout ("skidesign.out");
    ifstream fin ("skidesign.in");
	int used[SIZE];
	int N,tmp,cost=0,ans = 0x7fffffff;
	fin >> N;
	for(int i = 0; i < SIZE ; ++i) {
		used[i] = 00;
	}
	for(int i = 0; i < N ; ++i) {
		fin >> tmp;
		used[tmp]++;
	}
	for(int i = 0; i < (100-17+1) ; ++i) {
		cost = 0;
		for(int j = 0; j < SIZE ; ++j) {
			if( 0 != used[j]) {
				if( j < i ) {
					cost += (i-j)*(i-j)*used[j];
				}
				else if( j > (i+17)){
					cost += (j-(i+17))*(j-(i+17))*used[j];
				}
			}
		}
		if( cost < ans ) {
			ans = cost;
		}
	}
	fout << ans <<endl;
    return 0;
}
