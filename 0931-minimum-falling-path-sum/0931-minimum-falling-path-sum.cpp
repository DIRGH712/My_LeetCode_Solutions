/* memorization
class Solution {
public:

    int getMinUtil(int i, int j, int col, vector<vector<int>>& matrix,  vector<vector<int>>& dp ){
        
        if(j<0 || j>=col){
            return 1e9;
        }

        if(i==0){
            return matrix[0][j];
        }

        if(dp[i][j] != 1e9){
            return dp[i][j];
        }

        int up = matrix[i][j] + getMinUtil(i - 1, j, col, matrix, dp);
        int leftDiagonal = matrix[i][j] + getMinUtil(i - 1, j - 1, col, matrix, dp);
        int rightDiagonal = matrix[i][j] + getMinUtil(i - 1, j + 1, col, matrix, dp);

        return dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
    }


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp (n, vector<int>(m,1e9));
        int mini = INT_MAX;

        for (int j = 0; j < m; j++) {
            int ans = getMinUtil(n - 1, j, m, matrix, dp); 
            mini = min(mini, ans);
        }

        return mini;
    }
};

*/


/* Tabulation 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int up = matrix[i][j] + dp[i - 1][j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[i - 1][j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[i - 1][j + 1];
                } else {
                    rightDiagonal += 1e9;
                }

                dp[i][j] = min(up, min(leftDiagonal, rightDiagonal));
            }
        }
        
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n - 1][j]);
        }

        return mini;
    }   
};

*/




// Tabulation + space optimization

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m, 0);
        for (int j = 0; j < m; j++) {
            dp[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            vector<int> temp(m,0);

            for (int j = 0; j < m; j++) {
                
                int up = matrix[i][j] + dp[j];

                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0) {
                    leftDiagonal += dp[j - 1];
                } else {
                    leftDiagonal += 1e9; 
                }

                int rightDiagonal = matrix[i][j];
                if (j + 1 < m) {
                    rightDiagonal += dp[j + 1];
                } else {
                    rightDiagonal += 1e9;
                }

                temp[j] = min(up, min(leftDiagonal, rightDiagonal));
            }

            dp = temp;
        }
        
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[j]);
        }

        return mini;
    }   
};























