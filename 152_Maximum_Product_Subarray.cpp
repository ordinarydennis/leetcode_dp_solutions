//time limit
class Solution {

	void dfs(int index, int product, vector<int>& nums)
	{

		if (nums.size() <= index)
			return;


		if (ret < nums[index] * product)
		{
			ret = nums[index] * product;
			dp[index] = ret;
		}

		dfs(index + 1, product * nums[index], nums);
	}

	int ret = INT_MIN;

public:
	int maxProduct(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			dfs(i, 1, nums);
		}


		return ret;
	}
};

class Solution {

	int dfs(int index, int product, vector<int>& nums)
	{
		if (nums.size() - 1 == index)
		{
			return nums[index];
		}

		if (dp.count(index))
		{
			return dp[index];
		}


		int r = dfs(index + 1, product * nums[index], nums);

		dp[index] = max(r, r * nums[index]);
		

		return dp[index];
	}

	int ret = INT_MIN;

public:
	int maxProduct(vector<int>& nums) {

		for (int i = 0; i < nums.size(); i++)
		{
			dfs(i, 1, nums);
		}

		return ret;
	}
};

