/*
ID: hwchiu1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define N 3
#define LIMIT 9
using namespace std;
int clocks[N][N];
//    A B C
//    D E F
//    G H I
vector<int> numbers;
void change(int *clock,bool forward){
	if(forward){
		if(12 == *clock)
			*clock = 3;
		else
			*clock +=3;
	}
	else{
		if( 3 == *clock)
			*clock = 12;
		else
			*clock -=3; 
	}
}

void change(int index,bool forward){
	switch(index){
		case 1: //ABDE
			change(&clocks[0][0],forward);
			change(&clocks[0][1],forward);
			change(&clocks[1][0],forward);
			change(&clocks[1][1],forward);
			return ;
		case 2://ABC
			change(&clocks[0][0],forward);
			change(&clocks[0][1],forward);
			change(&clocks[0][2],forward);
			return ;
		case 3://BCEF
			change(&clocks[0][1],forward);
			change(&clocks[0][2],forward);
			change(&clocks[1][1],forward);
			change(&clocks[1][2],forward);
			return ;
		case 4://ADG
			change(&clocks[0][0],forward);
			change(&clocks[1][0],forward);
			change(&clocks[2][0],forward);
			return ;
		case 5://BDEFH
			change(&clocks[0][1],forward);
			change(&clocks[1][0],forward);
			change(&clocks[1][1],forward);
			change(&clocks[1][2],forward);
			change(&clocks[2][1],forward);
			return ;
		case 6://CFI
			change(&clocks[0][2],forward);
			change(&clocks[1][2],forward);
			change(&clocks[2][2],forward);
			return ;
		case 7://DEGH	
			change(&clocks[1][0],forward);
			change(&clocks[1][1],forward);
			change(&clocks[2][0],forward);
			change(&clocks[2][1],forward);
			return ;
		case 8://GHI
			change(&clocks[2][0],forward);
			change(&clocks[2][1],forward);
			change(&clocks[2][2],forward);
			return ;
		case 9://EFHI
			change(&clocks[1][1],forward);
			change(&clocks[1][2],forward);
			change(&clocks[2][1],forward);
			change(&clocks[2][2],forward);
			return ;
	}
}
bool check(){
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			if(clocks[i][j]!=12)
				return false;
	return true;
}

bool backtracking(int depth,int used){
	if( used > 3)
		return false;
	bool ans = false;
	if( LIMIT < depth){
		if(check())
			return true;
		return false;
	}
	else{
		change(depth,true);
		numbers.push_back(depth);
		ans = backtracking(depth,used+1);
		if(ans)
			return true;
		numbers.pop_back();
		change(depth,false);
		ans = backtracking(depth+1,0);
		if(ans) 
			return true;
	}
	return false;
}


int main() {
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			fin >> clocks[i][j];
	backtracking(1,0);
	for(int i=0;i<numbers.size();i++){
		if( 0 == i)
			fout<<numbers[i];
		else
			fout<<" "<<numbers[i];
	}
	fout<<endl;
    return 0;
}
