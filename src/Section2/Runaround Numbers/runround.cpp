/*
ID: hwchiu1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool IsRunRound(const int n)
{
	static char input[10];
	bool isExist[10] = {0}; //1~9
	bool isUsed[10] = {0};
	int index = 0;
	int len;

	sprintf(input, "%d", n);
	len = strlen(input);

	//Check duplicate digit
	for (int i =0; i < len; i++) {
		if (true  == isExist[input[i]-'0']) {
			return false;
		}

		if ( 0 == input[i]-'0') {
			return false;
		}

		isExist[input[i]-'0'] = true;
	}

	//Check rotate
	for(int i =0; i<=len; i++) {
		if (true == isUsed[input[index] - '0']) {
			return index == 0 && i == len? true:false;
		}
		isUsed[input[index]-'0'] = true;
		index = (index + (input[index] - '0')) % len;
	}

	return false;
}


int main() {
	int N;
    ofstream fout ("runround.out");
    ifstream fin ("runround.in");

	fin >> N;

	for (;;N++) {
		if(IsRunRound(N)) {
			fout << N << endl;
			break;
		}
	}

    return 0;
}
