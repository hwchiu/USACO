/*
ID: hwchiu1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("palsquare.out");
bool checkPalin(string input){
	int n = input.size();
	for(int i=0;i<input.size()/2;++i){
		if(input[i] != input[n-i-1])
			return false;
	}
	return true;
}
char getBaseChar(int n){
	if( n < 10)
		return n+'0';
	else
		return 'A'+(n-10);
}

void PalindromesSquare(int n,int base){
	string baseString;
	string squareString;
	int tmp = n;
	n = n *n;
	while(n){
		squareString.push_back(getBaseChar(n%base));
		n/=base;
	}
	while(tmp){
		baseString.push_back(getBaseChar(tmp%base));
		tmp/=base;
	}
	if ( checkPalin(squareString) ){
		n = baseString.size();
		for(int i=0;i<baseString.size();++i)
			fout<<baseString[n-i-1];
		fout<<" "<<squareString<<endl;
	}
		
}

int main() {
    ifstream fin ("palsquare.in");
	int base;
	fin >> base;
	for(int i=1;i<=300;++i){
		PalindromesSquare(i,base);
	}
    return 0;
}
