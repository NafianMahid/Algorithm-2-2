#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
int main(){
  long long n,m;
   cin >> n >> m;
   vector<vector<long long>>adjList[n+1];
  for (long long i = 1; i <= m; i++)
  {
    long long a,b,c;
    cin >> a >> b >> c;
    adjList[a].push_back({b,c});
  }
  vector<bool>explore(n+1,0);
  vector<long long>dis(n+1,LLONG_MAX);
  priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>p;
  p.push({0,1});
  dis[1] = 0;
  while(!p.empty()){
    long long node = p.top().second;
    p.pop();
    if(explore[node]==1) continue;
    explore[node] = 1;
    for (long long i = 0; i < adjList[node].size(); i++){
       long long neighbour = adjList[node][i][0];
       long long weight = adjList[node][i][1];
    {
       if(!explore[neighbour] && ((dis[node] + weight) < dis[neighbour])){
        dis[neighbour] = dis[node] + weight;
        p.push({dis[neighbour],neighbour});
       }
    }
  }
}
  for (int i = 1; i <= n; i++)
  {
    cout << dis[i] << " ";
  }
  cout << endl;
}