class Solution {
public:
	int rob(vector<int>& nums) {

		if (2 == nums.size())
		{
			return max(nums[0], nums[1]);
		}

		if (3 == nums.size())
		{
			return max(
				nums[0],
				max(
					nums[1],
					nums[2]
					)
			);
		}

		int len = nums.size();

		int n1 = nums[len - 1];
		int n2 = nums[0];

		for (int i = len - 1; 1 <= i; i--)
		{
			int temp = n1;

			n1 = max(
				nums[i] + n2,
				n1
			);

			n2 = temp;
		}

		return n1;

	}
};
