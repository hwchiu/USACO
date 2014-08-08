/*
ID: hwchiu1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define MAXSIZE 10001  // 100,000,000 = 100,00 ^2
vector<int> primes;
int a,b;
int dig_a,dig_b;
ofstream fout ("pprime.out");
ifstream fin ("pprime.in");
void linear_sieve(){
	bool *used = new bool[MAXSIZE];
	for(int i=0;i<MAXSIZE;i++)
		used[i] = false;
	for(int i=2;i<=MAXSIZE;i++){
		if(!used[i])
			primes.push_back(i);
		for(unsigned int j=0;j<primes.size() && i*primes[j]<=MAXSIZE;j++){
			used[i*primes[j]] = true;
		}
	}
	
	delete []used;
}
bool checkPrime(int value){
	for(unsigned int i=0;i<primes.size() && primes[i] <= sqrt(value);i++){
		if( 0 == (value % primes[i]))
			return false;
		if( value < primes[i])
			return true; 
	}
	return true;

}
int backtracking(int dig_limit, int half_dig_limit, int depth,int value){
	if( depth == half_dig_limit){
		int tmp=value,upper_bound = half_dig_limit;
		int ans=value;
		if( dig_limit %2){
			tmp /= 10;
			upper_bound-=1;
		}
		for(int i=0;i<upper_bound;i++){
			ans=ans*10+tmp%10;
			tmp/=10;
		}
		if(  ans > b)
			return 2;
		if( a <= ans && checkPrime(ans)){
			fout<<ans<<endl;
			return 0;
		}
	}
	else{

		for(int i=0;i<10;i++)
		{
			if( 0 == depth && ( i%2==0 || 5 == i) && 1 != dig_limit) continue;
			if( 2 == backtracking(dig_limit,half_dig_limit,depth+1,value*10+i))
				return 2;

		}
		
	}
	return 1;

}
int main() {
	int tmp_a,tmp_b;
	linear_sieve();
	fin >> a >> b;
	tmp_a = a;
	tmp_b = b;
	// compute the digits of a and b
	dig_a = dig_b = 0;
	while(tmp_a){ dig_a++,tmp_a/=10;}
	while(tmp_b){ dig_b++,tmp_b/=10;}
	for(int i=dig_a;i<=dig_b;i++){
		if(i%2)
			backtracking(i,(i+1)/2,0,0);		
		else if( 2 == i && a<=11 && 11<=b)
			fout<<11<<endl;
	}

    return 0;
}
