class Solution {
public:
    int climbStairs(int n) {
        
        int prev = 1;
        int prev2 = 1;
        int curr;

        if (n == 0 || n == 1) {
            return 1;
        }

        for(int i= 2; i<=n; i++){
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
            
        }
        return curr;

    }
};