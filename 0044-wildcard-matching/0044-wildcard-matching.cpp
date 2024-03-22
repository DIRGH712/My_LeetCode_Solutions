class Solution {

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n+1, vector<bool>(m+1,false));
        dp[0][0] = true;

        for(int i=1;i<=n; i++)
            dp[i][0] = false;
        
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]!='*')
                flag=false;
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};


/*

class Solution {

bool isAllStars(string &S1, int i) {
    for (int j = 0; j <= i; j++) {
        if (S1[j] != '*')
            return 0;
    }
    return 1;
}

int helper(int i, int j, string s, string p,  vector<vector<int>> &dp){

    if (i < 0 && j < 0)
        return 1;
    
    if (j < 0 && i >= 0)
        return 0;
    
    if (i < 0 && j >= 0)
        return isAllStars(p, j);
   
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == p[j] || p[j] == '?'){
        return dp[i][j] = helper(i-1,j-1, s,p,dp);
    }
    else{
        if(p[j] == '*'){
            return dp[i][j] = helper(i-1, j, s, p, dp) || helper(i, j-1, s,p,dp); 
        }
        else
            return 0;
    }
}

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        return helper(n-1, m-1, s, p, dp);
    }
};

*/