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
		// Create a min-heap to store the ending time with value.
		priority_queue<pair<int, int>, vector<pair<int, int>>,
			greater<pair<int, int>>>
			pq;
		sort(events.begin(), events.end());

		int maxVal = 0, maxSum = 0;

		for (auto& event : events) {
			// Pop all valid events from queue and take their maximum.
			while (pq.size() && pq.top().first < event[0]) {
				maxVal = max(maxVal, pq.top().second);
				pq.pop();
			}

			maxSum = max(maxSum, maxVal + event[2]);
			pq.push({ event[1], event[2] });
		}

		return maxSum;
	}
};