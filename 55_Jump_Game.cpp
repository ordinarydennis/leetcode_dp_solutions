class Solution {

	int dfs(int index, vector<int>& nums)
	{
		if (dp.count(index))
		{
			return dp[index];
		}

		if (nums.size() - 1 <= index)
		{
			return 0;
		}

		if (0 == nums[index])
		{
			return -1;
		}

		int min = INT_MAX;

		for (int i = 1; i <= nums[index]; i++)
		{
			int result = dfs(index + i, nums);

			if (0 <= result)
			{
				min = std::min(min, result);
			}
		}

		return dp[index] = (INT_MAX == min) ? -1 : min + 1;
	}


	unordered_map<int, int> dp;

public:
	int jump(vector<int>& nums) {

		return dfs(0, nums);

	}
};

class Solution {
	
	bool dfs(int index, vector<int>& nums)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (nums.size() <= index)
		{
			return false;
		}

		if (nums.size() - 1 == index)
		{
			return true;
		}

		int jump = nums[index];

		bool result = false;

		for (int i = 1; i <= jump; i++)
		{
			result = dfs(index + i, nums);

			if (result)
			{
				break;
			}
		}

		memo[index] = result;

		return result;
	}

	unordered_map<int, bool> memo;

public:
	bool canJump(vector<int>& nums) {

		return dfs(0, nums);

	}
};