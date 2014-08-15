/*
ID: hwchiu1
PROG: castle
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#define WEST  0x1
#define NORTH 0x2
#define EAST  0x4
#define SOUTH 0x8
int M,N;
vector<int> rooms;
int solve(int **map,int** record,int count,int i,int j){
	int tmp = 0;
	if(i < 0 or i>=N or j <0 or j>=M)
		return 0;
	if( -1 != record[i][j])
		return 0;
	record[i][j] = count;
	tmp = 1;
	if( !(map[i][j] & WEST))
		tmp += solve(map,record,count,i,j-1);
	if( !(map[i][j] & NORTH))
		tmp += solve(map,record,count,i-1,j);
	if( !(map[i][j] & EAST))
		tmp += solve(map,record,count,i,j+1);
	if( !(map[i][j] & SOUTH))
		tmp += solve(map,record,count,i+1,j);
	return tmp;
}
int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
	int **map,**record;
	int count =0;
	int maxAns = 0,result = 0;
	int maxRoom = 0;
	int ans_row=0,ans_col=0;
	bool ans_dir = true;
	fin >> M >> N;
	map = new int*[N];
	record = new int*[N];
	for(int i=0;i<N;i++){
		map[i] = new int[M];
		record[i] = new int[M];
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			fin >> map[i][j];
			record[i][j] = -1;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if( -1 == record[i][j]){
				result = solve(map,record,count++,i,j);
				rooms.push_back(result);
				maxAns = max(maxAns,result);
			}
		}
	}
	fout << rooms.size() <<endl;
	fout << maxAns << endl;
	for(int j=0;j<M;j++){//盡量往西南
		for(int i=N-1;i>=0;i--){//對每一塊磚塊來說，上面以及右邊的牆壁都算是他的座標，所以從最左下面開始，每一塊都先往上測試，再往右測試。因為座標從（1,1)開始，因此紀錄的時候要多一
			if( i!=0  && record[i][j] != record[i-1][j]){//往上面試試看
				result = rooms[record[i][j]] + rooms[record[i-1][j]];
				if(result > maxRoom){
					maxRoom = result;
					ans_row = i+1;
					ans_col = j+1;
					ans_dir = 0;
				}
			}
			if( j!=(M-1) && record[i][j] != record[i][j+1]){//往右邊邊試試看
				result = rooms[record[i][j]] + rooms[record[i][j+1]];
				if(result > maxRoom){
					maxRoom = result;
					ans_row = i+1;
					ans_col = j+1;
					ans_dir = 1;
				}
			}
		}	
	}
	fout<<maxRoom<<endl;
	fout<<ans_row<<" "<<ans_col<<" ";
	if(ans_dir)
		fout<<"E"<<endl;
	else
		fout<<"N"<<endl;
	for(int i=0;i<N;i++){
		delete[]map[i];
		delete[]record[i];
	}
	delete []map;
	delete []record;
    return 0;
}
