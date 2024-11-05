
class Solution {
public:
	int maxProfit(vector<int>& prices) {


	}
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/editorial/?envType=problem-list-v2&envId=dynamic-programming&difficulty=MEDIUM%2CEASY
class Solution {
public:
	int maxProfit(vector<int>& prices) { return calculate(prices, 0); }

private:
	int calculate(vector<int>& prices, int s) {
		if (s >= prices.size()) return 0;

		int max = 0;

		for (int start = s; start < prices.size(); start++) {

			int maxprofit = 0;

			for (int i = start + 1; i < prices.size(); i++)
			{
				if (prices[start] < prices[i])
				{
					int profit = calculate(prices, i + 1) + prices[i] - prices[start];
					if (profit > maxprofit) maxprofit = profit;
				}
			}
			if (maxprofit > max) max = maxprofit;
		}
		return max;
	}
};



class Solution {

	int dfs(int s, vector<int>& prices)
	{
		if (prices.size() <= s)
		{
			return 0;
		}

		int max = 0;

		for (int start = s; start < prices.size(); start++)
		{
			int maxprofit = 0;

			for (int i = start + 1; i < prices.size(); i++)
			{
				if (prices[start] < prices[i])
				{
					int profit = dfs(i + 1, prices) + prices[i] - prices[start];
					maxprofit = std::max(maxprofit, profit);
				}
			}

			if (maxprofit > max) max = maxprofit;
		}

		return max;
	}

public:
	int maxProfit(vector<int>& prices)
	{
		return dfs(0, prices);
	}
};


class Solution {

	int dfs(int buy, vector<int>& prices)
	{
		int ret = 0;

		for (int b = buy; b < prices.size(); b++)
		{
			int max = 0;

			for (int s = b + 1; s < prices.size(); s++)
			{
				if (prices[b] < prices[s])
				{
					int profit = dfs(s + 1, prices) + prices[s] - prices[b];
					max = std::max(max, profit);
				}
			}

			ret = std::max(max, ret);
		}

		return ret;
	}


public:
	int maxProfit(vector<int>& prices) {

		return dfs(0, prices);

	}
};
