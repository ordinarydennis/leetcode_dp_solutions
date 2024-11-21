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



class Solution {

	int dfs(int index, vector<int>& nums)
	{
		if (nums.size() - 1 == index)
		{
			result = nums[index];
			return nums[index];
		}
		
		int ret = dfs(index + 1, nums);

		if (ret <= nums[index] * ret)
		{
			result = nums[index] * ret;
			return nums[index] * ret;
		}
		else
		{
			return 1;
		}

		return 1;
	}

	int result = INT_MIN;

public:
	int maxProduct(vector<int>& nums) {

		dfs(0, nums);

		return result;
	}
};

class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int max_so_far = nums[0];
		int min_so_far = nums[0];
		int ret = nums[0];

		for (int i = 1; i < nums.size(); i++)
		{
			int cur = nums[i];
			
			int temp = std::max(cur,
				std::max(max_so_far * cur, min_so_far * cur)
			);

			min_so_far = std::min(cur,
				std::min(max_so_far * cur, min_so_far * cur)
			);

			max_so_far = temp;

			ret = max(ret, max_so_far);
		}

		return ret;

	}
};