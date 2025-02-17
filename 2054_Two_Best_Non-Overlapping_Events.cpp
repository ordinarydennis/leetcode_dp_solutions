class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {

		std::sort(events.begin(), events.end());

		int ret = INT_MIN;

		for (int i = 0; i < events.size(); i++)
		{
			int start = events[i][0];
			int end = events[i][1];
			int value = events[i][2];
			
			int max = value;

			for (int a = i + 1; a < events.size(); a++)
			{
				if (end < events[a][0])
				{
					max = std::max(max, value + events[a][2]);
				}
			}

			ret = std::max(ret, max);
		}

		return ret;
	}
};
