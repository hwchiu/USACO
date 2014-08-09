/*
ID: hwchiu1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct stall{
    int index;
    int distance;
};
bool compare(stall *sa,stall *sb){
    if ( sa->distance == sb->distance)
        return sa->index < sb->index;
    return sa->distance > sb->distance;
}

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    vector<stall*> data;
    vector<int> originalData;
    vector<int> boardPoint;
    int boardNum,stallNum,cowNum;
    int prevPos=-1,cowPos;
    int ans = 0;
    fin >> boardNum >> stallNum >> cowNum;
    if ( boardNum >= cowNum){
        fout << cowNum<<endl;
        return 0;
    }
    for(int i=0;i<cowNum;i++){
        fin >> cowPos;
        originalData.push_back(cowPos);
    }
    sort(originalData.begin(),originalData.end(),std::less<int>());
    //Compute a distance between for consecutive cows.
    for(int i=0;i<originalData.size();i++){
        cowPos = originalData[i];
        stall *tmp = new stall();
        tmp->index = i;
        if( prevPos <0)
            tmp->distance = 0;
        else
            tmp->distance = cowPos - prevPos;
        prevPos = cowPos;
        data.push_back(tmp);
    }
    //Sort the distance
    sort(data.begin(),data.end(),compare);
    //Use the distance to decide the position of boardPoint
    for(int i=0;i<boardNum-1;++i){
        boardPoint.push_back(data[i]->index);
    }

    sort(boardPoint.begin(),boardPoint.end());
    int curr = 0;
    for(int i=0;i<boardPoint.size();i++){
        ans += originalData.at(boardPoint[i]-1) - originalData[curr] +1;
        curr = boardPoint[i];
    }
    ans += originalData[data.size()-1] - originalData[curr] + 1;
    fout<<ans<<endl;
    return 0;
}
