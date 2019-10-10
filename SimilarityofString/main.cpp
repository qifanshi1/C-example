#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
int shortEdit(const string& str1, const string& str2)
{
	/*if (str1.size() == 0)
		return str2.size();
	if (str2.size() == 0)
		return str1.size();
	if (str1 == str2)
		return 0;*/
	int length1 = str1.size();
	int length2 = str2.size();
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, INT_MAX));
	for (int i = 0; i <= length1; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= length2; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
			}
		}
	}
	return dp[length1][length2];
}
int main()
{
	string str1 = "abccd";
	string str2 = "bccd";
	int len = shortEdit(str1, str2);
	cout << len << endl;
	system("pause");
	return 0;
}