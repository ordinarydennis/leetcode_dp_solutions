class Solution {

    int dfs(int x, int y, int maxX, int maxY, vector<vector<int>>& dp)
    {
        if (maxX < x || maxY < y)
            return 0;

        if (0 < dp[y][x])
            return dp[y][x];

        if (x == maxX && y == maxY)
            return 1;

        dp[y][x] = dfs(x + 1, y, maxX, maxY, dp) + dfs(x, y + 1, maxX, maxY, dp);

        return dp[y][x];
    }


public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n));

        return dfs(0, 0, n - 1, m - 1, dp);
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int y = 0; y < m - 1; y++)
        {
            for (int x = 0; x < n - 1; x++)
            {
                dp[y + 1][x + 1] = dp[y][x + 1] + dp[y + 1][x];
            }
        }

        return dp[m - 1][n - 1];
    }
};