// TC O(v^2)
// SC O(v)
class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>>adj[], int s) {
        // Code here
        vector<bool>explored(v,0);
        vector<int>dist(v,INT_MAX);
        dist[s] = 0;
        int count = v;
        while(count--){
            // select a node which is not explored yet and calculate its dist
        int node = -1,value = INT_MAX;
        for(int i = 0 ; i<v;i++){
            if(!explored[i] && value > dist[i]){
                node = i;
                value = dist[i];
            }
        }
        explored[node] = 1;
        
        // relax the edges
        
        for(int i = 0;i<adj[node].size();i++){
            int neighbour = adj[node][i][0];
            int weight = adj[node][i][1];
            if(!explored[neighbour] && (dist[node] + weight < dist[neighbour])){
                dist[neighbour] = dist[node] + weight;
            }
        }
    }
        return dist;
    }
};