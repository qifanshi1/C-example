#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestSubstring(const string& str)
{
	//int record[26] = {-1};//记录该字符上一次出现的位置，总共26个字母,采用此方式仅初始化第一个元素为-1
	vector<int> record(26, -1);
	//vector<int> maxlength(str.size() + 1, 0);//记录以当前字符为结尾的不包含重复字符的最长子字符串的长度	
	int lastLength = 0;
	int max_index = 0, max_length = 0;
	for (int i = 0; i < str.size(); i++)
	{
		int temp = record[str[i] - 'a'];
		if (temp < 0 || i - temp > lastLength)
		{
			lastLength++;
		}
		else
		{
			lastLength = i - temp;
		}
		if (lastLength > max_length)
		{
			max_length = lastLength;
			max_index = i;
		}
		record[str[i] - 'a'] = i;
	}
	return str.substr(max_index - max_length + 1, max_length);
}
int main()
{
	string str;
	cin >> str;
	string res = longestSubstring(str);

	system("pause");
	return 0;
}