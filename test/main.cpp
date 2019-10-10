#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<stdio.h>

using namespace std;

void permutation(string str, int k, int m,
	vector<string>& vec_str)
{
	int i, j;
	if (k == m)
	{
		if (find(vec_str.begin(), vec_str.end(), str) == vec_str.end())
			vec_str.push_back(str);
	}
	else
	{
		for (j = k; j <= m; j++)
		{
			swap(str[j], str[k]);
			permutation(str, k + 1, m, vec_str);
		}
	}
}
int main()
{
	int i = INT_MIN;
	string str="bac";
	cout << str << "所有全排列的结果为：" << endl;
	vector<string> res;
	permutation(str, 0, str.size() - 1, res);
	/*sort(res.begin(), res.end());
	auto it=unique(res.begin(), res.end());
	res.erase(it, res.end());*/
	system("pause");
	return 0;
}