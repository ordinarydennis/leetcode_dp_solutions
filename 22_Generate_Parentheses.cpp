class Solution {


	void dfs(int comCount, int openCount, int closeCount, string& str, vector<string>& ret)
	{
		if (0 == openCount && 0 == closeCount)
		{
			ret.push_back(str);
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			if (i == 0 )
			{
				if (openCount)
				{
					str.push_back('(');
					dfs(comCount + 1, openCount - 1, closeCount, str, ret);
					str.pop_back();
				}
			}
			else if (closeCount)
			{
				if (comCount)
				{
					str.push_back(')');
					dfs(comCount - 1, openCount, closeCount - 1, str, ret);
					str.pop_back();
				}

			}
		}
	}


public:
	vector<string> generateParenthesis(int n) {

		vector<string> ret;

		string str;

		dfs(0, n, n, str, ret);

		return ret;
	}
};

class Solution {
private:
	bool isValid(std::string pString) {
		int leftCount = 0;
		for (char p : pString) {
			if (p == '(') {
				leftCount++;
			}
			else {
				leftCount--;
			}
			if (leftCount < 0) {
				return false;
			}
		}
		return leftCount == 0;
	}

public:
	std::vector<std::string> generateParenthesis(int n) {
		std::vector<std::string> answer;
		std::queue<std::string> queue;
		queue.push("");
		while (!queue.empty()) {
			std::string curString = queue.front();
			queue.pop();
			if (curString.length() == 2 * n) {
				if (isValid(curString)) {
					answer.push_back(curString);
				}
				continue;
			}
			queue.push(curString + ")");
			queue.push(curString + "(");
		}
		return answer;
	}
};


class Solution {

	void dfs(int openLeftCount, int closeLeftCount, string& str, vector<string>& ret)
	{
		if (0 == openLeftCount && 0 == closeLeftCount)
		{
			ret.push_back(str);
			return;
		}

		if (openLeftCount)
		{
			str.push_back('(');
			dfs(openLeftCount - 1, closeLeftCount, str, ret);
			str.pop_back();
		}
		
		if (openLeftCount < closeLeftCount)
		{
			str.push_back(')');
			dfs(openLeftCount, closeLeftCount - 1, str, ret);
			str.pop_back();
		}
	}


public:
	vector<string> generateParenthesis(int n) {

		vector<string> ret;
		
		string str;
		
		dfs(n, n, str, ret);

		return ret;
	}
};