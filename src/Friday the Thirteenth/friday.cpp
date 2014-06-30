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
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int ans[7]={0}; //0 for saturday, 1 for sunday, 2 for monday, 6 for friday.
	int years;
	int day = 0;
	int leap;
	fin >> years;
	for(int i=0;i<years;++i){
		leap = 0;
		if( ( 0 == i%4 && 0 !=i%100) || i==100) //N=0~400 --> 1900~2300, only 2000 need to watch out. 2000-1900 = 100,
			leap = 1;
		for(int j=0; j<12;++j){ 
			ans[day]++;
			addDays(day,days[j]);
			if(j==1 && leap)
				addDays(day,1);
		}
	}
	for(int i=0;i<7;++i){
		if(i)
			fout<<" ";
		fout<<ans[i];
	}
	fout<<endl;
    return 0;
}
