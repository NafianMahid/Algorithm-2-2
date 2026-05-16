#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<vector<pair<int,int>>> adjList(n+1);
  
  for(int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({v, w});
    adjList[v].push_back({u, w});
  }
  vector<long long> dist(n+1, LLONG_MAX);
  vector<long long> maxWeight(n+1, 0);
  vector<bool> explored(n+1, false);
  
  dist[1] = 0;
  maxWeight[1] = 0;  

  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
  pq.push({0, 1});
  
  while(!pq.empty()){
    int node = pq.top().second;
    pq.pop();
    
    if(explored[node]) continue;
    explored[node] = true;
    
    for(auto &edge : adjList[node]){
      int neighbour = edge.first;
      int weight = edge.second;
      long long newDist = dist[node] + weight;
      if(!explored[neighbour] && newDist < dist[neighbour]){
        dist[neighbour] = newDist;
        maxWeight[neighbour] = max(maxWeight[node], (long long)weight);
        pq.push({newDist, neighbour});
      }
      else if(!explored[neighbour] && newDist == dist[neighbour]){
        maxWeight[neighbour] = min(maxWeight[neighbour], max(maxWeight[node], (long long)weight));
      }
    }
  }
  
  cout << maxWeight[n] << endl;
  
  return 0;
}