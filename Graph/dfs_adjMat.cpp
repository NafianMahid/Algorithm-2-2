#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>ans;
void dfs(vector<vector<bool>>adjMat,vector<bool>&vis,int start,int v){
      vis[start] = true;
      ans.push_back(start);
      for(int i = 0;i<v;i++){
        if(adjMat[start][i] == 1 && !vis[i]){
          dfs(adjMat,vis,i,v);
        }
      }
}
void dfshelper(vector<vector<bool>>adjMat,int v){
   vector<bool>vis(v,0);
   for (int i = 0; i < v; i++)
   {
    /* code */
    if(!vis[i]){
      dfs(adjMat,vis,i,v);
    }
   }
   
}
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<bool>>adjMat(v,vector<bool>(v,0));
  for (int i = 0; i < e; i++)
  {
    /* code */
    int u,v;
    cin >> u >> v;
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
  }
  dfshelper(adjMat,v);
}