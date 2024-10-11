
//bfs
class Solution {

	int dfs(int y, int x, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
	{
		if (0 < dp[y][x])
		{
			return dp[y][x];
		}

		if (1 == obstacleGrid[y][x])
		{
			return 0;
		}

		if (y == obstacleGrid.size() - 1 && x == obstacleGrid[0].size() - 1) 
		{
			return 1;
		}

		int l = 0;
		int b = 0;

		if (x < obstacleGrid[0].size() - 1)
		{
			l = dfs(y, x + 1, obstacleGrid, dp);
		}

		if (y < obstacleGrid.size() - 1)
		{
			b = dfs(y + 1, x, obstacleGrid, dp);
		}

		dp[y][x] = l + b;

		return l + b;
	}

public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		vector<vector<int>> dp(
			obstacleGrid.size(),
			vector<int>(obstacleGrid[0].size())
		);


		return dfs(0, 0, obstacleGrid, dp);

	}
};

//bfs
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		vector<vector<int>> dp(
			obstacleGrid.size(),
			vector<int>(obstacleGrid[0].size())
		);


		for (int y = 0; y < obstacleGrid.size(); y++)
		{
			if (y == 0 && 0 == obstacleGrid[y][0] || 0 < y && 0 == obstacleGrid[y][0] && 1 == dp[y - 1][0])
			{
				dp[y][0] = 1;
			}
		}

		for (int x = 0; x < obstacleGrid[0].size(); x++)
		{
			if (0 == x && 0 == obstacleGrid[0][x] || 0 < x && 0 == obstacleGrid[0][x] && 1 == dp[0][x - 1])
			{
				dp[0][x] = 1;
			}
		}

		for (int y = 1; y < obstacleGrid.size(); y++)
		{
			for (int x = 1; x < obstacleGrid[0].size(); x++)
			{
				if (0 == obstacleGrid[y][x])
				{
					dp[y][x] = dp[y - 1][x] + dp[y][x - 1];
				}
			}
		}

		return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};

//optimized bfs
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		if (1 == obstacleGrid[0][0])
		{
			return 0;
		}
		
		obstacleGrid[0][0] = 1;

		for (int y = 1; y < obstacleGrid.size(); y++)
		{
			obstacleGrid[y][0] =
				(0 == obstacleGrid[y][0] && 1 == obstacleGrid[y - 1][0]) ? 1 : 0;
		}

		for (int x = 1; x < obstacleGrid[0].size(); x++)
		{
			obstacleGrid[0][x] =
				(0 == obstacleGrid[0][x] && 1 == obstacleGrid[0][x - 1]) ? 1 : 0;
		}


		for (int y = 1; y < obstacleGrid.size(); y++)
		{
			for(int x = 1; x < obstacleGrid[0].size(); x++)
			{
				if (0 == obstacleGrid[y][x])
				{
					obstacleGrid[y][x] = obstacleGrid[y - 1][x] + obstacleGrid[y][x - 1];
				}
				else
				{
					obstacleGrid[y][x] = 0;
				}
			}
		}

		return obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};