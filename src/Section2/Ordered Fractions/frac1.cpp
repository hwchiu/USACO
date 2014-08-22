/*
ID: hwchiu1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
	return b == 0 ? a: gcd(b,a%b);
}
struct Number{
	int up;
	int bottom;
	double ans;
};
bool compare(Number *n1, Number *n2){
	return n1->ans < n2->ans;
}
int main() {
    ofstream fout ("frac1.out");
    ifstream fin ("frac1.in");
	vector<Number*> data;
	int N;
	fin >> N;
	for(int i=1;i<N;i++){
		for(int j=i+1;j<=N;j++){
			Number *tmp = new Number();
			int gcd_ij = gcd(i,j);
			tmp->up = i/gcd_ij;
			tmp->bottom = j/gcd_ij;
			tmp->ans = (double)i/j;
			data.push_back(tmp);
		}
	}
	sort(data.begin(),data.end(),compare);
	fout << "0/1" <<endl;
	int pre_up=0,pre_bottom=0;
	for(unsigned int i=0;i<data.size();i++){
		if(data[i]->up == pre_up && data[i]->bottom == pre_bottom)
			continue;
		pre_up = data[i]->up;
		pre_bottom = data[i]->bottom;
		fout << pre_up <<"/" <<pre_bottom<<endl;
	}

	fout << "1/1" <<endl;
    return 0;
}
