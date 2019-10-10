#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MaxGift(const vector<vector<int>>& value)
{
	if (value.empty() || value[0].empty())
		return 0;
	int height = value.size();
	int width = value[0].size();

	vector<int> max_value(width,0);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int left = 0, up = 0;
			if (i > 0)
			{
				up = max_value[j];
			}
			if (j > 0)
			{
				left = max_value[j - 1];
			}
			max_value[j] = max(left, up) + value[i][j];
		}
	}
	return max_value[width - 1];
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> value;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		for (int j = 0; j < m; j++)
		{
			int num;
			cin >> num;
			temp.push_back(num);
		}
		value.push_back(temp);
	}
	int sum = MaxGift(value);
	system("pause");
	return 0;
}