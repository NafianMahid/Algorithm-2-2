#include<iostream>
using namespace std;
int main(){
  int v,e;
  cin >> v >> e;
  vector<vector<int>>matrix(v);
  for (int i = 0; i < e; i++)
  {
    int u,v,w;
    cin >> u >> v >> w;
    matrix[i] ={u,v,w};
  }
  for (int i = 0; i < v; i++)
  {
   for (int j = 0; j < v; j++)
   {
     if(matrix[i][j] == -1){
      matrix[i][j] = INT_MAX;
     }
   }
   
  }
  
  for (int k = 0; k < v; k++)
  {
    for (int i = 0; i < v; i++)
    {
      for (int j = 0; j < v; j++)
      {
        if(matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX) continue; // handles -ve edge and integer overflow
        matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
      }
      
    }
    
  }
   for (int i = 0; i < v; i++)
  {
   for (int j = 0; j < v; j++)
   {
     if(matrix[i][j] == INT_MAX){
      matrix[i][j] = -1;
     }
   }
  }
}

// Time complexity : O(v^3)