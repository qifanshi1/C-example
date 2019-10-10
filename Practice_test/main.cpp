#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
void calculate(map<char, int>& record, string str)
{
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] != ',')
		{
			if (record[str[i]] <= record[str[0]])
				record[str[i]] = record[str[0]] + 1;
			else
				record[str[i]]++;
		}
	}
}
vector<string> costsOfNodes(vector<string> lines) {
	map<char, int> record;
	//initial the map
	for (int i = 0; i < lines.size(); i++)
	{
		record[lines[i][0]] = 1;
	}
	for (int i = 0; i < lines.size(); i++)
	{
		calculate(record, lines[i]);
	}
	vector<string> res;
	for (auto iter = record.begin(); iter != record.end(); iter++)
	{
		string tmp = "";
		tmp += iter->first;
		tmp += ",";
		tmp += to_string(iter->second);
		res.push_back(tmp);
	}
	return res;
}

int main()
{
	vector<string> input = { {"1"},{"G"} };
	vector<string> result = costsOfNodes(input);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << "\n";
		}
	}
	system("pause");
	return 0;
}