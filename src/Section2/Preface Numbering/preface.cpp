/*
ID: hwchiu1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
int N;
map<char, int> record;
void computeNumber(int &input, int &output, const int &value)
{
	output = input / value;
	input = input % value;
}

void computeRomanNumber(int N)
{
	int tmp;
	while( 0 <N ) {
		if( 1000<= N) {
			computeNumber(N, tmp, 1000);
			for(int i = 0; i < tmp; i++) {
				++record['M'];
			}
		} else if (900 <= N) {
			N -= 900;
			++record['M'];
			++record['C'];
		} else if ( 500 <= N) {
			N -= 500;
			++record['D'];
		} else if ( 400 <= N) {
			N -= 400;
			++record['C'];
			++record['D'];
		} else if ( 100 <= N) {
			computeNumber(N, tmp, 100);
			for(int i = 0; i < tmp; i++) {
				++record['C'];
			}
		} else if ( 90 <= N) {
			N -= 90;
			++record['X'];
			++record['C'];
		} else if ( 50 <= N) {
			N -= 50;
			++record['L'];
		} else if ( 40 <= N) {
			N -= 40;
			++record['X'];
			++record['L'];
		} else if ( 10 <= N) {
			computeNumber(N, tmp, 10);
			for(int i =0 ;i < tmp ; i++){
				++record['X'];
			}
		} else if ( 9 <= N) {
			N -= 9;
			++record['I'];
			++record['X'];
		} else if ( 5 <= N) {
			N -= 5;
			++record['V'];
		} else if ( 4 <= N) {
			N -= 4;
				++record['I'];
				++record['V'];
		} else if ( 1 <= N) {
			for(int i =0 ;i < N ; i++){
				++record['I'];
			}
			N = 0;
		}
	}
}
void outputAns(const char &key, ofstream &fout)
{
	if( record[key] ){
		fout << key << " " << record[key]<<endl;
	}
}

int main() {
    ofstream fout ("preface.out");
    ifstream fin ("preface.in");
	fin >> N;
	for(int i = 1; i <= N; i++) {
		computeRomanNumber(i);
	}
	outputAns('I', fout);
	outputAns('V', fout);
	outputAns('X', fout);
	outputAns('L', fout);
	outputAns('C', fout);
	outputAns('D', fout);
	outputAns('M', fout);
    return 0;
}
