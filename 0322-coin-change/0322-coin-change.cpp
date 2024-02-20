// Tabulation + space

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
    
    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0); 
  
    for (int i = 0; i <= amount; i++) {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }
    
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= amount; target++) {
    
            int notTake = prev[target];
            
            int take = 1e9;
            if (coins[ind] <= target)
                take = 1 + cur[target - coins[ind]];
                
            cur[target] = min(notTake, take);
        }
        
        prev = cur;
    }
    

    int ans = prev[amount];
    
    if (ans >= 1e9)
        return -1;
    
    return ans;
    }
};


/* Tablulation 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
               dp[0][i] = 1e9;
    
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
            
                int notTake = dp[ind - 1][target];
                
                int take = 1e9;
                if (coins[ind] <= target)
                    take = 1 + dp[ind][target - coins[ind]];
                    
                dp[ind][target] = min(notTake, take);
            }
        }

        int ans = dp[n-1][amount];

        if(ans == 1e9)
            return -1;
        return ans;

    }
};




/* Memoriztion

class Solution {
public:

    int helper(int ind, int target, vector<vector<int>>&  dp, vector<int>& arr){
        if(ind == 0){
            if(target % arr[ind] == 0) {
                return target/arr[0];
            }
            else{
                return 1e9;
            }
        }

        if(dp[ind][target] != -1) return dp[ind][target];

        int nottake = 0 + helper(ind-1, target, dp, arr);
        int take = 1e9;

        if(arr[ind] <= target){
            take = 1 + helper(ind, target - arr[ind], dp, arr);
        }

        return dp[ind][target] = min(take,nottake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>>  dp(n, vector<int>(amount + 1, -1));

        int ans = helper(n-1,amount,dp, coins);
        if(ans == 1e9)
            return -1;
        return ans;
    }
};

*/ 
