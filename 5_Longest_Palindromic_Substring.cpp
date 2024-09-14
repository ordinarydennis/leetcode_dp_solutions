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