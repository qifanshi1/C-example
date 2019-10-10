#include<string>
#include<vector>
#include<iostream>

using namespace std;

int currentShortStr(string str, int left)
{
	int right = left;
	for (int i = left; i < str.size(); i++)
	{
		if (str[i] == str[left])
			right = i;
	}
	return right;
}

bool isOK(string str, int left, int right, int& expand)
{
	bool flag = true;
	int max_right = right;
	for (int i = left + 1; i < right; i++)
	{
		if (str[i] != str[left])
		{
			int temp = currentShortStr(str, i);
			if (temp > right)
			{
				flag = false;
				if (temp > max_right)
				{
					max_right = temp;
					right= temp;
				}					
			}
		}
	}
	expand = max_right;
	return flag;
}
int main()
{
	string str;
	cin >> str;

	vector<int> res;

	for (int i = 0; i < str.size(); )
	{
		int right = currentShortStr(str, i);
		int expand = right;
		bool flag = isOK(str, i, right, expand);
		if (flag)
		{
			int length = right - i + 1;
			res.push_back(length);
			i = right + 1;
		}
		else
		{
			int length = expand - i + 1;
			res.push_back(length);
			i = expand + 1;
		}
	}

	for (auto a : res)
	{
		cout << a << " ";
	}
	system("pause");
	return 0;
}