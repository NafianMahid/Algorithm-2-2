#include<iostream>
using namespace std;
int FindParent(int u,vector<int>&parent){
  if(u == parent[u]){
    return u;
  }
  return parent[u] = FindParent(parent[u],parent); // path compression
}
void UnionByRank(int u,int v,vector<int>&parent,vector<int>&rank){
  int pu = FindParent(u,parent);
  int pv = FindParent(v,parent);
  if(rank[pu]>rank[pv]){
    parent[pv] = pu;
  }
  else if(rank[pu] < rank[pv]){
    parent[pu] = pv;
  }
  else{
    parent[pv] = pu;
    rank[pu]++;
  }
}
int main(){
  int v,e;
  cin >> v >> e;
  vector<int>parent(v);
  vector<int>rank(v,0);
  for (int i = 0; i < v; i++)
  {
    parent[i] = i;
  }
  
  vector<vector<int>> adjList[v];
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
  }
  priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < adjList[i].size(); j++)
    {
      pq.push({adjList[i][j][1],{i,adjList[i][j][0]}});
    }
    
  }
  int cost = 0;
  int edges = 0;
  while(!pq.empty()){
    int wt = pq.top().first;
    int u = pq.top().second.first;
    int v = pq.top().second.second;
    pq.pop();
    if(FindParent(u,parent)!=FindParent(v,parent)){
      cost+=wt;
      UnionByRank(u,v,parent,rank);
      edges++;
    }
    if(edges == v-1) break;  // v-1 edges should be my part
  }
  cout << cost << endl;
} 

// TC: v + ElogE + ElogE 