/*
ID: hwchiu1
PROG: friday
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
void addDays(int& days,int add){
	days+=add;
	days%=7;
}

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
	int days[11]={3,0,3,2,3,2,3,3,2,3,2};
	int ans[7]={0};
	int years;
	int day = 0;
	int leap;
	fin >> years;
	for(int i=0;i<years;++i){
		leap = 0;
		//for Jan
		//1/1~1/13 , (13-1)%7 = 5;
		addDays(day,5);
		ans[day]++;
		if( ( 0 == i%4 && 0 !=i%100) || i==100) //N=0~400 --> 1900~2300, only 2000 need to watch out. 2000-1900 = 100,
			leap = 1;
		for(int j=0; j<11;++j){
			addDays(day,days[j]);
			if( 1 == j && leap)
				addDays(day,1);
			ans[day]++;
		}
		//compute the rest Dec
		addDays(day,(31-13+1));
	}
	fout<<ans[5]<<" ";
	fout<<ans[6]<<" ";
	fout<<ans[0]<<" ";
	fout<<ans[1]<<" ";
	fout<<ans[2]<<" ";
	fout<<ans[3]<<" ";
	fout<<ans[4]<<endl;
    return 0;
}
