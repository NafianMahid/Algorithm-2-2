#include<iostream>
#include<queue>
using namespace std;
void bfs(vector<int>adjList[],int start){
  bool vis[100] = {false};
  queue<int>q;
  vis[start] = true;
  q.push(start);
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    cout << curr << " ";
    for(int i = 0;i<adjList[curr].size();i++){ // runs total E number of times
       if(!vis[adjList[curr][i]]){
        q.push(adjList[curr][i]);
        vis[adjList[curr][i]] = true;
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
    adjList[v].push_back(u);
  }
  bfs(adjList,0);
}