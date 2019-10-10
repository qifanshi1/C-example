#include<vector>
#include<iostream>
using namespace std;

//compute the nums of inverse pairs
long long Merge(vector<int>& data,
	int begin, int end)
{
	if (begin >= end)
		return 0;
	long long left = Merge(data, begin, (begin + end) / 2);
	long long right = Merge(data, (begin + end) / 2 + 1, end);
	vector<int> temp(data.begin(), data.end());
	int middle = (begin + end) / 2;
	int i = middle, j = end, k = end;
	long long count = 0;
	while (i >= begin && j >= middle + 1)
	{
		if (data[i] > data[j])
		{
			count = j - middle;
			temp[k--] = data[i--];
		}
		else
		{
			temp[k--] = data[j--];
		}
	}
	while (i >= begin)
	{
		temp[k--] = data[i--];
	}
	while (j >= middle + 1)
	{
		temp[k--] = data[j--];
	}
	data.swap(temp);
	return left + right + count;
}
int InversePairs(vector<int> data) {
	if (data.size() <= 1)
		return 0;
	long long count = 0;	
	count = Merge(data, 0, data.size() - 1);
	return count % 1000000007;
}
int main()
{

	vector<int> data = { 7,5,6,4 };
	int res = InversePairs(data);
	cout << res << endl;
	system("pause");
	return 0;
}
