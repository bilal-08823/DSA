class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        
        dist[0][1] = 0;
        pq.push({0, 0, 1});
        
        while (!pq.empty()) {
            auto [w, u, cnt] = pq.top();
            pq.pop();
            
            if (w > dist[u][cnt]) continue;
        
            if (u == n - 1) return w;
            
            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                int new_cnt = (labels[u] == labels[v]) ? cnt + 1 : 1;
                
                if (new_cnt <= k) {
                    if (w + weight < dist[v][new_cnt]) {
                        dist[v][new_cnt] = w + weight;
                        pq.push({w + weight, v, new_cnt});
                    }
                }
            }
        }
        
        return -1; 
    }
};