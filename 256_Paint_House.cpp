
//tle
class Solution {

	int dfs(int index, int preColor, vector<vector<int>>& costs, int sum)
	{
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

		return min;
	}

public:
	int minCost(vector<vector<int>>& costs) {

		return dfs(0, -1, costs, 0);
	}
};


class Solution {

	int dfs(int index, int preColor, vector<vector<int>>& costs)
	{
		if (costs.size() <= index)
		{
			return 0;
		}

		auto key = std::make_pair(index, preColor);

		if (memo.count(key))
		{
			return memo[key];
		}


		int min = INT_MAX;

		for (int i = 0; i < 3; i++)
		{
			if (i == preColor)
			{
				continue;
			}

			int r = dfs(index + 1, i, costs) + costs[index][i];

			min = std::min(r, min);
		}

		memo[key] = min;

		return min;
	}


	std::map<std::pair<int, int>, int> memo;

public:
	int minCost(vector<vector<int>>& costs) {

		return dfs(0, -1, costs);
	}
};

//memo
class Solution {
	std::vector<std::vector<int>> memo;

	int dfs(int index, int preColor, std::vector<std::vector<int>>& costs) {
		if (index >= costs.size()) {
			return 0;
		}

		if (preColor != -1 && memo[index][preColor] != -1) {
			return memo[index][preColor];
		}

		int minCost = INT_MAX;

		for (int i = 0; i < 3; i++) {
			if (i == preColor) {
				continue;
			}

			int r = dfs(index + 1, i, costs) + costs[index][i];
			minCost = std::min(r, minCost);
		}

		if (preColor != -1) {
			memo[index][preColor] = minCost;
		}

		return minCost;
	}

public:
	int minCost(std::vector<std::vector<int>>& costs) {
		int n = costs.size();
		if (n == 0) return 0;

		memo = std::vector<std::vector<int>>(n, std::vector<int>(3, -1));
		return dfs(0, -1, costs);
	}
};

//memo2
class Solution {
	std::map<std::tuple<int, int>, int> memo;

	int dfs(int index, int preColor, std::vector<std::vector<int>>& costs) {

		if (index >= costs.size()) {
			return 0;
		}

		auto key = std::make_tuple(index, preColor);
		if (memo.find(key) != memo.end()) {
			return memo[key];
		}

		int minCost = INT_MAX;

		for (int i = 0; i < 3; i++) {
			if (i == preColor) {
				continue;
			}

			int r = dfs(index + 1, i, costs) + costs[index][i];
			minCost = std::min(r, minCost);
		}

		memo[key] = minCost;
		return minCost;
	}

public:
	int minCost(std::vector<std::vector<int>>& costs) {
		int n = costs.size();
		if (n == 0) return 0;

		memo.clear();
		return dfs(0, -1, costs);
	}
};


//dp
class Solution {
public:
	int minCost(vector<vector<int>>& costs) {

		for (int i = costs.size() - 2; 0 <= i; i--)
		{
			costs[i][0] += std::min(costs[i + 1][1], costs[i + 1][2]);
			costs[i][1] += std::min(costs[i + 1][0], costs[i + 1][2]);
			costs[i][2] += std::min(costs[i + 1][0], costs[i + 1][1]);
		}

		return std::min(costs[0][0], std::min(costs[0][1], costs[0][2]));
	}
};