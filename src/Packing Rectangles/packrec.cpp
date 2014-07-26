/*
ID: hwchiu1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class rect{
	public:
		rect(int h, int w):height(h),width(w),area(h*w),used(false){}
		void swap(){
			height ^= width ;
			width ^= height ;
			height ^= width ;
		}
		int height;
		int width;
		int area;
		bool used;
};
bool compare(rect* ra, rect* rb){
	return ra->height >= rb->height;
}
vector<rect*> ans;
vector<rect*> input;
vector<int> currentData;
void compute(int h,int w){
	int height = max(h,w), width = min(h,w);
	int area = height* width;
	if( !ans.empty() && area < ans.at(0)->area){
		for(int i=0;i<ans.size();i++)
			delete ans[i];
		ans.clear();
	}
	else if( !ans.empty() &&  area > ans.at(0)->area)
		return;
	for(int i=0;i<ans.size();++i){
		if(ans[i]->height == height && ans[i]->width == width)
			return;
	}
	rect* tmp = new rect(height,width);
	ans.push_back(tmp);
}
void getData(int index,int*w,int*h){
	*h = input[index]->height;
	*w = input[index]->width;
}

void backtracking(int depth){
	if( depth == input.size()){
		int index;
		int height,width;
		int h1,h2,h3,h4,w1,w2,w3,w4;
		getData(currentData[0],&h1,&w1);
		getData(currentData[1],&h2,&w2);
		getData(currentData[2],&h3,&w3);
		getData(currentData[3],&h4,&w4);

		//We have six basic type, compute for each one and check the minimal ans.
		//Type(1) 1,2,3,4
		width  = w1+w2+w3+w4;
		height = max(max(h1,h2),max(h3,h4));
		compute(height,width);
		//Type(2) 123
		//        444
		width = max(w1+w2+w3,w4);
		height = h4 + max(max(h1,h2),h3);
		compute(height,width);
		//Type(3) 123
		//         43
		width = max(w1+w2,w4)+w3;
		height = max(h3, max(h1,h2)+h4);
		compute(height,width);
		//Type(4,5) 124
		//           3
		width = max(w2,w3)+w1+w4;
		height = max(max(h1,h4),h2+h3);
		compute(height,width);
		//Type(6)   12     1
		//          34     32
		//                 34
		//Tw
		//two case
		if(h1 + h3 > h4 && w1 <= w3 && h2+h4>h3){
			height = max(h1+h3,h2+h4);
			if( h4 > h3)
				width = max(w1+w2,w3+w4);
			else 
				width = w3+max(w2,w4); 
			compute(height,width);
		}
		return;
	}
	for(int i=0;i<input.size();i++){
		if(!input.at(i)->used){
			input.at(i)->used = true;
			currentData.push_back(i);
			backtracking(depth+1);
			input.at(i)->swap();
			backtracking(depth+1);
			input.at(i)->swap();
			currentData.pop_back();
			input.at(i)->used = false;
		}
	}

}



int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
	int h,w;
	for(int i=0;i<4;i++){
		fin >> h >> w;
		rect* tmp = new rect(h,w);
		input.push_back(tmp);
	}
	backtracking(0);
	sort(ans.begin(),ans.end(),compare);
	fout<<ans[0]->area<<endl;
	for(int i=0;i<ans.size();++i)
		fout<<ans[i]->width<<" "<<ans[i]->height<<endl;
    return 0;
}
