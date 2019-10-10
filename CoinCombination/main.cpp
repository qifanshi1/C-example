#include<iostream>
#include<vector>
using namespace std;

int CoinCombinations(vector<int> coins, int sum)
{
	if (coins.empty()||sum==0)
		return 0;
	int num = coins.size();
	vector<vector<int>> dp(num + 1, vector<int>(sum + 1, 0));
	for (int i = 0; i <= num; i++)
	{
		dp[i][0] = 1;
	}
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			dp[i][j] = 0;
			int condition = j / coins[i - 1];
			for (int k = 0; k <= condition; k++)
			{
				dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
			}
		}
	}
	return dp[num][sum];
}
int main()
{
	vector<int> coins = { 1,2,5};
	int sum = 5;
	int res = CoinCombinations(coins, sum);
	cout << res << endl;
	system("pause");
	return 0;
}