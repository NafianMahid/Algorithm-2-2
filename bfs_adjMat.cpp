#include<iostream>
#include<queue>
using namespace std;
void bfs(vector<vector<bool>>adjMat,int start,int v){
      vector<bool>vis(v,false);
      vis[start] = true;
      queue<int>q;
      q.push(start);
      while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " " ;
        for(int i = 0;i<v;i++){
          if(adjMat[curr][i]==1 && !vis[i]){
            vis[i] = true;
            q.push(i);
          }
        }
      }
}
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<bool>>adjMat(v,vector<bool>(v,0));
  for (int i = 0; i < e; i++)
  {
    /* code */
    int u,v;
    cin >> u >> v;
    adjMat[u][v] = 1;
    adjMat[v][u] = 1;
  }
  bfs(adjMat,0,v);
}