/*
ID: hwchiu1
PROG: transform
LANG: C++ 
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;
void turn90(char* data,int n){
	char *tmp = new char[n*n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			tmp[j*n+(n-i-1)] =  data[i*n + j];
		}
	}
	memcpy(data,tmp,n*n);
	delete tmp;
	return ;
}

void reflect(char *data,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n/2;j++){
			swap(data[i*n+j],data[i*n+(n-j-1)]);
		}
	}
	return ;
}
int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
	char *src, * dst;
	int n;
	fin >> n;
	src = new char[n*n];
	dst = new char[n*n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			fin >> src[i*n+j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			fin >> dst[i*n+j];
	}

	//#1
	turn90(src,n);
	if( 0 == memcmp(src,dst,n*n)){
		fout <<"1"<<endl;
		return 0;
	}
	//#2
	turn90(src,n);
	if( 0 == memcmp(src,dst,n*n)){
		fout <<"2"<<endl;
		return 0;
	}
	//#3
	turn90(src,n);
	if( 0 == memcmp(src,dst,n*n)){
		fout <<"3"<<endl;
		return 0;
	}
	//#4
	turn90(src,n);
	reflect(src,n);
	if( 0 == memcmp(src,dst,n*n)){
		fout <<"4"<<endl;
		return 0;
	}
	//#5
	for(int i=0;i<3;i++){
		turn90(src,n);
		if( 0 == memcmp(src,dst,n*n)){
			fout <<5<<endl;
			return 0;
		}
	}
	//#6
	turn90(src,n);
	reflect(src,n);
	if( 0 == memcmp(src,dst,n*n)){
		fout <<"6"<<endl;
		return 0;
	}
	//#7
	fout<<"7"<<endl;

    return 0;
}
