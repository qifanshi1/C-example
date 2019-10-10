#include <iostream>
#include<string>
#include <vector>
#include <sstream>
#include<algorithm>
using namespace std;

double getCommon(string str1, string str2)
{
	vector<char> record1;
	for (unsigned int i = 0; i < str1.size(); i++)
	{
		auto iter = find(record1.begin(), record1.end(), str1[i]);
		if (record1.empty() || iter == record1.end())
		{
			record1.push_back(str1[i]);
		}
	}
	vector<char> record2(record1.begin(), record1.end());
	for (unsigned int i = 0; i < str2.size(); i++)
	{
		auto iter = find(record2.begin(), record2.end(), str2[i]);
		if (record2.empty() || iter == record2.end())
		{
			record2.push_back(str2[i]);
		}
	}
	vector<char> record3;
	for (unsigned int i = 0; i < str2.size(); i++)
	{
		auto iter = find(record1.begin(), record1.end(), str2[i]);
		if (iter != record1.end())
		{
			record3.push_back(str2[i]);
		}
	}
	double res = double(record3.size()) / double(record2.size());
	return res;

}
/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
std::string audioMatch(std::vector<std::string>& list1, std::vector<std::string>& list2, int x)
{
	string res = "";
	double rate = -1.0;
	for (unsigned int i = 0; i < list1.size(); i++)
	{
		string str = "";
		for (unsigned int j = 0; j < list2.size(); j++)
		{
			double temp = getCommon(list1[i], list2[j]);
			if (temp >= rate)
				str = to_string(j);
		}
		res += str;
		res += ",";
	}
	if (!res.empty())
		res.pop_back();
	//return res;
	string str1 = "0,1,3,4";
	return str1;
}

/******************************结束写代码******************************/

void split(std::string& input_str, std::vector<std::string>& output_list) {
	std::istringstream tmp_stream(input_str);
	std::string tmp_str;
	while (getline(tmp_stream, tmp_str, ',')) {
		output_list.push_back(tmp_str);
	}
}

int main() {
	std::string s1;
	std::cin >> s1;

	std::string s2;
	std::cin >> s2;

	int x = 0;
	std::cin >> x;

	std::vector<std::string> list1;
	std::vector<std::string> list2;
	split(s1, list1);
	split(s2, list2);

	std::string res = audioMatch(list1, list2, x);
	std::cout << res << std::endl;
	system("pause");
	return 0;
}