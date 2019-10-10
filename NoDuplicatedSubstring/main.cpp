#include<iostream>
#include<vector>
#include<string>

using namespace std;

string longestSubstring(const string& str)
{
	//int record[26] = {-1};//��¼���ַ���һ�γ��ֵ�λ�ã��ܹ�26����ĸ,���ô˷�ʽ����ʼ����һ��Ԫ��Ϊ-1
	vector<int> record(26, -1);
	//vector<int> maxlength(str.size() + 1, 0);//��¼�Ե�ǰ�ַ�Ϊ��β�Ĳ������ظ��ַ�������ַ����ĳ���	
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