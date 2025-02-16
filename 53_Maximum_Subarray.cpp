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

//fail
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


class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		vector<int> dp(nums.size());

		dp[0] = nums[0];

		int ret = dp[0];

		for (int i = 1; i < nums.size(); i++)
		{
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			ret = max(ret, dp[i]);
		}
	
		return ret;
	}
};

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int curSum = nums[0];
		int ret = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			//If there are consecutive negative numbers, nums[i] will become cursum.
			curSum = max(curSum + nums[i], nums[i]);
			ret = max(ret, curSum);
		}

		return ret;
	}
};


//fail
class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));

		int max = INT_MIN;

		for (int i = 0; i < nums.size(); i++)
		{
			dp[i][i] = nums[i];

			max = std::max(max, dp[i][i]);

			if (i < nums.size() - 1)
			{
				dp[i][i + 1] = nums[i] + nums[i + 1];
				max = std::max(max, dp[i][i + 1]);
			}
		}
		
	
		for (int size = 3; size <= nums.size(); size++)
		{
			for (int i = 0; i <= nums.size() - size; i++)
			{
				dp[i][i + size - 1] = dp[i + 1][i + size - 2] + nums[i] + nums[i + size - 1];
				max = std::max(max, dp[i][i + size - 1]);
			}
		}


		return max;
	}
};

//fail
class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		vector<int> dp(nums.size());

		int max = INT_MIN;
		for (int i = 0; i < nums.size(); i++)
		{
			dp[i] = nums[i];
			max = std::max(max, dp[i]);
		}

		for (int size = 2; size <= nums.size(); size++)
		{
			for (int i = 0; i <= nums.size() - size; i++)
			{
				dp[i] = dp[i] + nums[i + size - 1]);
				max = std::max(max, dp[i]);
			}
		}


		for (int i = 0; i < dp.size(); i++)
		{
			cout << dp[i] << " ";
		}

		return dp[0];
	}
};



class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		int cur = nums[0];
		int ret = cur;

		for (int i = 1; i < nums.size(); i++)
		{
			cur = max(cur + nums[i], nums[i]);
			ret = max(ret, cur);
		}

		return ret;
	}
};


class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		vector<int> dp(nums.size());

		dp[0] = nums[0];

		int ret = dp[0];

		for (int i = 1; i < nums.size(); i++)
		{
			//logic error 
			//if (dp[i - 1] <= dp[i - 1] + nums[i])
			//{
			//	dp[i] = dp[i - 1] + nums[i];
			//}
			//else
			//{
			//	dp[i] = nums[i];
			//}

			//because we need to get consicutive sum, we sum dp and nums[i] or not.
			//when nagative numbers appear consecutively, use nums[i] 
			dp[i] = max(dp[i - 1] + nums[i], nums[i]);
			
			ret = max(ret, dp[i]);
		}

		return ret;
	}
};
