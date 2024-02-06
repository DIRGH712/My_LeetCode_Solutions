class Solution {
    
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        vector<int> dis(n, INT_MAX);
        queue<pair<int, pair<int,int>>> q;

        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        q.push({0,{src,0}});

        // T = O(Edges flights.size())
        dis[src] = 0;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops>k) continue; // we are omiting adj nodes of this node buz it might me dst and we have reached max stops.

            for (auto it : adj[node]) {
                int adjnode = it.first;
                int wt = it.second;
                if (cost + wt < dis[adjnode] && stops<=k) {
                    dis[adjnode] = cost + wt;
                    q.push({stops + 1, {adjnode, cost+wt}});
                }
            }
        }

        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};
