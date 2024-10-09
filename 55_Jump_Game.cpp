class Solution {

	int dfs(int index, vector<int>& nums)
	{
		if (dp.count(index))
		{
			return dp[index];
		}

		if (nums.size() - 1 <= index)
		{
			return 0;
		}

		if (0 == nums[index])
		{
			return -1;
		}

		int min = INT_MAX;

		for (int i = 1; i <= nums[index]; i++)
		{
			int result = dfs(index + i, nums);

			if (0 <= result)
			{
				min = std::min(min, result);
			}
		}

		return dp[index] = (INT_MAX == min) ? -1 : min + 1;
	}


	unordered_map<int, int> dp;

public:
	int jump(vector<int>& nums) {

		return dfs(0, nums);

	}
};

class Solution {
	
	bool dfs(int index, vector<int>& nums)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (nums.size() <= index)
		{
			return false;
		}

		if (nums.size() - 1 == index)
		{
			return true;
		}

		int jump = nums[index];

		bool result = false;

		for (int i = 1; i <= jump; i++)
		{
			result = dfs(index + i, nums);

			if (result)
			{
				break;
			}
		}

		memo[index] = result;

		return result;
	}

	unordered_map<int, bool> memo;

public:
	bool canJump(vector<int>& nums) {

		return dfs(0, nums);

	}
};

class Solution {
public:
	bool canJump(vector<int>& nums) {

		vector<bool> memo(nums.size());

		memo[nums.size() - 1] = true;

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			int maxdist = std::min(i + nums[i], static_cast<int>(nums.size() - 1));

			for (int d = i + 1; d <= maxdist; d++)
			{
				if (memo[d])
				{
					memo[i] = true;
					break;
				}
			}
		}

		return memo[0];
	}
};


//bfs
class Solution {
public:
	bool canJump(vector<int>& nums) {

		int n = nums.size() - 1;

		vector<bool> dp(nums.size());

		dp[n] = true;

		for (int i = n - 1; 0 <= i; i--)
		{
			int max = std::min(i + nums[i], n);

			for (int d = i + 1; d <= max; d++)
			{
				if (dp[d])
				{
					dp[i] = true;
					break;
				}
			}
		}

		return dp[0];
	}
};


//dfs without memoization 
//이해하신 부분에 대해 설명드리겠습니다.주어진 배열이 `[3, 3, 3, 1]`인 경우를 예로 들었을 때, 각 인덱스에서 가능한 점프 수를 고려한 시간 복잡도 계산에 대해 좀 더 명확히 해보겠습니다.
//
//### 주어진 배열 `[3, 3, 3, 1]` 분석:
//-배열의 각 요소는 해당 위치에서 가능한 최대 점프 수를 의미합니다.
//- 예를 들어, 첫 번째 요소가 `3`이면, 첫 번째 인덱스에서 최대 3칸까지 점프할 수 있습니다.
//
//### 재귀 호출의 흐름 :
//1. * *첫 번째 인덱스(`0`)에서 * *:
//-가능한 점프 : 1칸(`index 1`), 2칸(`index 2`), 3칸(`index 3`)
//	- 각각의 점프 후에 재귀 함수를 호출합니다.
//
//	2. * *두 번째 인덱스(`1`)에서 * *:
//-가능한 점프 : 1칸(`index 2`), 2칸(`index 3`), 3칸(배열 범위 밖이므로 무시)
//	- 다시 각각의 점프 후에 재귀 함수를 호출합니다.
//
//	3. * *세 번째 인덱스(`2`)에서 * *:
//-가능한 점프 : 1칸(`index 3`)
//	- 마지막 인덱스에 도달하므로 여기서 재귀는 종료됩니다.
//
//	### 시간 복잡도 계산 :
//-각 단계에서 가능한 모든 점프를 실행하기 때문에, 각 재귀 호출마다 가능한 모든 경로를 탐색합니다.
//- 각 인덱스에서의 가능한 점프 수는 최대 `n-1`일 수 있고, 이 경우 최악의 복잡도는 각 인덱스마다 발생하는 재귀 호출의 수가 `n`에 가까워집니다.
//- 따라서, 이 경우의 복잡도는 `O(n ^ k)` 형태가 될 수 있으며, 여기서 `k`는 배열의 길이 `n`에 매우 가깝습니다.즉, `O(n ^ n)`이 될 수 있습니다.
//
//### `O(2 ^ n)`에 대한 해석 :
//-일반적으로 `O(2 ^ n)`은 이진 결정 문제에서 나타나는 복잡도입니다.각 단계에서 두 가지 선택이 가능하고, 이 선택이 재귀적으로 반복되어 지수적으로 증가하는 경우에 적용됩니다.
//- 이 문제에서 `O(2 ^ n)`이 언급된 것은 모든 가능한 경로를 고려해야 한다는 점을 강조하기 위한 것일 수 있습니다.하지만, 실제로는 각 인덱스에서의 점프 수가 결정적인 요소이기 때문에, `O(2 ^ n)`보다는 `O(n ^ k)`가 더 정확할 수 있습니다.
//
//### 결론:
//-주어진 배열 `[3, 3, 3, 1]`에서는 각 단계에서 발생할 수 있는 재귀 호출 수가 `n`에 가까워서 `O(n ^ n)`과 같은 복잡도가 더 적합합니다.
//- `O(2 ^ n)` 복잡도는 이론적인 설명이나 가장 일반적인 최악의 경우를 가정할 때 사용될 수 있으나, 실제 코드에서는 `O(n^ k)`의 형태로 표현하는 것이 더 정확할 수 있습니다.


class Solution {

	bool dfs(int index, vector<int>& nums)
	{
		if (index == nums.size() - 1)
		{
			return true;
		}

		int maxJump = std::min(index + nums[index], (int)nums.size() - 1);

		for (int i = index + 1; i <= maxJump; i++)
		{
			if (dfs(i, nums))
			{
				return true;
			}
		}

		return false;
	}

public:
	bool canJump(vector<int>& nums) {

		return dfs(0, nums);

	}
};


//dfs with memoization 
//해당 코드에서 `O(n ^ 2)` 시간 복잡도로 설명되는 이유를 명확하게 분석해보겠습니다.이 코드는 동적 계획법의 일종인 "메모이제이션"을 사용하여 이미 계산한 결과를 저장함으로써 중복 계산을 방지합니다.
//
//### 코드의 작동 방식
//- `canJumpFromPosition` 함수는 현재 위치에서 게임의 마지막 인덱스까지 도달할 수 있는지를 재귀적으로 판단합니다.
//- `memo` 배열은 각 인덱스의 도달 가능성(`GOOD`, `BAD`, `UNKNOWN`)을 저장하여, 한 번 계산된 결과는 다시 계산하지 않도록 합니다.
//
//	### 복잡도 분석
//	1. * *재귀 호출의 최적화 * *:
//-`memo` 배열을 사용하여, 한 번 계산된 인덱스의 결과(`GOOD` 또는 `BAD`)는 다시 계산하지 않습니다.이렇게 중복 호출을 제거함으로써 알고리즘의 효율성을 크게 향상시킵니다.
//
//	2. * *포문의 역할 * *:
//-각 `position`에서 `furthestJump`까지의 모든 인덱스에 대해 재귀적으로 `canJumpFromPosition`을 호출합니다.
//- 각 위치에서 가능한 모든 점프를 시도하므로, 한 위치에서 발생할 수 있는 재귀 호출의 수는 최대 `nums[position]`입니다.
//
//3. * *복잡도 산출 * *:
//-초기 호출에서, 각 위치는 한 번씩만 처리됩니다.만약 `memo[position]`가 `UNKNOWN`이 아니라면 재귀 호출을 하지 않고 결과를 반환합니다.
//- 첫 번째 위치에서 시작할 때, 가능한 모든 점프 경로를 확인하고, 각 경로는 다시 그 경로에서 가능한 모든 점프를 확인합니다.
//- 이러한 처리는 선형적으로 연결된 최악의 경우(모든 `nums[i]`가 큰 경우) 각 위치에서 `n`개의 점프가 가능하므로 최대 `n* n = n ^ 2`의 연산이 필요할 수 있습니다.
//
//### 왜 `O(n ^ 2)`인가 ?
//-코드가 메모이제이션을 통해 중복 계산을 제거하긴 하지만, 최악의 경우 각 위치에서 가능한 모든 점프를 확인해야 합니다.
//- 각 인덱스에서 발생할 수 있는 연산은 그 인덱스에서 가능한 최대 점프 수까지 반복되므로, 이론적으로 모든 인덱스에서 최대 점프를 하는 경우 `n^2`의 연산이 필요합니다.
//- 실제 실행에서는 `memo` 배열이 중복을 줄여줘서 일반적으로 `O(n)`에 가까울 수 있지만, 최악의 경우에 대한 고려로 `O(n ^ 2)`으로 볼 수 있습니다.
//
//이렇게 최악의 시나리오를 고려할 때 `O(n ^ 2)` 복잡도가 언급되며, 각 인덱스에서 가능한 모든 경로를 탐색하는 과정에서 나타날 수 있는 최대 연산 횟수를 반영합니다.

//메모이제이션 시간복잡도를 어떻게 봐야할지 모르겠다
//내 생각에는 한번 방문 했으면 재방문하지 않기 때문에 O(n)인데.. 다른 설명에서 모두 O(n^2) 이라고 함
class Solution {

	bool dfs(int index, vector<int>& nums)
	{
		if (0 != dp[index])
		{
			return (dp[index] == 2);
		}

		if (index == nums.size() - 1)
		{
			dp[index] = 2;
			return true;
		}

		int maxJump = std::min(index + nums[index], (int)nums.size() - 1);

		for (int i = index + 1; i <= maxJump; i++)
		{
			if (dfs(i, nums))
			{
				dp[index] = 2;
				return true;
			}
		}
		dp[index] = 1;
		return false;
	}

	vector<int> dp;

public:
	bool canJump(vector<int>& nums) {

		dp.resize(nums.size());

		return dfs(0, nums);

	}
};
