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


//brute force
class Solution {
public:
	int maxSubArray(vector<int>& nums) {


		int ret = INT_MIN;

		for (int s = 0; s < nums.size(); s++)
		{
			int sum = 0;

			for (int e = s; e < nums.size(); e++)
			{
				ret = std::max(ret, sum += nums[e]);
			}
		}

		return ret;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		vector<int> dp(nums.size() + 1);

		dp[0] = 0;

		int max = dp[0];
		int min = dp[0];

		int minIndex = 0;
		int maxIndex = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			dp[i + 1] += nums[i] + dp[i];

			if (dp[i + 1] < min)
			{
				min = dp[i + 1];
				minIndex = i + 1;
			}

			if (max < dp[i + 1])
			{
				max = dp[i + 1];
				maxIndex = i + 1;
			}
		}

		return dp[maxIndex] - dp[minIndex];
	}
};
