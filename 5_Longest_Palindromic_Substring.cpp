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

		vector<vector<int>> dp(s.size(), vector<int>(s.size()));


		string ret;

		int max = INT_MIN;

		for (int i = 0; i < s.size(); i++)
		{
			dp[i][i] = 1;

			ret = s.substr(i, 1);
			
			max = 1;

			if (i < s.size() - 1)
			{
				if (s[i] == s[i + 1])
				{
					dp[i][i + 1] = 2;
					ret = s.substr(i, 2);
					max = 2;
				}
			}
		}


		for (int si = 0; si < s.size(); si++)
		{
			for (int ei = si + 2; ei < s.size(); ei++)
			{
				if (s[si] == s[ei] && s[si + 1] == s[ei - 1])
				{
					dp[si][ei] = dp[si + 1][ei - 1] + 1;

					if (max < ei - si + 1)
					{
						max = ei - si + 1;
						ret = s.substr(si, ei - si + 1);
					}
				}
				
			}
		}

		return ret;
	}
};