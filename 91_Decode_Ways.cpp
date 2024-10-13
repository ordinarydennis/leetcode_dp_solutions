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