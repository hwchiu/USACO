/*
ID: hwchiu1
PROG: gift1
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Person{
	public:
		Person();
		Person(string name,int money):name(name),money(money){}
		string name;
		int money;
};

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	int num_group;
	vector<Person> groups;
	string name,name_given;
	int money,num_given;

	fin >> num_group;
	
	for(int i=0;i<num_group;++i){
		fin >> name;
		Person person(name,0);
		groups.push_back(person);
	}
	for(int i=0;i<num_group;++i){
		fin >> name;
		fin >> money >> num_given;
		for(int j=0;j<num_given;++j){
			fin >> name_given;
			for(int k=0;k<groups.size();++k){
				if( groups.at(k).name == name_given){
					groups.at(k).money += money/num_given;
					break;
				}
			}
		}
		if( 0!= num_given){
			for(int k=0;k<groups.size();++k){
				if( groups.at(k).name == name){
					groups.at(k).money += (money%num_given) - money;
					break;
				}
			}
		}
	}
	for(int i=0;i<groups.size();++i){
		fout<< groups.at(i).name<<" "<<groups.at(i).money<<endl;
	}

    return 0;
}
