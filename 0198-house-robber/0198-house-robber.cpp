class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int curr = 0;
        int prev = 0;
        int next = 0;

        for(int i=0; i<n ;i++){
            int next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }

        return curr;
    }
};