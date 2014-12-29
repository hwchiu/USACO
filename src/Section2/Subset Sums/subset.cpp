/*
ID: hwchiu1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define MAXN 40
#define MAX 781
using namespace std;
/*
 * DP[i][j] = how many records which sums up to j when we use the number from {1~i}
 * DP[i][j] = DP[i-1][j] + DP[i-1][j-i] if j > i// with i or without i 
 * else DP[i][j] = DP[i-1][j];
 */

int DP[MAXN][MAX];
int main() {
	int N;
	int sum = 0;
	int count = 0;
	int tmp;
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");

	fin >> N;

	sum = (1+N)*N/2;
	if ( (sum%2)==1) {
		fout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAX; ++j) {
			DP[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; ++i) {
		tmp = (1+i)*i/2;
		for (int j = 1; j <= tmp; ++j) {
			if(j > i) DP[i][j] = DP[i-1][j] + DP[i-1][j-i];
			else DP[i][j] = DP[i-1][j];
		}
		DP[i][tmp] = 1;
	}

	fout <<DP[N][sum/2]<<endl;

    return 0;
}
