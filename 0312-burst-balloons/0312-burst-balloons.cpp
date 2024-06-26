class Solution {
int helper(int i, vector<int>& nums, int j, vector<vector<int>>& dp){

    if(i>j) return 0;
    int maxi = -1e9;

    if(dp[i][j]!=-1)
        return dp[i][j];

    for(int ind = i; ind<=j; ind++){
        int cost = nums[i-1] * nums[ind] * nums[j+1] + helper(i,nums,ind-1, dp) + helper(ind+1,nums,j, dp);
        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;

}
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return helper(1, nums, n, dp);
    }
};