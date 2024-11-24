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


//Brute force TLE
class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int ret = INT_MIN;

		for (int i = 0; i < nums.size(); i++)
		{
			int pro = 1;

			for (int a = i; a < nums.size(); a++)
			{
				pro *= nums[a];
				ret = max(ret, pro);
			}
		}

		return ret;
	}
};


class Solution {
public:
	int maxProduct(vector<int>& nums) {

		int min_so_far = nums[0];
		int max_so_far = nums[0];
	
		int ret = max_so_far;

		for (int i = 1; i < nums.size(); i++)
		{
			int temp = max(
				nums[i],
				max(
					nums[i] * max_so_far,
					nums[i] * min_so_far
				)
			);

			min_so_far = min(
				nums[i],
				min(
					min_so_far * nums[i],
					max_so_far * nums[i]
				)
			);

			max_so_far = temp;
			
			ret = max(ret, max_so_far);
		}

		return ret;
	}
};

//single negative number
//from first to before negative number or from after negative number to last number.

//two negative number 
//product of all numbers

//no negative numbers
//product of all numbers