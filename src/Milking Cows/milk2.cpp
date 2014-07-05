/*
ID: hwchiu1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct farmers{
	int low,high;
};
bool compare(farmers *fa, farmers *fb){
	if(fa->low == fb->low)
		return fa->high < fb->high;
	return fa->low < fb->low;
}
vector<farmers*> data;
int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
	int n;
	int currLow,currHigh;
	int maxMilked,maxNotMilked;
	fin >> n;
	for(int i=0;i<n;i++){
		farmers* f = new farmers();
		fin >> f->low >> f->high;
		data.push_back(f);
	}
	sort(data.begin(),data.end(),compare);
	currLow = data[0]->low;
	currHigh= data[0]->high;
	maxMilked = currHigh - currLow;
	maxNotMilked = 0;
	for(int i=1;i<data.size();++i){
		if(data[i]->low > currHigh){
			maxNotMilked = max(maxNotMilked,data[i]->low - currHigh);
			currLow = data[i]->low;
			currHigh = data[i]->high;
			maxMilked = max(maxMilked,currHigh-currLow);
		}
		else if (data[i]->high > currHigh){
			currHigh = data[i]->high;
			maxMilked = max(maxMilked,(currHigh - currLow));
		}
	}
	fout<<maxMilked<<" "<<maxNotMilked<<endl;
    return 0;
}
