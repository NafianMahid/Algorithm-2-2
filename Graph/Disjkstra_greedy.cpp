class Solution {
  public:
    vector<int> dijkstra(int v, vector<vector<int>>adj[], int s) {
        // Code here
        vector<bool>explored(v,0);
        vector<int>dist(v,INT_MAX);
        dist[s] = 0;
        // priority_queue<int , vector<int>, greater<int>>p; // building a min heap
        // we need pair to store in the priority_queue
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>>p;// replace int to pair<int,int>
        p.push({0,s});
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            if(explored[node] == 1) continue;
            explored[node] = 1;
             // relax the edges
        
            for(int i = 0;i<adj[node].size();i++){
            int neighbour = adj[node][i][0];
            int weight = adj[node][i][1];
            if(!explored[neighbour] && (dist[node] + weight < dist[neighbour])){
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour],neighbour});
            }
        }
        }
       
        return dist;
    }
};