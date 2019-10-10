#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>

using namespace std;

int LCS(const string& str1, const string& str2,vector<vector<int>>& dp)
{
	if (str1.empty() || str2.empty())
		return 0;
	int length1 = str1.size();
	int length2 = str2.size();

	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (dp[i - 1][j] >= dp[i][j - 1])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	return dp[length1][length2];
}
void getLCS(const string& str1, const string& str2, 
	const vector<vector<int>>& dp,
	int i, int j,string res,set<string>& all_res)
{
	if (i == 0 || j == 0)
		return ;
	while (i > 0 && j > 0)
	{
		if (str1[i-1] == str2[j-1])
		{
			res = str1[i - 1] + res;
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			i--;
		}
		else if(dp[i - 1][j] < dp[i][j - 1])
		{
			j--;
		}
		else
		{
			getLCS(str1, str2, dp, i - 1, j, res,all_res);
			getLCS(str1, str2, dp, i, j - 1, res, all_res);
			return;
		}
	}
	all_res.insert(res);
}
int main()
{
	string str1 = "ABCBDAB";
	string str2 = "BDCABA";
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));
	int length = LCS(str1, str2, dp);
	string res="";
	set<string> all_res; 
	getLCS(str1, str2, dp, str1.size(), str2.size(), res,all_res);
	cout << length << endl;
	//cout << res << endl;
	for (auto a : all_res)
	{
		cout << a << endl;
	}
	system("pause");
	return 0;
}