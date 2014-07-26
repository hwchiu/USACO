/*
ID: hwchiu1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct farmer{
	int price;
	int amount;
};

bool compare(farmer* fa,farmer* fb){
	if( fa->price == fb->price)
		return fa->amount > fb->amount;
	return fa->price <= fb->price;
}
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
	vector<farmer*> data;
	int require,numOfFarmer;
	int price,amunt;
	int ans = 0;
	fin >> require >> numOfFarmer;
	for(int i=0;i<numOfFarmer;++i){
		farmer* tmp = new farmer();
		fin >> tmp->price >> tmp->amount;
		data.push_back(tmp);
	}
	sort(data.begin(),data.end(),compare);
	for(int i=0;i<data.size() && require >0;++i){
		if( data.at(i)->amount < require){
			ans += data.at(i)->amount * data.at(i)->price;
			require -= data.at(i)->amount;
		}
		else{
			ans += require * data.at(i)->price;
			require = 0;
			break;
		}
	}
	fout<<ans<<endl;
	for(int i=0;i<data.size();++i)
		delete data[i];
    return 0;
}
