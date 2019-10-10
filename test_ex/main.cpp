#include<iostream>
#include<string>
#include<stack>
#include<set>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
void noRepeat(const vector<int>& input1, const vector<int>& input2)
{
	if (input1.empty())
		return;
	
	set<int> res;
	for (int i = 0; i < input1.size(); i++)
	{
		bool flag = true;
		for (int j = 0; j < input2.size(); j++)
		{
			if (input1[i] == input2[j])
			{
				flag = false;
				continue;
			}	
		}
		if (flag&&res.find(input1[i]) == res.end())
			res.insert(input1[i]);
	}
	for (auto a : res)
	{
		cout << a << " ";
	}
}
int findNum(const vector<int>& input)
{
	if (input.size() < 1000)
		return -1;
	vector<int> res(1000);
	int i = 0, len = input.size();
	while (i < 1000)
	{
		res.push_back(input[i]);
		i++;
	}
	make_heap(res.begin(), res.end());
	while (i < len)
	{
		int tmp = res[0];
		if (input[i] < tmp)
		{
			pop_heap(res.begin(), res.end());
			res.pop_back();
			res.push_back(input[i]);
			make_heap(res.begin(), res.end());
		}
		i++;
	}
	return res[0];
}
int findNum1(const vector<int>& input)
{
	if (input.size() < 1000)
		return -1;
	multiset<int, greater<int>> res;
	int i = 0;
	while (i < 1000)
	{
		res.insert(input[i]);
		i++;
	}
	while (i < input.size())
	{
		auto iter = res.begin();
		if (input[i] < *iter)
		{
			res.erase(iter);
			res.insert(input[i]);
		}
		i++;
	}
	return *res.begin();
}
struct test
{
	int x;
	char y;
	static int z;
};
int partion(vector<int>& num,int begin,int end)
{
	int tmp = num[end];
	int i = begin - 1, j = begin;
	for (; j < end; j++)
	{
		if (num[j] < tmp)
		{
			i++;
			if (i != j)
				swap(num[i], num[j]);
		}
	}
	swap(num[++i], num[end]);
	return i;
}
int findMiddleNum(vector<int> num,int k)
{
	if (num.empty() || k <= 0)
		return -1;
	int begin = 0, end = num.size() - 1;
	int index = partion(num, 0, end);
	while (index!=k-1)
	{
		if (index > k - 1)
			end = index - 1;
		else
		{
			begin = index + 1;
		}
		index = partion(num, begin, end);
	}
	return num[k - 1];
}
int FindMaxNum(vector<int> num)
{
	if (num.empty())
		return -1;
	if (num.size() <= 2)
		return num[num.size() - 1];
	int left = 0, right = num.size() - 1;
	while (left < right) //最终left==right，即为所求
	{
		int middle = (left + right) >> 1;
		if (num[middle] < num[middle + 1])//middle<=right
			left = middle + 1;//说明最大值在middle右边
		else
			right = middle;
	}
	return num[left];
}
//string ReverseSentence(string str) {
//	stack<string> stk;
//	if (str.empty())
//		return "";
//	string tmp = "";
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] != ' ')
//			tmp += str[i];
//		if (i == str.size() - 1 || str[i] == ' ')
//		{
//			stk.push(tmp);
//			tmp = "";
//		}
//	}
//	string res = "";
//	while (!stk.empty())
//	{
//		res += stk.top();
//		res += ' ';
//		stk.pop();
//	}
//	if (!res.empty())
//		res = res.substr(0, res.size() - 1);
//	return res;
//}
void Reverse(string& str, int begin, int end)//引用传参
{
 	while (begin < end)
	{
		swap(str[begin], str[end]);
		begin++;
		end--;
	}
}
string ReverseSentence(string str) {
	if (str.empty())
		return "";
	int len = str.size();
	Reverse(str, 0, len - 1);
	int begin = 0, end = 0;
	while (begin < len)
	{
		if (str[begin] == ' ')
		{
			begin++;
			end++;
		}
		else if (str[end] == ' ' || end == len - 1)
		{
			Reverse(str, begin, --end);
			begin = ++end;
		}
		else
		{
			end++;
		}
	}
	return str;
}
int main()
{
	string str = "I am a student.";
	//string str1 = ReverseSentence(str);
	Reverse(str,0,str.size()-1);
	string str1 = ReverseSentence(str);
	cout << str << endl;
	cout << str1 << endl;
	vector<int> input1 = { 1,2,3,5 };
	int max_val = FindMaxNum(input1);
	cout << max_val << endl;

	cout << sizeof(test) << endl;
	vector<int> input;
	for (int i = 0; i < 100; i++)
	{
		int tmp = rand() % 100;
		input.push_back(tmp);
	}
	int middle_val = findMiddleNum(input, 15);
	cout << middle_val << endl;
	//int val = findNum1(input);
	sort(input.begin(), input.end());
	cout << input[14] << endl;
	system("pause");
	return 0;
}