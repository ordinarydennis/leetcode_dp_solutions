class Solution {

	void dfs(int curDay, int pass, int sum, vector<int>& days, vector<int>& costs)
	{
		if (days.size() <= curDay)
		{
			ret = std::min(ret, sum);
			return;
		}

		if (pass < days[curDay])
		{
			//패스권 구매 
			for (int i = 0; i < costs.size(); i++)
			{
				if (i == 0)
				{
					dfs(curDay + 1, days[curDay] + 1, sum + costs[i], days, costs);
				}
				else if (i == 1)
				{
					dfs(curDay + 1, days[curDay] + 7, sum + costs[i], days, costs);
				}
				else
				{
					dfs(curDay + 1, days[curDay] + 30, sum + costs[i], days, costs);
				}
			}
		}
		else
		{
			//구매 x
			dfs(curDay + 1, pass, sum, days, costs);
		}
	}


	int ret = INT_MAX;

public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {

		dfs(0, 0, 0, days, costs);

		return ret;
	}
};
