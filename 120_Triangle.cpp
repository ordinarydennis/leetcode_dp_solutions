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
					triangleSum[y].push_back(triangleSum[y - 1][x - 1] + triangleSum[y - 1][x] + triangle[y][x]);
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