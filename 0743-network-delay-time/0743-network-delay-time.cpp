class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        vector<int> dist(n+1, INT_MAX);
        queue<int> q;
        q.push(k);
        dist[k] = 0;

        for(auto time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto adjnode : adj[node]){
                if(dist[node] + adjnode.second < dist[adjnode.first]){
                    dist[adjnode.first] = dist[node] + adjnode.second;
                    q.push(adjnode.first);
                }
            }
        }
        int result = 0;
        // start from 1 buz nodes are not zero indexed, it starts from 1
        for(int i=1 ;i<=n;i++){
            if(dist[i] == INT_MAX)  return -1;
            result = max (result, dist[i]);
        }
        return result;

    }
};