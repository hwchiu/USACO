/*
ID: hwchiu1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int *vitamins;
int **feeds;
int *bestResults;
int *currentResults;
int *current;
int V,G;
int currentSize,bestSize;
bool check(){
    if(currentSize >= bestSize)
        return false;
    for(int i=0;i<V;i++){
        if(current[i] < vitamins[i])
                return false;
    }
    bestSize = currentSize;
    for(int i=0;i<currentSize;i++)
        bestResults[i] = currentResults[i];
    return true;
}

void DFS(int depth){
    if(depth > G)
        return ;
    if(check() || depth == G){
        return ;
    }
    for(int i=0;i<V;i++){
        current[i]+=feeds[depth][i];
    }
    currentResults[currentSize++] = depth+1;

    DFS(depth+1);

    for(int i=0;i<V;i++)
        current[i]-=feeds[depth][i];
    currentSize--;

    DFS(depth+1);
    return ;
}

int main() {
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    fin >> V;
    vitamins = new int[V];
    for(int i=0;i<V;i++){
        fin >> vitamins[i];
    }
    fin >> G;
    feeds = new int*[G];
    for(int i=0;i<G;i++){
        feeds[i] = new int[V];
        for(int j=0;j<V;j++){
            fin >>feeds[i][j];
        }
    }
    bestResults = new int[G];
    currentResults = new int[G];
    current = new int [V];
    for(int i=0;i<V;i++)
        current[i] = 0;
    currentSize = 0;
    bestSize = G+1;
    DFS(0);
    fout<<bestSize;
    for(int i=0;i<bestSize;i++)
        fout<<" "<<bestResults[i];
    fout<<endl;
    delete []vitamins;
    delete []bestResults;
    delete []currentResults;
    delete []current;
    for(int i=0;i<G;i++)
        delete []feeds[i];
    delete []feeds;
    return 0;
}
