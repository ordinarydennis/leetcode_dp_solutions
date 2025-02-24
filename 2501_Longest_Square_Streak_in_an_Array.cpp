class Solution {


	void dfs(int index, vector<int>& nums, vector<int> arr)
	{
		if (nums.size() <= index)
		{
			if (arr.size() < 2)
				return;

			sort(arr.begin(), arr.end());

			for (int n : arr)
			{
				cout << n << " ";
			}
			cout << endl;

			int n = arr[0];
			for (int i = 1; i < arr.size(); i++)
			{
				if (n * n != arr[i])
				{
					return;
				}

				n = arr[i];
			}

			ret = std::max(ret, static_cast<int>(arr.size()));
			return;
		}

		for (int i = index + 1; i < nums.size(); i++)
		{
			if (0 == nums[i] % nums[index] || 0 == nums[index] / nums[i])
			{
				arr.push_back(nums[i]);
				dfs(i, nums, arr);
				arr.pop_back();
			}
		}
	}

	int ret = 0;

public:
	int longestSquareStreak(vector<int>& nums) {

		vector<int> arr;

		arr.push_back(nums[0]);

		dfs(0, nums, arr);

		return ret;
	}
};