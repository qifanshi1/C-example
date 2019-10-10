#include<typeinfo>
#include<iostream>
#include<vector>

using namespace std;

void merge_vec(vector<int>& sort_data, vector<vector<int>>& res,
	int begin, int middle, int end)
{
	vector<int> temp(sort_data.begin(), sort_data.end());
	int p1 = middle, p2 = end, p3 = end;
	while (p1 >= begin && p2 >= middle + 1)
	{
		if (sort_data[p1] > sort_data[p2])
		{
			int i = p2;
			while (i >= middle + 1)
			{
				vector<int> temp;
				temp.push_back(sort_data[p1]);
				temp.push_back(sort_data[i]);
				res.push_back(temp);
				i--;
			}
			temp[p3--] = sort_data[p1--];
		}
		else
		{
			temp[p3--] = sort_data[p2--];
		}
	}
	while (p1 >= begin)
	{
		temp[p3--] = sort_data[p1--];
	}
	while (p2 >= middle + 1)
	{
		temp[p3--] = sort_data[p2--];
	}
	temp.swap(sort_data);
}
void Merge(vector<int>& sort_data, vector<vector<int>>& res,
	int begin, int end)
{
	if (begin >= end)
		return;
	Merge(sort_data, res, begin, (begin + end) / 2);
	Merge(sort_data, res, (begin + end) / 2 + 1, end);
	merge_vec(sort_data, res, begin, (begin + end) / 2, end);
}
int InversePairs(vector<int> data) {
	if (data.size() <= 1)
		return 0;
	int count = 0;
	vector<int> sort_data(data.begin(), data.end());
	vector<vector<int>> res;
	Merge(sort_data, res, 0, data.size() - 1);
	count = res.size();
	return count;
}
int main()
{
	
	vector<int> data = { 7,5,6,4 };
	int res = InversePairs(data);
	cout << res << endl;
	system("pause");
	return 0;
}