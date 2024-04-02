class Solution {

int helper(string s1, string s2, string s3, int i, int j, vector<vector<int>>& dp) {
        if(i == s1.size() && j == s2.size()) {
                return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if (i < s1.size() && s1[i] == s3[i + j] && helper(s1, s2, s3, i + 1, j,dp)) {
            return dp[i][j]= 1;
        }
        if (j < s2.size() && s2[j] == s3[i + j] && helper(s1, s2, s3, i, j + 1,dp)) {
            return dp[i][j] = 1;
        }
        dp[i][j] = 0;
        return dp[i][j];
}   

public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }

        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));

        return helper(s1, s2, s3, 0,0,dp);
    }
};