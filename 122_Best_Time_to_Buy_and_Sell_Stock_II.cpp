class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int maxY = triangle.size();

		vector<vector<int>> triangleSum(maxY);

		triangleSum[0].push_back(triangle[0][0]);

		for (int y = 1; y < maxY; y++)
		{
			int maxX = triangle[y].size();

			for(int x = 0; x < maxX; x++)
			{
				if (0 == x)
				{
					triangleSum[y].push_back(triangleSum[y - 1][x] + triangle[y][x]);
				}
				else if (maxX - 1 == x)
				{
					triangleSum[y].push_back(triangleSum[y - 1][x - 1] + triangle[y][x]);
				}
				else
				{
					int m = std::min(triangleSum[y - 1][x - 1], triangleSum[y - 1][x]);

					triangleSum[y].push_back(m + triangle[y][x]);
				}
			}
		}

		int ret = INT_MAX;

		for (int x = 0; x < triangleSum[maxY - 1].size(); x++)
		{
			ret = std::min(ret, triangleSum[maxY - 1][x]);
		}

		return ret;
	}
};


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int maxY = triangle.size();

		vector<vector<int>> totalSum(maxY);

		totalSum[0].push_back(triangle[0][0]);

		for (int y = 1; y < maxY; y++)
		{
			int maxX = triangle[y].size();

			for (int x = 0; x < maxX; x++)
			{
				int n = 0;

				if (0 == x)
				{
					n = totalSum[y - 1][x];
				}
				else if (maxX - 1 == x)
				{
					n = totalSum[y - 1][x - 1];
				}
				else
				{
					n = std::min(totalSum[y - 1][x], totalSum[y - 1][x - 1]);
				}

				totalSum[y].push_back(n + triangle[y][x]);
			}
		}

		int ret = INT_MAX;


		for(int x = 0; x < triangle[maxY - 1].size(); x++)
		{
			ret = std::min(totalSum[maxY - 1][x], ret);
			
		}

		return ret;
	}
};

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
			
			for (int i = start + 1; i < prices.size(); i++) {
				if (prices[start] < prices[i]) {
					int profit =
						calculate(prices, i + 1) + prices[i] - prices[start];
					if (profit > maxprofit) maxprofit = profit;
				}
			}
			if (maxprofit > max) max = maxprofit;
		}
		return max;
	}
};

//Approach 2: Peak Valley Approach
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int i = 0;
		int valley = prices[0];
		int peak = prices[0];
		int maxprofit = 0;

		while (i < prices.size() - 1)
		{
			while (i < prices.size() - 1 && prices[i] >= prices[i + 1]) i++;

			valley = prices[i];

			while (i < prices.size() - 1 && prices[i] <= prices[i + 1]) i++;

			peak = prices[i];

			maxprofit += peak - valley;
		}
		return maxprofit;
	}
};

/*
이 코드에서 valley를 먼저 구하고 peak을 구해야 하는 이유는 이익을 올리기 위해 주식을 저가에 매수하고 고가에 매도해야 하기 때문입니다. 
만약 peak을 먼저 구하고 valley를 나중에 구한다면, 주식을 고가에 매수한 후 더 낮은 가격에 매도하는 상황이 발생할 수 있어 이익을 제대로 계산하지 못합니다
*/

//Approach 3: Simple One Pass
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxprofit = 0;
		for (int i = 1; i < prices.size(); i++) {
			if (prices[i] > prices[i - 1])
				maxprofit += prices[i] - prices[i - 1];
		}
		return maxprofit;
	}
};

//also 

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int maxprofit = 0;
		for (int i = 0; i < prices.size() - 1; i++) {
			if (prices[i] < prices[i + 1])
				maxprofit += prices[i + 1] - prices[i];
		}
		return maxprofit;
	}
};

//결국 낮은 가격에 사서 비싼 가격에 파는 로직을 짜야한다.