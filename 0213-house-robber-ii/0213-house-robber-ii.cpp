class Solution {

private:

    int helper(int l, int r, vector<int>& arr){

        int prev = 0;
        int prev2 = 0;
        
        for(int i=l; i<=r; i++){
            int pick = arr[i];
            // if(i>1)
                pick += prev2;
            int nonPick = 0 + prev;
            
            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;
            
        }
        return prev;
    }
    

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(helper(1,n-1,nums),helper(0,n-2,nums));
    }
};