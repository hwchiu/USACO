/*
ID: hwchiu1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ofstream fout ("ariprog.out");
    ifstream fin ("ariprog.in");
    int N,M;
    int maxNumber;
    int index;
    bool *used;
    bool find = false;
    vector<int> sets;
    fin >> N >> M;
    maxNumber = (M*M)*2;
    used = new bool[maxNumber+1];
    for(int i=0;i<=maxNumber;i++)
        used[i]=false;
    for(int i=0;i<=M;i++){
        for(int j=0;j<=M;j++){
            used[i*i + j*j] = true;
        }
    }
    for(int i=0;i<=maxNumber;i++){
        if(used[i]){
            sets.push_back(i);
        }
    }
    for(int b=1;b*(N-1)<=maxNumber;b++){
        for(int i=0;i<sets.size() && sets[i]+b*(N-1) <= maxNumber;i++){
            for(index=0;index<N;index++){
                if( false == used[sets[i] + b*index])
                    break;
            }
            if( index ==N){
                fout<<sets[i]<<" "<<b<<endl;
                find = true;
            }

        }
    }
    if( false == find)
        fout << "NONE"<<endl;
    delete used;
    return 0;
}
