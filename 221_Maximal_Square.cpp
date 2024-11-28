
//brute force tle
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {

		int maxY = matrix.size();
		int maxX = matrix[0].size();

		int maxLen = 0;

		for (int y = 0; y < maxY; y++)
		{
			for (int x = 0; x < maxX; x++)
			{
				if ('1' != matrix[y][x])
					continue;

				if (0 == maxLen)
				{
					maxLen = 1;
				}

				int len = 1;

				bool isSquare = true;

				while (x + len < maxX && y + len < maxY && isSquare)
				{
					for (int i = x; i <= x + len; i++)
					{
						if ('1' != matrix[y + len][i])
						{
							isSquare = false;
							break;
						}
					}

					for (int i = y; i <= y + len; i++)
					{
						if ('1' != matrix[i][x + len])
						{
							isSquare = false;
							break;
						}
					}

					if (isSquare)
					{
						len++;
					}
				}

				maxLen = std::max(maxLen, len);

			}
		}

		return maxLen * maxLen;
	}
};

//dp
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
		vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
		int maxsqlen = 0;
		// for convenience, we add an extra all zero column and row
		// outside of the actual dp table, to simpify the transition
		for (int i = 1; i <= rows; i++)
		{
			for (int j = 1; j <= cols; j++)
			{
				if (matrix[i - 1][j - 1] == '1') 
				{
					dp[i][j] =
						min(
							min(dp[i][j - 1], dp[i - 1][j]), 
							dp[i - 1][j - 1]
						) +
						1;
					maxsqlen = max(maxsqlen, dp[i][j]);
				}
			}
		}
		return maxsqlen * maxsqlen;
	}
};