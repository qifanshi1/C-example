#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int MakeCoin(vector<int> coins, int sum)
{
	if (coins.empty() || sum == 0)
		return 0;
	int num = coins.size();
	vector<int> dp(sum + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 1; i <= sum; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (i - coins[j] < 0)
				break;
			else
			{
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[sum];

}
int main()
{
	vector<int> coins = { 1,3,5 };
	int sum = 11;
	int res = MakeCoin(coins, sum);
	cout << res << endl;
	system("pause");
	return 0;
}