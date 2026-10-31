class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;

        int m = grid.size();
        int n = grid[0].size();

        vector<long long> dp(n, 0);

        dp[0] = 1;

        long long left = 0;

        for (int i = 0; i < m; i++) {

            left = 0;

            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0) {
                    long long total = (left + dp[j]) % MOD;

                    left = total;
                    dp[j] = total;
                } 
                else {
                    long long fromAbove = dp[j];
                    long long fromLeft = left;

                    left = fromAbove;
                    dp[j] = fromLeft;
                }
            }
        }

        return (int)left;
    }
};