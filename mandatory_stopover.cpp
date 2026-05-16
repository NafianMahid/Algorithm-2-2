#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int v,e,s,d,c;
  cin >> v >> e >> s >> d >> c;
  vector<vector<int>>adjList[v+1];
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    adjList[u].push_back({v,w});
    adjList[v].push_back({u,w});
  }
  vector<bool>explore1(v+1,0);
  vector<int>dis1(v+1,INT_MAX);
  dis1[s] = 0;
  // priority_queue<int,vector<int>,greater<int>>p;
  //pair<int,int>
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
  p.push({0,s});
  while(!p.empty()){
    int node = p.top().second;
    p.pop();
    if(explore1[node] == 1) continue;
    explore1[node] = 1;
    for (int i = 0; i < adjList[node].size(); i++)
    {
      int neighbour = adjList[node][i][0];
      int weight = adjList[node][i][1];
      if(!explore1[neighbour] && (dis1[neighbour] > dis1[node] + weight)){
        dis1[neighbour] = dis1[node] + weight;
        p.push({dis1[neighbour],neighbour});
      }
    }
  }
  int time = 0;
  time = dis1[c];
  vector<bool>explore2(v+1,0);
  vector<int>dis2(v+1,INT_MAX);
  dis2[c] = 0;
  // priority_queue<int,vector<int>,greater<int>>p;
  //pair<int,int>
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p2;
  p2.push({0,c});
  while(!p2.empty()){
    int node = p2.top().second;
    p2.pop();
    if(explore2[node] == 1) continue;
    explore2[node] = 1;
    for (int i = 0; i < adjList[node].size(); i++)
    {
      int neighbour = adjList[node][i][0];
      int weight = adjList[node][i][1];
      if(!explore2[neighbour] && (dis2[neighbour] > dis2[node] + weight)){
        dis2[neighbour] = dis2[node] + weight;
        p2.push({dis2[neighbour],neighbour});
      }
    }
  }
  time = time + dis2[d];
  cout << time << endl;
}