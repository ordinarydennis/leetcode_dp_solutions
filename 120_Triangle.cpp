class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int maxY = triangle.size();

		vector<vector<int>> triangleSum(maxY);

		triangleSum[0].push_back(triangle[0][0]);

		for (int y = 1; y < maxY; y++)
		{
			int maxX = triangle[y].size();

			for(int x = 0; x < maxX; x++)
			{
				if (0 == x)
				{
					triangleSum[y].push_back(triangleSum[y - 1][x] + triangle[y][x]);
				}
				else if (maxX - 1 == x)
				{
					triangleSum[y].push_back(triangleSum[y - 1][x - 1] + triangle[y][x]);
				}
				else
				{
					int m = std::min(triangleSum[y - 1][x - 1], triangleSum[y - 1][x]);

					triangleSum[y].push_back(m + triangle[y][x]);
				}
			}
		}

		int ret = INT_MAX;

		for (int x = 0; x < triangleSum[maxY - 1].size(); x++)
		{
			ret = std::min(ret, triangleSum[maxY - 1][x]);
		}

		return ret;
	}
};


class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {

		int maxY = triangle.size();

		vector<vector<int>> totalSum(maxY);

		totalSum[0].push_back(triangle[0][0]);

		for (int y = 1; y < maxY; y++)
		{
			int maxX = triangle[y].size();

			for (int x = 0; x < maxX; x++)
			{
				int n = 0;

				if (0 == x)
				{
					n = totalSum[y - 1][x];
				}
				else if (maxX - 1 == x)
				{
					n = totalSum[y - 1][x - 1];
				}
				else
				{
					n = std::min(totalSum[y - 1][x], totalSum[y - 1][x - 1]);
				}

				totalSum[y].push_back(n + triangle[y][x]);
			}
		}

		int ret = INT_MAX;


		for(int x = 0; x < triangle[maxY - 1].size(); x++)
		{
			ret = std::min(totalSum[maxY - 1][x], ret);
			
		}

		return ret;
	}
};