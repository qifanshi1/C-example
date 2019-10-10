#include<iostream>
#include<string>
extern int a;
using namespace std;
int main()
{
	int x, y;
	cin >> x >> y;
	string str;
	cin >> str;

	int i = 0, j = str.size() - 1;
	int sum1 = 0, sum2 = 0, interval = 1;
	while (i <= j)
	{
		if (sum1 <= sum2)
		{
			sum1 = sum1 * x + int(str[i++]-'0');
		}
		else
		{
			sum2 = sum2 + interval * int(str[j--]-'0');
			interval = y * interval;
		}
	}
	cout << sum1 << endl;
	system("pause");
	return 0;
}