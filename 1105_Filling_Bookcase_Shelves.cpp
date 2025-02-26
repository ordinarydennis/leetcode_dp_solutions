class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {

		int len = books.size();
		int ret = 0;

		int shelfWidth2 = shelfWidth;

		int maxH = 0;

		for (int i = len - 1; 0 <= i; i--)
		{
			int w = books[i][0];
			int h = books[i][1];

			if (0 <= shelfWidth2 - w)
			{
				maxH = std::max(maxH, h);
				shelfWidth2 -= w;
			}
			else
			{
				ret += maxH;

				shelfWidth2 = shelfWidth;
				
				maxH = 0;

				i++;
			}
		}

		ret += maxH;

		return ret;
	}
};