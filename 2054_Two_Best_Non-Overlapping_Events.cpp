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

class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		sort(events.begin(), events.end());
		vector<vector<int>> dp(events.size(), vector<int>(3, -1));
		return findEvents(events, 0, 0, dp);
	}
	// Recursive function to find the greatest sum for the pairs.
	int findEvents(vector<vector<int>>& events, int idx, int cnt,
		vector<vector<int>>& dp)
	{
		if (cnt == 2 || idx >= events.size())
			return 0;
		if (dp[idx][cnt] == -1)
		{
			int end = events[idx][1];
			int lo = idx + 1, hi = events.size() - 1;
			while (lo < hi)
			{
				int mid = lo + ((hi - lo) >> 1);
				if (events[mid][0] > end)
					hi = mid;
				else
					lo = mid + 1;
			}
			int include =
				events[idx][2] + (lo < events.size() && events[lo][0] > end
					? findEvents(events, lo, cnt + 1, dp)
					: 0);
			int exclude = findEvents(events, idx + 1, cnt, dp);
			dp[idx][cnt] = max(include, exclude);
		}
		return dp[idx][cnt];
	}
};

class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {
		vector<array<int, 3>> times;
		for (auto& e : events) {
			// 1 denotes start time.
			times.push_back({ e[0], 1, e[2] });
			// 0 denotes end time.
			times.push_back({ e[1] + 1, 0, e[2] });
		}
		int ans = 0, maxValue = 0;
		sort(begin(times), end(times));
		for (auto& timeValue : times) {
			// If current time is a start time, find maximum sum of maximum end
			// time till now.
			if (timeValue[1]) {
				ans = max(ans, timeValue[2] + maxValue);
			}
			else {
				maxValue = max(maxValue, timeValue[2]);
			}
		}
		return ans;
	}
};


class Solution {
public:
	int maxTwoEvents(vector<vector<int>>& events) {

		std::priority_queue < std::pair<int, int>,
			vector<std::pair<int, int>>,
			std::greater<std::pair<int, int>>
		> pq;


		std::sort(events.begin(), events.end());

		int ret = INT_MIN;
		int max = 0;

		for (auto& e : events)
		{
			while (pq.size() && pq.top().first < e[0])
			{
				max = std::max(max, pq.top().second);
				pq.pop();
			}

			pq.push({ e[1], e[2] });

			ret = std::max(ret, max + e[2]);
		}

		return ret;
	}
};