#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int num;
	cin >> num;
	string *arr;
	arr = new string [num];

	for (int i = 0; i < num; i++)
	{
		getline(cin, str);
		for (int j = 0; j < str.length(); j++)
		{
			if (str[j] >= 97 && str[j] <= 122)
				str[j] -= 32;
			else if (str[j] >= 65 && str[j] <= 90)
				str[j] += 32;
		}
		arr[i].append(str);
	}

	for (int i = 0; i < num; i++)
	{
		cout << arr[i] << endl;
	}
}