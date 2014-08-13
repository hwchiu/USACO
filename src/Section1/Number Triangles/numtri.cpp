/*
ID: hwchiu1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int n;
    int *dp,*tmp;
    int ans = 0;
    fin >> n;
    dp = new int[n+2];
    tmp = new int[n+2];
    for(int i=0;i<n+2;i++)
        dp[i]=tmp[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            fin >> dp[j];
            dp[j] = dp[j]+max(tmp[j-1],tmp[j]);
        }
        for(int i=0;i<n+2;i++)
            tmp[i] = dp[i];
    }
    for(int i=0;i<n+2;i++)
        ans = max (ans,tmp[i]);
    fout<<ans<<endl;
    delete []dp;
    delete []tmp;
    return 0;
}
