#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<int>>adjList[v+1];
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
  }
  vector<bool>explore(v+1,0);
  vector<int>dis(v+1,INT_MAX);
  vector<int>parent(v+1,-1);
  dis[1] = 0;
  // priority_queue<int,vector<int>,greater<int>>p;
  //pair<int,int>
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
  p.push({0,1});
  while(!p.empty()){
    int node = p.top().second;
    p.pop();
    if(explore[node] == 1) continue;
    explore[node] = 1;
    for (int i = 0; i < adjList[node].size(); i++)
    {
      int neighbour = adjList[node][i][0];
      int weight = adjList[node][i][1];
      if(!explore[neighbour] && (dis[neighbour] > dis[node] + weight)){
        dis[neighbour] = dis[node] + weight;
        p.push({dis[neighbour],neighbour});
        parent[neighbour] = node;
      }
    }
  }
   vector<int>path;
   int dest = v;
     // i cant reach my destination disconnected graph
     if(parent[v] == -1){
      cout << -1 << endl;
      return;
     }
   while(dest!=-1){
    path.push_back(dest);
    dest = parent[dest];
   }
   reverse(path.begin(),path.end());
   for (int i = 0; i < path.size(); i++)
   {
    cout << path[i] << " ";
   }
   cout << endl;
}