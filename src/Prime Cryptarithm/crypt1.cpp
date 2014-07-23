/*
ID: hwchiu1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#define SIZE 11

/*
 *		 i  j  k 
 *		    l  p
 *--------------
 *	    a1 a2 a3
 *   b1 b2 b3	 
 * -------------
 *   m1 m2 m3 m4
 */

int main() {
    ofstream fout ("crypt1.out");
    ifstream fin ("crypt1.in");
	int n;
	int input[SIZE];
	int a1,a2,a3,b1,b2,b3,m1,m2,m3,m4;
	int solutions=0;
	bool exist[SIZE] = {false};
	fin >> n ;
	for(int i=0;i<n;++i){
		fin >> input[i];
		exist[input[i]] = true;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				for(int p=0;p<n;p++){
					a3 = input[p] * input[k];
					a2 = input[p] * input[j] + a3/10;
					a1 = input[p] * input[i] + a2/10;
					a3%=10;
					a2%=10;
					if(a1 <10 && exist[a1] && exist[a2] && exist[3]){
						for(int l=0;l<n;l++){
							b3 = input[l] * input[k];
							b2 = input[l] * input[j] + b3/10;
							b1 = input[l] * input[i] + b2/10;
							b3%=10;
							b2%=10;
							if(b1<10 && exist[b1] && exist[b2] && exist[b3]){
								m4 = a3;
								m3 = (a2+b3);
								m2 = (a1+b2)+m3/10;
								m1 = b1 + m2/10;
								m3%=10;
								m2%=10;
								if(m1 < 10 && exist[m1] && exist[m2] && exist[m3] && exist[m4]){
									solutions++;
								}
							}
						}
					}
					
				}
			}
		}
	}
	fout<<solutions<<endl;
    return 0;
}
