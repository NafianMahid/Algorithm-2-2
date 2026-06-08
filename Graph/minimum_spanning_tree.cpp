#include<iostream>
#include<vector>
using namespace std;
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<int>>adjList[v];
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
  }
  // pair<int,pair<int,int>>
  priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
  vector<bool>IsMST(v,0);
  vector<int>parent(v); // for drawing mst

  int cost = 0;
  pq.push({0,{0,-1}});

  while(!pq.empty()){
    int wt = pq.top().first;
    int node = pq.top().second.first;
    int par = pq.top().second.second;
    pq.pop();
    if(!IsMST[node]){
      IsMST[node] = 1;
      cost += wt;
      parent[node] = par;
      for (int i = 0; i < adjList[node].size(); i++)
      {
        if(!IsMST[adjList[node][i][0]]){
          pq.push({adjList[node][i][1],{adjList[node][i][0],node}});
        }
      }
      
    }
  }
  cout << cost << endl;
}

// SC:O(V+V+E)=> O(V+E) E is the max size of priority_queue
// TC:O(ElogE) or (ElogV) for worst case complete graph