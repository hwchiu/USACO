/*
ID: hwchiu1
PROG: wormhole
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#define MAXSIZE 12
using namespace std;
int totalCount;
int N;
int position[MAXSIZE][2];
int nextHole[MAXSIZE];
int match[MAXSIZE];
bool used[MAXSIZE];
bool checkLoop()
{
	bool visited[MAXSIZE];
	int tmp;
	for(int i = 0; i < N ; ++i) {
		visited[i]=false;
	}
	for(int i = 0; i < N ; ++i) {
		if( -1 == match[i] || true == visited[i]) {
			continue;
		}
		tmp = i;
		while( -1 != tmp) {
			visited[tmp] = true;
			tmp = nextHole[match[tmp]];
			if( i == tmp ) {
				return true;
			}
		}
		
	}

	return false;
}

void solve(int index, int pairCount)
{
	if( true == used[index] ) {
		solve(index+1,pairCount);
		return ;
	}
	if( N/2 == pairCount) {
		if(checkLoop()) {
			++totalCount;
		}
		return ;
	}
	if( index >= N)
		return ;
	for(int i = 0 ; i < N ; i++) {
		if( true == used[i] || i == index) {
			continue;
		}
		used[i] = used[index] = true;
		match[i] = index;
		match[index] = i;
		solve(index+1,pairCount+1);
		match[i] = match[index] = -1;
		used[i] = used[index] = false;
	}

}
int main() {
    ofstream fout ("wormhole.out");
    ifstream fin ("wormhole.in");
	totalCount=0;
	fin >> N;
	for(int i = 0 ; i < N ; i++) {
		nextHole[i] = match[i] = -1;
		used[i] = false;
	}
	for (int i = 0 ; i < N; i++) {
		for(int j = 0; j < 2; j++) {
			fin >> position[i][j];
		}
	}
	for(int i = 0 ; i < N; i++) {
		int temp = INT_MAX;
		for(int j = 0; j < N; j++) {
			if( i == j ) {
				continue;
			}
			if( position[i][1] == position[j][1] && (position[j][0] > position[i][0])) {
				if( (position[j][0] - position[i][0]) < temp) {
					temp = position[j][0] - position[i][0];
					nextHole[i] = j;
				}
			}
		}
	}
	solve(0,0);
	fout<<totalCount<<endl;
    return 0;
}
