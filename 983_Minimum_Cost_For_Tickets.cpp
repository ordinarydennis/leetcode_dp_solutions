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


class Solution {
public:
    unordered_set<int> isTravelNeeded;

    int solve(vector<int>& dp, vector<int>& days, vector<int>& costs, int currDay) {
        // If we have iterated over travel days, return 0.
        if (currDay > days[days.size() - 1]) {
            return 0;
        }

        // If we don't need to travel on this day, move on to next day.
        if (isTravelNeeded.find(currDay) == isTravelNeeded.end()) {
            return solve(dp, days, costs, currDay + 1);
        }

        // If already calculated, return from here with the stored answer.
        if (dp[currDay] != -1) {
            return dp[currDay];
        }

        int oneDay = costs[0] + solve(dp, days, costs, currDay + 1);
        int sevenDay = costs[1] + solve(dp, days, costs, currDay + 7);
        int thirtyDay = costs[2] + solve(dp, days, costs, currDay + 30);

        // Store the cost with the minimum of the three options.
        return dp[currDay] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // The last day on which we need to travel.
        int lastDay = days[days.size() - 1];
        vector<int> dp(lastDay + 1, -1);

        // Mark the days on which we need to travel.
        for (int day : days) {
            isTravelNeeded.insert(day);
        }

        return solve(dp, days, costs, 1);
    }
};

//exceeded time limit
class Solution {

	void dfs(int index, int pass, int sum, vector<int>& days, vector<int>& costs)
	{
		if (days.size() <= index)
		{
			ret = std::min(ret, sum);
			return;
		}

		int day = days[index];

		if (days[index] < pass)
		{
			dfs(index + 1, pass, sum, days, costs);
		}
		else
		{
			dfs(index + 1, days[index] + 1, sum + costs[0], days, costs);
			dfs(index + 1, days[index] + 7, sum + costs[1], days, costs);
			dfs(index + 1, days[index] + 30, sum + costs[2], days, costs);
		}
	}

	int ret = INT_MAX;


public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {

		dfs(0, 0, 0, days, costs);

		return ret;
	}
};

class Solution {

    int dfs(int curDay, vector<int>& days, vector<int>& costs)
    {
        if (days[days.size() - 1] < curDay)
        {
            return 0;
        }
        if (travelDays.find(curDay) == travelDays.end())
        {
            return dfs(curDay + 1, days, costs);
        }

        if (dp.end() != dp.find(curDay))
        {
            return dp[curDay];
        }

        int a = costs[0] + dfs(curDay + 1, days, costs);
        int b = costs[1] + dfs(curDay + 7, days, costs);
        int c = costs[2] + dfs(curDay + 30, days, costs);

        return dp[curDay] = std::min(std::min(a, b), c);
    }

    unordered_map<int, int> dp;
    unordered_set<int> travelDays;

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {


        for (int n : days)
        {
            travelDays.insert(n);
        }

        return dfs(0, days, costs);

    }
};