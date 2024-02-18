class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;

        for(int i=0;i<nums.size();i++){
            target+= nums[i];
        }

        if(target % 2 !=0 ) 
            return false;
        else {
            int k = target /2;

            vector<bool> prev(k + 1, false);
            prev[0] = true;

            if(nums[0]<=k) prev[nums[0]] = true;

            for (int ind = 1; ind < nums.size(); ind++) {
                // Create a vector to represent the current row of the DP table
                vector<bool> cur(k + 1, false);
                cur[0] = true;

                for (int target = 1; target <= k; target++) {
                    // Exclude the current element
                    bool notTaken = prev[target];

                    // Include the current element if it doesn't exceed the target
                    bool taken = false;
                    if (nums[ind] <= target)
                        taken = prev[target - nums[ind]];

                    // Update the current row of the DP table
                    cur[target] = notTaken || taken;
                }

                // Set the current row as the previous row for the next iteration
                prev = cur;
            }
            return prev[k];
            
        }    
        
    }
};