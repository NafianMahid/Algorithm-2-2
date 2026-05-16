#include<iostream>
#include<stack>
using namespace std;
stack<int>s;
void dfs(vector<int>adjList[],vector<bool>&visited,int node){
  visited[node] = true;
  for(int i = 0;i<adjList[node].size();i++){
    if(!visited[adjList[node][i]]){
      dfs(adjList,visited,adjList[node][i]);
    }
  }
  s.push(node);
}
void topological_sort(vector<int>adjList[],int v){
    vector<bool>visited(v,false);
    for(int i =0;i<v;i++){
      if(!visited[i]){
        dfs(adjList,visited,i);
      }
    }
    while(!s.empty()){
      cout << s.top() << " ";
      s.pop();
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
  topological_sort(adjList,v);
}