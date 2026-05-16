#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>ans;
void dfs(vector<int>adjList[],vector<bool>&vis,int start){
      vis[start] = true;
      ans.push_back(start);
      for(int i = 0;i<adjList[start].size();i++){
        if(!vis[adjList[start][i]]){
          dfs(adjList,vis,adjList[start][i]);
        }
      }
}
void dfshelper(vector<int>adjList[],int v){
   vector<bool>vis(v,0);
   for (int i = 0; i < v; i++)
   {
    /* code */
    if(!vis[i]){
      dfs(adjList,vis,i);
    }
   }
   
}
int main(){
  int v,e;
  cin >> v >> e;
  vector<int>adjList[v];
  for (int i = 0; i < e; i++)
  {
    /* code */
    int u,v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  dfshelper(adjList,v);
}