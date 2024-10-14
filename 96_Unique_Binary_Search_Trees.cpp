class Solution {

	void dfs(int index, int n, int& count)
	{
		if (index < 0 || n < index)
		{
			return;
		}

		count++;

		if (n == count)
		{
			ret++;
			return;
		}

		int mid = index / 2;
		int mid2 = (index + n) / 2;

		dfs(mid - 1, n, count);

		dfs(mid2 + 1, n, count);
	}

	int ret = 0;

public:
	int numTrees(int n) {

		int count = 1;

		for (int i = 1; i <= n; i++)
		{
			dfs(i, n, count);
		}

		return ret;
	}

};