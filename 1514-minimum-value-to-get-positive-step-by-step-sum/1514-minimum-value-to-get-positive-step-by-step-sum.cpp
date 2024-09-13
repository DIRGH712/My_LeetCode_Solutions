class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int mini = nums[0];

        for(int i=1; i<nums.size(); i++){
            nums[i] = nums[i] + nums[i-1];
            mini = min(mini, nums[i]);
        }

        if(mini <=0)
            return 1 + (-1 * mini);
        
        return 1;
    }
};