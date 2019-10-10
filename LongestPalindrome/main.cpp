#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s) {
	if (s.size() <= 1)
		return s;
	int length = s.size();
	vector<vector<bool>> dp(length, vector<bool>(length, false));
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (i >= j)
				dp[i][j] = true;
		}
	}
	int maxlength = 1, begin = 0;
	for (int l = 2; l <= length; l++)
	{
		for (int i = 0; i + l - 1 < length; i++)
		{
			int j = i + l - 1;
			if (s[i] == s[j] && dp[i + 1][j - 1])
			{
				dp[i][j] = true;
				if (l > maxlength)
				{
					maxlength = l;
					begin = i;
				}
			}
		}
	}
	return s.substr(begin, maxlength);
}
int main()
{
	string s;
	cin >> s;
	string res;
	res = longestPalindrome(s);
	cout << res << endl;
	system("pause");
	return 0;
}