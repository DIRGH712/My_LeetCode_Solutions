class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        //vector<int> prev(m + 1, 0), cur(m + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= m; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
                    // cur[ind2] = 1 + prev[ind2 - 1];
                
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
                    //cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
            }

            //prev = cur;
        }

        return dp[n][m];
        //return prev[m];
    
    }
};
/* for printing longest LCS
    
    int len = dp[n][m];
    int i = n;
    int j = m;
    string s = "";
    for (int k = 1; k <= len; k++) {
        str += "$"; // dummy string
    }

    while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}
/*



/* Memorization 0(N*M), 0(N*M) + 0(n+m)

class Solution {

    int helper(int i, int j, vector<vector<int>>& dp, string text1, string text2){

        if(i<0 || j<0){  // if(i == 0 || j == 0)
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text2[j]){ //do i -1 and j - 1, we are dng shifting was this type of b case
            return dp[i][j] = 1 + helper(i-1,j-1,dp, text1, text2);
        }

        else{
            return dp[i][j] = 0 + max(helper(i-1,j,dp, text1, text2), helper(i,j-1,dp, text1, text2));
        }
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        return helper(n-1, m-1, dp, text1, text2);
    }
};

*/