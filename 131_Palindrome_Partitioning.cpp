
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