
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


class Solution {
public:
	int rob(vector<int>& nums) {

		int n1 = nums[nums.size() - 1], n2 = 0;

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			int temp = n1;
			n1 = max(n1, nums[i] + n2);
			n2 = temp;
		}

		return n1;
	}
};