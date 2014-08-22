/*
ID: hwchiu1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> data;
vector<int> sorted;
int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
	int N,tmp,count=0;
	bool flag;
	fin >> N;
	for(int i = 0;i<N;i++){
		fin >> tmp;
		data.push_back(tmp);
		sorted.push_back(tmp);
	}
	sort(sorted.begin(),sorted.end());
	for(unsigned int i=0;i<data.size();i++){
		if(data[i] != sorted[i]){
			//先找可以一次交換就解決的
			flag = true;
			for(unsigned int j=i+1;j<data.size();j++){
				if(data[i] == sorted[j] && data[j] == sorted[i]){
					swap(data[i],data[j]);
					count++;
					flag= false;
					break;
				}
			}
			if(!flag) continue;
			//再找要透過兩次交換才能解決的，如果對方本來就符合，就不要換
			for(unsigned int j=i+1;j<data.size();j++){
				if(data[j] == sorted[i] && data[j]!=sorted[j]){
					swap(data[i],data[j]);
					count++;
					break;
				}
			}
		}
	}
	fout << count<<endl;
    return 0;
}
