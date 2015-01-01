/*
ID: hwchiu1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_COMBINATION 8
#define REPEAT_BIT 6

using namespace std;

//There are 1REPEAT_BIT combinations of buttons (1,2,3,4) and some of them is same.
//12 = 3, 13 =2, 23 = 1
//123 = 0, 124 = 34, 134 =24 , 234 = 14
//1234 = 4

//We have only MAX_COMBINATION unique combinations
//1, 2, 3, 4
//14, 24, 34
//0

//Since the rules of the button, the lamps will repeats every REPEAT_BIT lamps (button 4 is 3K+1, button 2 is 2K+1, button 3 is 2K), the LCM is REPEAT_BIT
//Hence we only need to record REPEAT_BIT lamps for each combination.
bool lamps[MAX_COMBINATION][REPEAT_BIT] = { //order by it binary numbers
	{0,0,0,0,0,0}, //1
	{0,0,1,1,1,0}, //34
	{0,1,0,1,0,1}, //2
	{0,1,1,0,1,1}, //4
	{1,0,0,1,0,0}, //14
	{1,0,1,0,1,0}, //3
	{1,1,0,0,0,1}, //24
	{1,1,1,1,1,1} //0
};

typedef enum {
	OFF = 0,
	ON = 1,
	DONT_CARE = 2
} STATUS;

//C = 1, we have 4 choices, (1,2,3,4)
//C = 2, we have 7 choices, (0,1,2,3,14,24,34)
//C >= 3, we have MAX_COMBINATION choices, (all)

int N,C;

int main() {
	bool find = false;
	bool used[MAX_COMBINATION] = {0}; //indicate which combination will be used, it is dependent on the C.
	STATUS status[REPEAT_BIT];
	int input;
    ofstream fout ("lamps.out");
    ifstream fin ("lamps.in");

	for (int i = 0; i < REPEAT_BIT; i++ ){
		status[i] = DONT_CARE;
	}
	
	fin >> N;
	fin >> C;

	//Assign used
	if (0 == C) {
		used[7] = true;
	} else if (1 == C) {
		used[0] = used[2] = used[3] = used[5] = true;
	} else if (2 == C) {
		used[0] = used[1] = used[2] = used[4] = used[5] = used[REPEAT_BIT] = used[7] = true;
	} else if (3 <= C) {
		used[0] = used[1] = used[2] = used[3] = used[4] = used[5] = used[REPEAT_BIT] = used[7] = true;
	}

	while ( fin >> input && -1 != input) {
		status[(input-1) % REPEAT_BIT] = ON;
	}

	while ( fin >> input && -1 != input) {
		if (ON == status[(input-1) % REPEAT_BIT]) {
			goto END;
		}
		status[(input-1) % REPEAT_BIT] = OFF;
	}

	for (int i = 0; i < MAX_COMBINATION; ++i) {
		if (false == used[i]) {
			continue;
		}

		bool correct = true;
		for (int j = 0; j < REPEAT_BIT; ++j) {//since 10<=N, we can only check REPEAT_BIT bits
			if (DONT_CARE != status[j] && (int)status[j] != lamps[i][j]) {
				correct = false;
				break;
			}
		}

		if (true == correct) {
			find = true;

			for(int j = 0 ; j < N; ++j) {
				fout << lamps[i][j%REPEAT_BIT];
			}
			fout << endl;
		}

	}


END:	
	if (!find) {
		fout << "IMPOSSIBLE"<<endl;
	}
    return 0;
}
