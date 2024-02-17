class Solution {
public:
    //int minCost(vector<vector<int>> &grid, int m, int n,vector<vector<int>>& dp) { 
    //   if (n <0 || m <0) 
    //      return INT_MAX; 
    //   else if(m==0 && n==0) 
    //      return grid[m][n]; 
    //   if(dp[m][n]!=-1)
    //       return dp[m][n];
    //   int cost = grid[m][n] + min(minCost(grid,m-1,n,dp),minCost(grid,m,n-1,dp)); 
    //   return dp[m][n] = cost;
    // } 
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        cout<<m<<n;
        vector<int> dp(m, 0);

        

        for(int i=0; i<n; i++){
            vector<int> temp(m, 0);

            for(int j =0; j<m;j++){
                if(i ==0 && j==0) temp[j] = grid[i][j];
                else{
                    int up = 0;
                    int left = 0;

                    if(i>0){
                        up = grid[i][j] + dp[j];
                    }
                    else{
                        up+=1e9;
                    }

                    if(j>0){
                        left = grid[i][j] + temp[j-1];
                    }
                    else{
                        left+=1e9;
                    }

                    temp[j] = min(left,up);
                }
            }
            dp = temp;
            
        }
        return dp[m-1];
    }
    
};