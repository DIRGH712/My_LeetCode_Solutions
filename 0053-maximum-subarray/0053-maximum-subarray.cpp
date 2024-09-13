class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MIN;

        for(auto n : nums){
            sum += n;
            mini = max(sum,mini);
            sum = sum < 0 ? 0 : sum;
        }

        return mini;
    }
};
