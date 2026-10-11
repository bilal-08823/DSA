class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // i is 0-based, so actual index = i + 1
            if (n % (i + 1) == 0) {
                ans += nums[i] * nums[i];
            }
        }

        return ans;
    }
};