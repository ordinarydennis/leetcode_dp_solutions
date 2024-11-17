
//Approach 1: Backtracking
class Solution {

	bool isPalindrome(string& str)
	{
		int left = 0;
		int right = str.size() - 1;

		while (left < right)
		{
			if (str[left] == str[right])
			{
				left++;
				right--;
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	void dfs(int index, string& s, vector<string>& list)
	{
		if (s.size() <= index)
		{
			ret.push_back(list);
			return;
		}

		for (int l = 1; index + l <= s.size(); l++)
		{
			string sub = s.substr(index, l);

			if (isPalindrome(sub))
			{
				list.push_back(sub);
				dfs(index + l, s, list);
				list.pop_back();
			}
		}
	}

	vector<vector<string>> ret;

public:
	vector<vector<string>> partition(string s) {

		vector<string> list;

		dfs(0, s, list);

		return ret;
	}
};


class Solution {


	void dfs(int index, string s, vector<string>& subStrList, vector<vector<bool>>& dp)
	{
		if (s.size() <= index)
		{
			ret.push_back(subStrList);
			return;
		}

		for (int i = index; i < s.size(); i++)
		{
			if (index == i)
			{
				dp[index][i] = true;
			}
			else
			{
				if (s[index] == s[i])
				{
					if (i - index < 2 || dp[index + 1][i - 1])
					{
						dp[index][i] = true;
					}
				}
			}

			if (dp[index][i])
			{
			
				subStrList.push_back(s.substr(index, i - index + 1));

				dfs(i + 1, s, subStrList, dp);

				subStrList.pop_back();
			}

		}

	}

	vector<vector<string>> ret;

public:
	vector<vector<string>> partition(string s) {


		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

		vector<string> subStrList;

		dfs(0, s, subStrList, dp);

		return ret;
	}
};


//fail
class Solution {

	void dfs(int start, string& s, vector<string>& list, vector<vector<bool>>& dp)
	{
		if (s.size() <= start)
		{
			ret.push_back(list);
			return;
		}


		for (int l = 1; l <= s.size(); l++)
		{
			if (1 == l)
			{
				dp[start][start] = true;
			}
			else if (2 == l && s[start] == s[start + 1])
			{
				dp[start][start + 1] = true;
			}
			else if (s[start] == s[start + l - 1] && dp[start + 1][start + l - 2])
			{
				dp[start][start + l - 1] = true;
			}
			else
			{
				continue;
			}

			list.emplace_back(std::move(s.substr(start, l)));

			dfs(start + l, s, list, dp);

			list.pop_back();
		}
	}

	vector<vector<string>> ret;

public:
	vector<vector<string>> partition(string s) {

		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

		vector<string> list;

		dfs(0, s, list, dp);

		return ret;
	}

};

class Solution {

	void dfs(int index, string& s, vector<string>& list, vector<vector<bool>>& dp)
	{
		if (s.size() <= index)
		{
			ret.push_back(list);
			return;
		}

		for (int i = index; i < s.size(); i++)
		{
			if (s[index] == s[i])
			{
				if (i - index <= 2 || dp[index + 1][i - 1])
				{
					dp[index][i] = true;

					list.emplace_back(s.substr(index, i - index + 1));

					dfs(i + 1, s, list, dp);

					list.pop_back();
				}
			}
		}
	}

	vector<vector<string>> ret;

public:
	vector<vector<string>> partition(string s) {

		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

		vector<string> list;

		dfs(0, s, list, dp);

		return ret;
	}
};