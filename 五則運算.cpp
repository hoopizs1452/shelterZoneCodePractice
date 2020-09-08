#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[3] = {};

	for (int i = 0; i < 3; i++)
	{
		cin >> str[i];
	}

	int num1 = atoi(str[0].c_str()), numLast = atoi(str[2].c_str());
	string n = str[1];

	if (n == "+")
		cout << num1 + numLast << endl;
	else if (n == "-")
		cout << num1 - numLast << endl;
	else if (n == "*")
		cout << num1 * numLast << endl;
	else
		cout << num1 / numLast << endl;
}