/*

class Solution {

    int helper(string s1, string s2, int i, int j, vector<vector<int>>& dp){
        if(i<0){
            return j + 1;
        }
        if(j<0){
            return i + 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s1[i] == s2[j]){
            return dp[i][j] = 0 + helper(s1,s2, i-1, j-1,dp);
        }

        return dp[i][j] = 1 + min(helper(s1,s2,i-1,j-1, dp), 
                            min(helper(s1,s2, i,j-1, dp),
                            helper(s1,s2,i-1,j,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return helper(word1, word2, n-1, m-1, dp);

        vector<vector<int>> dp(n + 1,vector<int> (m + 1,0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
          dp[0][j] = j;
        }

        for(int i = 1; i<=n; i++){
            for(int j =1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = 0 +  dp[i-1][j-1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
                }
            }
        }

        return dp[n][m];
    }
};

*/




class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // Create two arrays to store previous and current row of edit distances
        vector<int> prev(m + 1, 0);
        vector<int> cur(m + 1, 0);

        if(n == 0 && m !=0){
            return m;
        }
        
        // Initialize the first row
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        // Calculate edit distances row by row
        for (int i = 1; i <= n; i++) {
            cur[0] = i; // Initialize the first column of the current row
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // If the characters match, no additional cost
                    cur[j] = prev[j - 1];
                } else {
                    // Minimum of three choices:
                    // 1. Replace the character at S1[i-1] with S2[j-1]
                    // 2. Delete the character at S1[i-1]
                    // 3. Insert the character at S2[j-1] into S1
                    cur[j] = 1 + min(prev[j - 1], min(prev[j], cur[j - 1]));
                }
            }
            prev = cur; // Update the previous row with the current row
        }

        // The value at cur[m] contains the edit distance
        return cur[m];
    }
};