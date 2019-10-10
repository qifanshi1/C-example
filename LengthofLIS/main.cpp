#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums,vector<int>& dp) {
	if (nums.size() <= 1)
		return nums.size();
	int res = 1;	
	int index = 0;
	for (int i = 1; i < nums.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (nums[j] < nums[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		if (dp[i] > res)
		{
			res = dp[i];
			index = i;
		}
	}
	return index;
}
void getLIS(const vector<int>& nums, const vector<int>& dp,
	int i, vector<int> &res)
{
	if (i < 0)
		return;
	res.push_back(nums[i]);	
	int length = dp[i];
	while (length > 0)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j]<nums[i]&&dp[i] == dp[j] + 1)
			{
				res.push_back(nums[j]);
				i = j;
				break;
			}
		}
		length--;
	}	
}
int main()
{
	vector<int> input = { 10,1,9,2,5,3,7,101,18 };
	int index;
	vector<int> dp(input.size(), 1);
	index = lengthOfLIS(input,dp);
	int length = dp[index];
	vector<int> res;
	getLIS(input, dp, index, res);
	for (auto a : res)
	{
		cout << a << endl;
	}
	system("pause");
	return 0;
}