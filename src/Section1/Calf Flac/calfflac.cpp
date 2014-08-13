/*
ID: hwchiu1
PROG: calfflac
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void checkPalindrome(string text,int lIdx,int rIdx,int *lAns,int *rAns){
    while(rIdx < text.size()-1 && !isalpha(text[rIdx])) rIdx++;
    if(text[lIdx+1] == text[rIdx]){
        rIdx++;
    }
    while(lIdx >= 0 && rIdx < text.size()){
        while(lIdx >=0 && isalpha(text[lIdx])==0) lIdx--;
        while(rIdx <text.size() && isalpha(text[rIdx])==0) rIdx++;
        if(text[lIdx]==text[rIdx]){
            if( (rIdx-lIdx) > (*rAns-*lAns)){
                *rAns = rIdx;
                *lAns = lIdx;
            }
            lIdx--;
            rIdx++;
        }else{
            return;
        }
    }
}
int main() {
    ofstream fout ("calfflac.out");
    ifstream fin ("calfflac.in");
    string input;
    string text;
    string tmp;
    int lIdx,rIdx;
    int lAns=0,rAns=0;
    int count=0;
    while(getline(fin,input)){
        text.append(input);
        text.append("\n");
    }
    tmp = text;
    for(int i=0;i<tmp.size();i++){
        if(isalpha(tmp[i]))
            tmp[i] = toupper(tmp[i]);
    }
        
    for(int i=1;i<text.size()-1;i++){
        if(!isalpha(text[i]))
                continue;
        checkPalindrome(tmp,i-1,i+1,&lAns,&rAns);
    }
    for(int i=lAns;i<=rAns;++i){
        if(isalpha(text[i])!=0)
            count++;
    }
    fout<<count<<endl;
    for(int i=lAns;i<=rAns;++i){
        fout<<text[i];
    }
    fout<<endl;
    return 0;
}
