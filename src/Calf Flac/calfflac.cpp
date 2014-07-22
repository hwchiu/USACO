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
	while(lIdx >= 0 && rIdx < text.size()){
		while(lIdx >=0 && isalpha(text[lIdx])==0) lIdx--;
		while(rIdx <text.size() && isalpha(text[rIdx])==0) rIdx++;
		if(toupper(text[lIdx])==toupper(text[rIdx])){
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
	int lIdx,rIdx;
	int lAns=0,rAns=0;
	int count=0;
	while(getline(fin,input)){
		text.append(input);
		text.append("\n");
	}
	for(int i=1;i<text.size()-1;i++){
		checkPalindrome(text,i,i+1,&lAns,&rAns);
		checkPalindrome(text,i-1,i+1,&lAns,&rAns);
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
