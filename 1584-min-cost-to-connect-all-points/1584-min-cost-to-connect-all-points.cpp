class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int sum = 0;
        int n = points.size();

        

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> visited(n,0);

        pq.push({0,0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if(visited[node] == 1) continue;
            sum += wt;
            visited[node] = 1;
            
            for(int adjnode = 0; adjnode<n; adjnode++){
                if(!visited[adjnode]){
                    int newwt = abs(points[adjnode][0] - points[node][0]) + abs(points[adjnode][1] - points[node][1]);
                    pq.push({newwt,adjnode});
                }
            }

        }

        return sum;
    }
};