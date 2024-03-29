class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
       
        for (int i = 1; i < m; i++) {
            vector<int> temp(n,1);
            for (int j = 1; j < n; j++) {
                temp[j] = dp[j] + temp[j-1];
            }
            dp = temp;
        }
        return dp[n-1];
    }
};