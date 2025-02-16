class Solution {


	bool isPalindrome(string& str, int left, int right)
	{
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

public:
	string longestPalindrome(string str) {

		if (isPalindrome(str, 0, str.size() - 1))
		{
			return str;
		}

		int length = 0;
		int index = 0;

		for (int s = 0; s < str.size(); s++)
		{
			for (int l = 0; s + l < str.size(); l++)
			{
				if (isPalindrome(str, s, s + l))
				{
					if (length < l + 1)
					{
						length = max(length, l + 1);
						index = s;
					}
					
				}
			}
		}

		return str.substr(index, length);
	}
};

class Solution {
public:
	string longestPalindrome(string s) {

		vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));

		pair<int, int> pos = { 0, 0 };

		for (int i = 0; i < s.size(); i++)
		{
			dp[i][i] = true;

			if (i < s.size() - 1)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = true;

					pos.first = i;
					pos.second = i + 1;
				}
			}
		}


		for (int si = 0; si < s.size(); si++)
		{
			for (int ei = si + 2; ei < s.size(); ei++)
			{
				if (s[si] == s[ei] && s[si + 1] == s[ei - 1])
				{
					dp[si][ei] = true;

					if (pos.second - pos.first < ei - si)
					{
						pos.first = si;
						pos.second = ei;
					}
				}
				
			}
		}

		return s.substr(pos.first, pos.second - pos.first + 1);
	}
};


class Solution {
public:
	string longestPalindrome(string s) {

		vector<vector<int>> dp(s.size(), vector<int>(s.size()));

		int index = 0;
		int length = 1;

		for (int i = 0; i < s.size(); i++)
		{
			dp[i][i] = true;

			if (i + 1 < s.size() && s[i] == s[i + 1])
			{
				dp[i][i + 1] = true;
				index = i;
				length = 2;
			}
		}

		for (int l = 3; l <= s.size(); l++)
		{
			for (int i = 0; i <= s.size() - l; i++)
			{
				int e = i + l - 1;
				if (s[i] == s[e] && dp[i + 1][e - 1])
				{
					dp[i][e] = true;
					index = i;
					length = l;
				}
			}
		}

		return s.substr(index, length);
	}
};

class Solution {

	bool isPalindrome(string& s)
	{
		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			if (s[left] != s[right])
			{
				return false;
			}

			left++;
			right--;
		}

		return true;
	}


public:
	string longestPalindrome(string s) {

		string ret;
		for (int i = 0; i < s.size(); i++)
		{
			for (int sz = 1; sz <= s.size(); sz++)
			{
				string sub = s.substr(i, sz);
				if (isPalindrome(sub) && ret.size() < sub.size())
				{
					ret = sub;
				}
			}
		}

		return ret;
	}
};



class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		vector<vector<bool>> dp(n, vector<bool>(n));
		array<int, 2> ans = { 0, 0 };

		for (int i = 0; i < n; ++i) {
			dp[i][i] = true;
		}

		for (int i = 0; i < n - 1; ++i) {
			if (s[i] == s[i + 1]) {
				dp[i][i + 1] = true;
				ans = { i, i + 1 };
			}
		}

		for (int diff = 2; diff < n; ++diff) {
			for (int i = 0; i < n - diff; ++i) {
				int j = i + diff;
				if (s[i] == s[j] && dp[i + 1][j - 1]) {
					dp[i][j] = true;
					ans = { i, j };
				}
			}
		}

		int i = ans[0];
		int j = ans[1];
		return s.substr(i, j - i + 1);
	}
};

class Solution {
public:
	string longestPalindrome(string s) {

		vector<vector<int>> dp(s.size(), vector<int>(s.size()));

		int max = 1;
		int begin = 0;

		for (int a = 0; a < s.size(); a++)
		{
			dp[a][a] = 1;

			if (a < s.size() - 1 && s[a] == s[a + 1])
			{
				dp[a][a + 1] = 2;
				max = 2;
				begin = a;
			}
		}

		for (int size = 3; size <= s.size(); size++)
		{
			for (int i = 0; i <= s.size() - size; i++)
			{
				if (s[i] == s[i + size - 1] && 1 <= dp[i + 1][i + size - 2])
				{
					dp[i][i + size - 1] = dp[i + 1][i + size - 2] + 2;
					max = size;
					begin = i;
				}	
			}
		}

		return s.substr(begin, max);
	}
};


