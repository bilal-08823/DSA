class Solution {
public:

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp = triangle;

        for (int i = n - 2; i >= 0; i--) {

            for (int j = 0; j < triangle[i].size(); j++) {

                int smaller = min(dp[i + 1][j],
                                  dp[i + 1][j + 1]);

                dp[i][j] = triangle[i][j] + smaller;
            }
        }

        return dp[0][0];
    }
};