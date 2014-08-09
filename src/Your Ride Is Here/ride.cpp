/*
ID: hwchiu1
PROG: ride
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string group,comet;
    int sum_group=1,sum_comet=1;

    fin >> group;
    fin >> comet;
    for(int i=0;i<group.size();++i){
        sum_group *= (group[i]-'A' +1);
    }
    for(int i=0;i<comet.size();++i){
        sum_comet *= (comet[i]-'A' +1);
    }
    if( (sum_group%47) == (sum_comet%47) ){
        fout << "GO" << endl;
    }
    else
        fout << "STAY" <<endl;
    
    return 0;
}
