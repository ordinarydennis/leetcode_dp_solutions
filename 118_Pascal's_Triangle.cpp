class Solution {
public:
	vector<vector<int>> generate(int numRows) {

		vector<vector<int>> ret(numRows);

		ret[0] = { 1 };

		for (int i = 1; i < numRows; i++)
		{
			for (int r = 0; r <= i; r++)
			{
				if (0 == r)
				{
					ret[i].push_back(ret[i - 1][r]);
				}
				else if (i == r)
				{
					ret[i].push_back(ret[i - 1][r - 1]);
				}
				else
				{
					ret[i].push_back(ret[i - 1][r - 1] + ret[i - 1][r]);
				}
			}
		}

		return ret;
	}
};
