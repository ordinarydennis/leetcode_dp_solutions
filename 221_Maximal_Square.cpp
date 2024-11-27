
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