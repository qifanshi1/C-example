#include<iostream>
#include<string>

using namespace std;
int main()
{
	string input,output="";
	cin >> input;
	int pos = 0;
	int length = input.size() ;
	while (pos < length)
	{
		int next = pos + 1;
		for (; next < length; next++)
		{
			if (input[next] != input[next - 1] + 1)
				break;
		}
		if (next - pos >= 4)
		{
			output += input[pos];
			output += '-';
			output += input[next - 1];
		}
		else
		{
			output += input.substr(pos, next - pos);
		}
		pos = next;
	}
	cout << output << endl;
	system("pause");
	return 0;
}