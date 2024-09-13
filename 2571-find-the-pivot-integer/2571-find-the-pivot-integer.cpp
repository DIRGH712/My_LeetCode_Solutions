class Solution {
public:
    int pivotInteger(int n) {
        int totalSum = n * (n + 1) / 2;

      
        for (int x = 1; x <= n; x++) {
            int leftSum = x * (x + 1) / 2; 
            if (leftSum == totalSum - leftSum + x) {
                return x;
            }
        }

        return -1;
    }
};
