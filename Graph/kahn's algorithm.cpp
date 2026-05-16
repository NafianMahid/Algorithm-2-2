#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int>ans;
void topologicalSort(vector<int>adjList[],int v){
    // calculete in degree of all vertex
   vector<int>indeg(v,0);
   for (int i = 0; i < v; i++)
   {
      for (int j = 0; j<adjList[v].size(); j++)
      {
        indeg[adjList[i][j]]++;
      }
   }
   //push zero indeg node to queue
   queue<int>q;
   for (int i = 0; i < v; i++)
   {
    if(indeg[i] == 0){
      q.push(i);
    }
   }
   while(!q.empty()){
    int node = q.front();
    q.pop();
    ans.push_back(node);
    for (int i = 0; i < adjList[node].size(); i++)
    {
       indeg[adjList[node][i]]--; // decrement the indeg
       if(indeg[adjList[node][i]]==0){
        q.push(adjList[node][i]);
       }
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
  }
}

