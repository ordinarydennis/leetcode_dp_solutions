class Solution {

	void dfs(int index, int n, int k, int c, int d)
	{
		if (n == d)
		{
			ret++;
			return;
		}

		for (int i = 0; i < k; i++)
		{
			int count = (i == index) ? c + 1 : 1;

			if (2 < count)
			{
				continue;
			}

			dfs(i, n, k, count, d + 1);
		}
	}

	int ret = 0;


public:
	int numWays(int n, int k) {

		dfs(-1, n, k, 1, 0);

		return ret;
	}
};


class Solution {
private:
	std::unordered_map<int, int> memo;

	int totalWays(int i, int k) {
		if (i == 1) return k;
		if (i == 2) return k * k;

		// Check if we have already calculated totalWays(i)
		if (memo.find(i) != memo.end()) {
			return memo[i];
		}

		// Use the recurrence relation to calculate totalWays(i)

		//i-번째 기둥이 (i−1)번째 기둥과 같은 색으로 칠해진 경우
		//int sum  = (k - 1) * totalWays(i - 1, k);

		//i-번째 기둥이 (i−1)번째 기둥과 다른 색으로 칠해진 경우, i번쨰와 i-2 번째와는 다른 색이어야 하기 때문에 k-1를 곱해야 한다. 
		//int sum2 = (k - 1) * totalWays(i - 2, k);

		//i - 번째 기둥이(i−1)번째 기둥과 같은 색으로 칠해진 경우, 
		//i - 번째 기둥이(i−1)번째 기둥과 다른 색으로 칠해진 경우를 더해야 함

		memo[i] = (k - 1) * (totalWays(i - 1, k) + totalWays(i - 2, k));
		return memo[i];
	}

public:
	int numWays(int n, int k) {
		return totalWays(n, k);
	}
};