
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