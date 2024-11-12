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

	bool dfs(int i, string& s, std::unordered_map<char, vector<string>>& m)
	{
		auto it = m.find(s[i]);
		if (m.end() == it)
		{
			return false;
		}

		if (s.size() <= i)
		{
			return true;
		}

		for (auto& str : it->second)
		{
			auto sub = s.substr(i, str.size());

			if (sub == str)
			{
				if (s.size() == i + str.size())
				{
					return true;
				}

				if (dfs(i + s.size(), s, m))
				{
					return true;
				}
			}

		}
		
		return false;
	}


public:
	bool wordBreak(string s, vector<string>& wordDict) {

		std::unordered_map<char, vector<string>> m;

		for (string& str : wordDict)
		{
			m[str[0]].push_back(str);
		}

		return dfs(0, s, m);
	}
};
