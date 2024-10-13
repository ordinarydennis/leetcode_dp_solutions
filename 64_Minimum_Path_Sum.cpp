class Solution {

	int dfs(int y, int x, vector<vector<int>>& grid)
	{
		if (0 < dp[y][x])
			return dp[y][x];

		if (y == targetY && x == targetX)
			return dp[y][x] = grid[y][x];

		int b = INT_MAX;
		int l = INT_MAX;

		if (x < targetX)
		{
			l = dfs(y, x + 1, grid);
		}

		if (y < targetY)
		{
			b = dfs(y + 1, x, grid);
		}

		dp[y][x] = std::min(l, b) + grid[y][x];

		return dp[y][x];
	}


	int targetY = 0;
	int targetX = 0;

	vector<vector<int>> dp;

public:
	int minPathSum(vector<vector<int>>& grid) {

		dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size()));

		targetY = grid.size() - 1;
		targetX = grid[0].size() - 1;

		dfs(0, 0, grid);

		return dp[0][0];
	}
};


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size()));

		dp[0][0] = grid[0][0];

		for (int i = 1; i < grid.size(); i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}

		for (int i = 1; i < grid[0].size(); i++)
		{
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}


		for (int y = 1; y < grid.size(); y++)
		{
			for (int x = 1; x < grid[0].size(); x++)
			{
				dp[y][x] = std::min(
					dp[y - 1][x],
					dp[y][x - 1]
				) + grid[y][x];
			}
		}

		return dp[grid.size() - 1][grid[0].size() - 1];
	}
};


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {

		int maxY = grid.size() - 1;
		int maxX = grid[0].size() - 1;

		vector<vector<int>> dp(maxY + 1, vector<int>(maxX + 1));

		for (int y = maxY; 0 <= y; y--)
		{
			for (int x = maxX; 0 <= x; x--)
			{
				if (y == maxY && x == maxX)
					dp[y][x] = grid[y][x];
				else if (y == maxY && x < maxX)
					dp[y][x] = dp[y][x + 1] + grid[y][x];
				else if (y < maxY && x == maxX)
					dp[y][x] = dp[y + 1][x] + grid[y][x];
				else
					dp[y][x] = std::min(dp[y + 1][x], dp[y][x + 1]) + grid[y][x];
			}
		}

		return dp[0][0];
	}
};