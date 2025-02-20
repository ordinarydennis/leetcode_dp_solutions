class Solution {

	int dfs(int x, int y, vector<vector<int>>& grid)
	{

		if (y < 0 || grid.size() <= y)
		{
			return 0;
		}

		if (grid[0].size() <= x)
		{
			return 0;
		}



		if (dp.end() != dp.find(pair<int, int>{y, x}))
		{
			return dp[pair<int, int>{y, x}];
		}
		

		//if (grid[0].size() <= x + 1)
		//{
		//	return 0;
		//}

		int a = -1;
		int b = -1;
		int c = -1;

		if (x + 1 < grid[0].size() && grid[y][x] < grid[y][x + 1])
		{
			a = dfs(x + 1, y, grid);
		}

		if (y + 1  < grid.size() && x + 1 < grid[0].size() && grid[y][x] < grid[y + 1][x + 1])
		{
			b = dfs(x + 1, y + 1, grid);
		}
		
		if (0 <= y - 1 && x + 1 < grid[0].size() && grid[y][x] < grid[y - 1][x + 1])
		{
			c = dfs(x + 1, y - 1, grid);
		}

		dp[pair<int, int>{ y, x }] = std::max(std::max(a, b), c) + 1;

		return dp[pair<int, int>{ y, x }];
	}

	map<pair<int, int>, int> dp;

public:
	int maxMoves(vector<vector<int>>& grid) {

		int ret = 0;

		for (int i = 0; i < grid.size(); i++)
		{
			ret = std::max(ret, dfs(0, i, grid));
		}

		return ret;
	}
};
