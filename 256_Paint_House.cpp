class Solution {

	int dfs(int index, int preColor, vector<vector<int>>& costs, int sum)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (costs.size() <= index)
		{
			return sum;
		}

		int min = INT_MAX;

		for (int i = 0; i < 3; i++)
		{
			if (i == preColor)
			{
				continue;
			}

			int r = dfs(index + 1, i, costs, costs[index][i] + sum);

			min = std::min(r, min);
		}

		memo[index] = min;

		return min;
	}


	unordered_map<int, int> memo;


public:
	int minCost(vector<vector<int>>& costs) {

		return dfs(0, -1, costs, 0);
	}
};

