class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]++;
        int result = 0, currsum = 0;
        

        for(auto n : nums){
            currsum += n;
            int diff = currsum - k;

            if(m.find(diff) != m.end()){
                result += m[diff];
            }

            m[currsum]++;
        }

        return result;
    }
};