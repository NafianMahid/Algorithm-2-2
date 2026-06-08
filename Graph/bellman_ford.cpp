#include<iostream>
using namespace std;
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<int>>edges(e);
  vector<int>dist(v,1e8);
  dist[0] = 0;
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    edges[i] = {u,v,w};
  }
  
  for (int i = 0; i < v-1; i++)
  {
    bool flag = 0;
    // Relax all the edges
    for (int j = 0; j < e; j++)
    {
      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];
      if(dist[u]== 1e8){
        continue;
      }
      if(dist[u] + w < dist[v]){
        dist[v] = dist[u] + w;
        flag = 1;
      }
    }
    if(flag == 0){
      break;
    }
  }
  //To deduct the cycle
  for (int j = 0; j < e; j++)
    {
      int u = edges[j][0];
      int v = edges[j][1];
      int w = edges[j][2];
      if(dist[u]== 1e8){
        continue;
      }
      if(dist[u] + w < dist[v]){
        cout << -1 << endl;
        return;
      }
    }
    for (int i = 0; i < v; i++)
    {
      cout << dist[i] <<" ";
    }
}

// time complexity: (v-1)* e + e => VE;
// best case : E (inner loop runs only e time once)
// space complexity : V

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int>bellmanFord(int v,vector<vector<int>>edges,int src){
//     vector<int>dist(v,1e8);
//     dist[src] = 0;
//     for (int i = 0; i < v-1; i++)
//     {
//        bool flag = 0;
//        for (int i = 0; i < edges.size(); i++)
//        {
//           int u = edges[i][0];
//           int v = edges[i][1];
//           int w = edges[i][2];
//           if(dist[u] == 1e8) continue;
//           if(dist[u]+ w < dist[v]){
//             dist[v] = dist[u] + w;
//             flag = 1;
//           }
//     }
//     if(flag == 0) break;
//     }

//     for (int i = 0; i < edges.size(); i++)
//     {
//        int u = edges[i][0];
//           int v = edges[i][1];
//           int w = edges[i][2];
//           if(dist[u] == 1e8) continue;
//           if(dist[u]+ w < dist[v]){
//             return {-1};
//           }
//     }
//     return dist;
// }

// int main(){
//     int v,e;
//     cin >> v >> e;
//     vector<vector<int>>edges(e);
//     for (int i = 0; i < e; i++)
//     {
//       int u,v,w;
//       cin >> u >> v >> w;
//       edges[i] = {u,v,w};
//     }
//     vector<int> ans = bellmanFord(v,edges,0);
//     for (int i = 0; i < ans.size(); i++)
//     {
//       cout << ans[i] << " ";
//     }
    
// }
