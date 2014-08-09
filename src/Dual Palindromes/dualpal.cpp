/*
ID: hwchiu1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream fout ("dualpal.out");
bool checkPalin(string input){
    int n = input.size();
    for(int i=0;i<input.size()/2;++i){
        if(input[i] != input[n-i-1])
            return false;
    }
    return true;
}
char getBaseChar(int n){
    return n+'0';
}

bool PalindromesSquare(int n,int base){
    string baseString;
    string squareString;
    int tmp = n;
    n = n;
    while(n){
        squareString.push_back(getBaseChar(n%base));
        n/=base;
    }
    if ( checkPalin(squareString) ){
        return true;
    }
    return false;
        
}

int main() {
    ifstream fin ("dualpal.in");
    int limit;
    int start;
    int count;
    fin >> limit >> start;
    while(limit){
        ++start;
        count =0;
        for(int i=2;i<=10;++i){
            if( PalindromesSquare(start,i)){
                ++count;
                if( 2 == count){
                    fout<<start<<endl;
                    --limit;
                    break;
                }
            }
        }
    }
    return 0;
}
