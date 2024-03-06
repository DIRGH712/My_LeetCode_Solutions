const int prime = 1e9 + 7;

class Solution {
public:
    
    int countUtil(string s1, string s2, int ind1, int ind2, vector<vector<int>>& dp) {
    // If s2 has been completely matched, return 1 (found a valid subsequence)
    if (ind2 < 0)
        return 1;
    
    // If s1 has been completely traversed but s2 hasn't, return 0
    if (ind1 < 0)
        return 0;

    // If the result for this state has already been calculated, return it
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];

    int result = 0;

    // If the characters match, consider two options: either leave one character in s1 and s2
    // or leave one character in s1 and continue matching s2
    if (s1[ind1] == s2[ind2]) {
        int leaveOne = countUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        int stay = countUtil(s1, s2, ind1 - 1, ind2, dp);

        result = leaveOne + stay;
    } else {
        // If characters don't match, just leave one character in s1 and continue matching s2
        result = countUtil(s1, s2, ind1 - 1, ind2, dp);
    }

    // Store the result and return it
    dp[ind1][ind2] = result;
    return result;
}
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();

         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return countUtil(s, t, n - 1, m - 1, dp);

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {

                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
                } else {
                    // If the characters don't match, we can only leave the current character in s1
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};