#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

string LCS_length(const string& str1, const string& str2)
{
	if (str1.empty() || str2.empty())
		return 0;
	int length1 = str1.size();
	int length2 = str2.size();
	vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
	int maxlength = 0;
	int begin = 0;
	for (int i = 1; i <= length1; i++)
	{
		for (int j = 1; j <= length2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			if (dp[i][j] > maxlength)
			{
				maxlength = dp[i][j];
				begin = i - maxlength;
			}
		}
	}
	return str1.substr(begin, maxlength);
}
int main()
{
	string str1 = "ABCBDAB";
	string str2 = "BDCABCBA";

	string res = LCS_length(str1, str2);
	cout << res << endl;
	system("pause");
	return 0;
}