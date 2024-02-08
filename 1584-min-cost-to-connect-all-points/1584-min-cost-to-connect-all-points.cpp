class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n,0);

        pq.push({0,0});
        int edgesUsed = 0;
        int totalcost = 0;

        while(edgesUsed < n){
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;
            if(vis[node]){
                continue;
            }

            vis[node] = 1;
            totalcost+=wt;
            edgesUsed++;

            for(int adjnode = 0; adjnode<n; adjnode++){
                if(!vis[adjnode]){
                    int nextwt = abs(points[node][0] - points[adjnode][0]) + 
                                    abs(points[node][1] - points[adjnode][1]);
                    pq.push({nextwt,adjnode});
                }
            }
        }

        return totalcost;
    }
};