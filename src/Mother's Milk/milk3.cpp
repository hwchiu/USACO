/*
ID: hwchiu1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int capacityA,capacityB,capacityC;
vector<int> ans;
void backtracking(bool **used, int usedA,int usedB,int usedC){
	if(used[usedB][usedC]) //used
		return ;
	else{
		used[usedB][usedC] = true;
		if( 0 == usedA){
			ans.push_back(usedC);
		}
		//C -> A
		if( usedC > 0 && usedA != capacityA){
			if( (usedC + usedA) <= capacityA ){  // C will be empty
				backtracking(used,usedA+usedC,usedB,0);
			}
			else // A will be full
				backtracking(used,capacityA,usedB,usedC + usedA - capacityA);
		}
		//C -> B
		if( usedC > 0 && usedB != capacityB){
			if( (usedC + usedB) <= capacityB ){  
				backtracking(used,usedA,usedB+usedC,0);
			}
			else 
				backtracking(used,usedA,capacityB,usedC + usedB - capacityB);
		}

		//B -> A
		if( usedB > 0 && usedB != capacityB){
			if( (usedB + usedA) <= capacityA ){  
				backtracking(used,usedA+usedB,0,usedC);
			}
			else 
				backtracking(used,capacityA,usedB + usedA - capacityA,usedC);
		}

		//B -> C
		if( usedB > 0 && usedC != capacityC){
			if( (usedB + usedC) <= capacityC ){  
				backtracking(used,usedA,0,usedC+usedB);
			}
			else 
				backtracking(used,usedA,usedB + usedC - capacityC,capacityC);
		}

		//A -> B
		if( usedA > 0 && usedB != capacityB){
			if( (usedA + usedB) <= capacityB ){  
				backtracking(used,0,usedB+usedA,usedC);
			}
			else 
				backtracking(used,usedA + usedB - capacityB,capacityB,usedC);
		}

		//A -> C
		if( usedA > 0 && usedC != capacityC){
			if( (usedA + usedC) <= capacityC ){  
				backtracking(used,0,usedB,usedA+usedC);
			}
			else 
				backtracking(used,usedA + usedC - capacityC,usedB,capacityC);
		}
	}
}


int main() {
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");
	bool **used;
	fin >> capacityA >> capacityB >> capacityC ;
	used = new bool*[capacityB+1];
	for(int i=0;i<capacityB+1;i++)
		used[i] = new bool[capacityC+1];
	backtracking(used,0,0,capacityC);
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();++i){
		if( 0 == i )
			fout<<ans.at(i);
		else
			fout<<" "<<ans.at(i);
	}
	fout<<endl;
	for(int i=0;i<capacityB+1;i++)
		delete []used[i];
	delete []used;
    return 0;
}
