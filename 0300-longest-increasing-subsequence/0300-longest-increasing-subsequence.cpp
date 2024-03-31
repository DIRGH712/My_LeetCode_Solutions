class Solution {

// int helper(int ind, int prev, vector<vector<int>> &dp, int n, vector<int>& nums){
//     if(ind == n)
//         return 0;
    
//     if(dp[ind][prev +1] != -1)
//         return dp[ind][prev +1];
//     int len = 0 + helper(ind + 1, prev,dp,n,nums);
//     if(prev == -1 || nums[ind] > nums[prev]){
//         len = max(len, 1 + helper(ind + 1, ind,dp,n,nums));
//     }

//     return dp[ind][prev +1] = len;
// }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return helper(0,-1,dp,n, nums);
        

        vector<int> temp;
        temp.push_back(nums[0]);

        int len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                // If arr[i] is greater than the last element of temp, extend the subsequence
                temp.push_back(nums[i]);
                len++;
            } else {
                // If arr[i] is not greater, replace the element in temp with arr[i]
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }

        return len;
        
        /*
        vector<int> dp(n, 1);
        int result = 1;
        for(int ind = 1; ind <n; ind++){
            for(int prev = 0; prev<ind; prev++){
                if(nums[ind] > nums[prev]){
                    dp[ind] = max(dp[ind], dp[prev] + 1);
                }
            }
            result = max(result,dp[ind]);
        }
        return result;
        */


        /*
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int ind = n-1;ind>=0;ind--){
            for(int prev = ind-1;prev>=-1;prev--){
                int nottake = dp[ind+1][prev+1];
                int take =0;
                if(prev==-1 || nums[ind]>nums[prev]){
                    take = 1+dp[ind+1][ind+1];
                }
                dp[ind][prev+1]=max(nottake,take);
                }
            }
        return dp[0][0];
        */
    }
};