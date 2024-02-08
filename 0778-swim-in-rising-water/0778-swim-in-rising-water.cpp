class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1){
            return 0;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n,0));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int result = max(grid[0][0], grid[n - 1][n - 1]);

        int drow[4] = {1,0,-1,0};
        int dcol[4] = {0,1,0,-1};

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it[0];
            int r = it[1];
            int c = it[2];
            visited[r][c] = 1;
            result = max(result, wt);

            for(int i = 0;i<4;i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow<0 || ncol<0 || nrow>=n || ncol>=n || visited[nrow][ncol]){
                    continue;
                }
                
                if (nrow == n - 1 && ncol == n - 1) { //once we reach the end we dont need to check for rest in queue
                    return result;
                }

                pq.push({grid[nrow][ncol], nrow, ncol});
                visited[nrow][ncol] = 1;
            }
        }

        return result;
    }
};