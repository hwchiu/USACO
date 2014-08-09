/*
ID: hwchiu1
PROG: beads
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int *r_left,*r_right,*b_left,*b_right;
    int num,max_ans=-1;
    int left,right;
    int ind_left,ind_right;
    char curr;
    char* data;
    fin >> num;
    data = new char[num<<1];
    r_left = new int[num<<1];
    r_right = new int[num<<1];
    b_left = new int[num<<1];
    b_right = new int[num<<1];
    for(int i=0;i<num;++i){
        fin >> data[i];
        data[num+i] = data[i];
        r_left[i] = r_right[i] = b_left[i] = b_right[i] = 0;
        r_left[num+i] = r_right[num+i] = b_left[num+i] = b_right[num+i] = 0;
    }
    //DP 
    //左邊跟右邊分開計算，左邊代表的是不用i點以前的所有可能性，右邊代表的是使用i的所有可能性
    //因此左邊都是看上一個點的值，右邊都是看當前此點的值
    for(int i=1;i<num*2;++i){
        if(data[i-1] =='r'){
            r_left[i] = r_left[i-1] + 1;
            b_left[i] = 0;
        }
        else if(data[i-1] =='b'){
            b_left[i] = b_left[i-1] + 1;
            r_left[i] = 0;
        }
        else if(data[i-1]=='w'){
            r_left[i] = r_left[i-1] + 1;
            b_left[i] = b_left[i-1] + 1;
        }
    }
    if(data[(num<<1)-1]=='r')
        r_right[(num<<1)-1]=1;
    else if(data[(num<<1)-1]=='b')
        b_right[(num<<1)-1]=1;
    else{
        r_right[(num<<1)-1]=1;
        b_right[(num<<1)-1]=1;
    }
    for(int i=(num*2-2);i>=0;i--){
        if(data[i] =='r'){
            r_right[i] = r_right[i+1] + 1;
            b_right[i] = 0;
        }
        else if(data[i] =='b'){
            b_right[i] = b_right[i+1] + 1;
            r_right[i] = 0;
        }
        else{
            r_right[i] = r_right[i+1] + 1;
            b_right[i] = b_right[i+1] + 1;
        }
    }
    for(int i=0;i<num*2;i++){
        max_ans = max(max_ans,max(r_left[i],b_left[i])+max(r_right[i],b_right[i]));
    }
    max_ans = min(max_ans,num);
    fout<<max_ans<<endl;
    delete b_right;
    delete b_left;
    delete r_right;
    delete r_left;
    delete data;


    return 0;
}
