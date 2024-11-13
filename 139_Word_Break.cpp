class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {

		std::unordered_map<char, vector<string>> m;

		for (string& str : wordDict)
		{
			m[str[0]].push_back(str);
		}


		for (auto& [_, list] : m)
		{
			sort(list.begin(), list.end());
		}
		int i = 0;

		for (;i < s.size();)
		{
			auto it = m.find(s[i]);

			if (m.end() == it)
			{
				return false;
			}

			auto& list = it->second;

			for (auto& str : list)
			{
				if (s.size() < i + str.size())
				{
					continue;
				}

				auto sub = s.substr(i, str.size());

				if (sub == str)
				{
					i += str.size();
					break;
				}
			}
		}

		return s.size() <= i;
	}
};


class Solution {
public:
	vector<int> memo;
	vector<string> wordDict;
	string s;

	bool wordBreak(string s, vector<string>& wordDict) {
		memo = vector(s.length(), -1);
		this->wordDict = wordDict;
		this->s = s;
		return dp(0);
	}

	bool dp(int i)
	{
		if (s.size() <= i)
			return true;

		if (memo[i] != -1) {
			return memo[i] == 1;
		}

		for (string word : wordDict)
		{
			int currSize = word.length();

			if (s.size() < i + currSize) {
				continue;
			}

			if (s.substr(i, currSize) == word &&
				dp(i + currSize)) {
				memo[i] = 1;
				return true;
			}
		}

		memo[i] = 0;
		return false;
	}
};

