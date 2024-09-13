class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int mini = INT_MIN;

        for(auto n : nums){
            sum += n;
            if(sum > mini){
                mini = sum;
            }

            if(sum <0){
                sum = 0;
            }
        }

        return mini;
    }
};
