class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int result = nums[0];
        int curMin = 1, curMax = 1;
        int n = nums.size();

        for(int i=0; i<n;i++){
            int temp = curMax * nums[i];
            curMax = max(max(nums[i] * curMax, nums[i] * curMin), nums[i]);
            curMin = min(min(temp, nums[i] * curMin), nums[i]);
            result = max(curMax,result);
        }
        return result;
    }
};