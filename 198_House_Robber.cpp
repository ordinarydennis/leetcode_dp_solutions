
//memoization
class Solution {

	int dfs(int index, vector<int>& nums)
	{
		if (memo.count(index)) return memo[index];

		if (nums.size() - 1 == index) return nums[index];

		else if (nums.size() <= index) return 0;

		return memo[index] = std::max(
			dfs(index + 1, nums),
			nums[index] + dfs(index + 2, nums)
		);;
	}

	std::unordered_map<int, int> memo;


public:
	int rob(vector<int>& nums) {

		return dfs(0, nums);

	}
};