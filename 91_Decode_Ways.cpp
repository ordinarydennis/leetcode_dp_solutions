class Solution {

	void dfs(int index, string& s)
	{
		if (s.size() <= index)
		{
			ret++;
			return;
		}

		for (int i = 1; i <= 2; i++)
		{
			if (s.size() < index + i)
			{
				return;
			}

			string sub = s.substr(index, i);

			if ('0' == sub[0])
			{
				continue;
			}

			if (stoi(sub) <= 26)
			{
				dfs(index + i, s);
			}
		}
	}

	int ret = 0;

public:
	int numDecodings(string s) {

		dfs(0, s);

		return ret;
	}
};


class Solution {

	int dfs(int index, string& s)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (s.size() == index)
		{
			return 1;
		}

		int count = 0;

		for (int i = 1; i <= 2; i++)
		{
			if (s.size() < index + i)
			{
				break;
			}

			auto str = s.substr(index, i);

			if ('0' == str[0])
			{
				break;
			}

			int n = stoi(str);

			if (n <= 26)
			{
				count += dfs(index + i, s);
			}
		}

		memo[index] = count;

		return memo[index];
	}


	unordered_map<int, int> memo;

public:
	int numDecodings(string s) {

		return dfs(0, s);

	}
};


class Solution {
public:
	int numDecodings(string s) {

		vector<int> dp(s.size() + 1);

		dp[0] = 1;

		for (int i = 1; i < dp.size(); i++)
		{
			if ('0' != s[i - 1])
			{
				dp[i] = dp[i - 1];
			}
			
			if (0 <= i - 2)
			{
				auto sub = s.substr(i - 2, 2);

				auto n = stoi(sub);
				if (10 <= n && n <= 26)
				{
					dp[i] += dp[i - 2];
				}
			}

		}

		return dp[s.size()];
	}
};



class Solution {
public:
	int numDecodings(string s) {

		vector<int> dp(s.size() + 1);

		int n1 = 1;

		int n2 = '0' != s[0];

		for (int i = 1; i < dp.size(); i++)
		{
			int cur = 0;

			if ('0' != s[i - 1])
			{
				cur = n2;
			}

			if (0 <= i - 2)
			{
				auto sub = s.substr(i - 2, 2);
				auto n = stoi(sub);
				if (10 <= n && n <= 26)
				{
					cur += n1;
				}
			}

			n1 = n2;
			n2 = cur;
		}

		return n2;
	}
};