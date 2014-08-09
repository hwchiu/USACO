/*
ID: hwchiu1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
bool check(int i,char target){
    switch(i){
        case 2:
            return target == 'A' | target =='B' | target == 'C';
        case 3:
            return target == 'D' | target =='E' | target == 'F';
        case 4:
            return target == 'G' | target =='H' | target == 'I';
        case 5:
            return target == 'J' | target =='K' | target == 'L';
        case 6:
            return target == 'M' | target =='N' | target == 'O';
        case 7:
            return target == 'P' | target =='R' | target == 'S';
        case 8:
            return target == 'T' | target =='U' | target == 'V';
        case 9:
            return target == 'W' | target =='X' | target == 'Y';
    }
    return false;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    ifstream din ("dict.txt");
    list<string> data;
    string input,tmp;
    fin >> input;
    while(din >> tmp){
        if(tmp.size() == input.size())
            data.push_back(tmp);
    }
    for(int i=0;i<input.size();++i){
        for(list<string>::iterator itr = data.begin(); itr != data.end() ; ){
            if(check(input[i]-'0',(*itr)[i])){
                ++itr;
            }
            else{
                itr = data.erase(itr);
            }

        }
    }
    if( data.empty() )
        fout<<"NONE"<<endl;
    for(list<string>::iterator itr = data.begin(); itr != data.end() ; ++itr)
        fout<<*itr<<endl;
    return 0;
}
