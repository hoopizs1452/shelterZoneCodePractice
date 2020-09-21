#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	int count;
	string str;
	cin >> str;
	
	//count = str.find("h");
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'h')
		{
			if (str[i + 1] == 't')
			{
				for (int j = 0; j < 27; j++)
				{
					cout << str[i + j];
				}
				cout << endl;
			}
		}
	}


	return 0;
}