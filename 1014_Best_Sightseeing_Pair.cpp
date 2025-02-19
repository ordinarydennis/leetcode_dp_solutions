//time limit exceeded
class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {

		int ret = INT_MIN;

		for (int a = 0; a < values.size(); a++)
		{
			for (int b = a + 1; b < values.size(); b++)
			{
				ret = std::max(ret, values[a] + values[b] - (b - a));	
			}
		}

		return ret;
	}
};

//fail
class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& values) {

		int ret = INT_MIN;

		vector<vector<int>> dp(values.size(), vector<int>(2, 0));

		dp[0][0] = values[0];
		dp[0][1] = 0;

		int max = INT_MIN;
		for (int i = 1; i < values.size(); i++)
		{
			if (dp[i - 1][0] <= values[i])
			{
				dp[i][0] = values[i];
				dp[i][1] = i;
			}
			else
			{
				dp[i][0] = dp[i - 1][0];
				dp[i][1] = dp[i - 1][1];
			}

			max = std::max(max, dp[i - 1][0] + values[i] + (dp[i - 1][1] - i));
		}

		return max;
	}
};
