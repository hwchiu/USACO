/*
ID: hwchiu1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#define MAXSIZE 10001  //100,000,000^(1/2) ==10000
using namespace std;
vector<int> primes;
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");
void linear_sieve(){
	bool *used = new bool[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
		used[i] = false;
	for(int i=2;i<=MAXSIZE;i++){
		if(!used[i])
			primes.push_back(i);
		for(unsigned int j =0; j < primes.size() && i*primes[j]<=MAXSIZE; j++){
			used[i*primes[j]] = true;
		}
	}
	delete []used;
}
bool checkPrime(int value){
	if( 1 == value)
		return false;
	for(unsigned int i=0;i<primes.size() && primes[i]<=sqrt(value);i++){
		if( 0 == (value % primes[i]))
			return false;
		if( value < primes[i])
			return true;
	}
	return true;

}
void backtracking(int depth, int limit,int value){
	if(depth == limit){
		fout<< value<<endl;
	}
	else{
		for(int i=1;i<=9;i++){ //don't consider 0, it can't be a prime.
			if(checkPrime(value*10+i))
				backtracking(depth+1,limit,value*10+i);
		}
	}



}

int main() {
	int n;
	linear_sieve();
	fin >> n;
	backtracking(0,n,0);
    return 0;
}
