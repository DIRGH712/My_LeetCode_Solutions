class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n+1,-1);
        // return min(helper(n-1,dp,cost), helper(n-2,dp,cost));
        
        int prev = cost[1];
        int prev2 = cost[0];
        if (n <= 2) return min(prev, prev2);

        for(int i = 2; i<n; i++){
            int curr = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }

        return min(prev2,prev);

    }

    // int helper(int n, vector<int>& dp, vector<int>& cost){

    //     if( n == 0 || n == 1) return cost[n];
    //     if (dp[n] != -1) return dp[n];
    //     int left = helper(n-1, dp, cost) + cost[n];
    //     int right = helper(n-2,dp,cost) + cost[n];

    //     return dp[n] = min(left,right);

    // }
};