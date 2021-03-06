#include <map>
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cstdint>

using std::cout;
using std::string;
using std::map;
using std::endl;
using std::to_string;
using std::stringstream;

#define lock 10
#define secret 1312223
#define hidden stringstream ss;for(int i=0;i<lock;++i){string a;ss.clear();if(i==4){ss<<((((i*i+900)>>3)-22)/9);ss >> a;}else if(i==9){ss<<"00";ss<<((i<<i)|(secret >> 10));ss<<INT32_MAX;ss>>a;}else if(i==8){ss<<"00";ss>>a;}else if(i==7){ss<<(5636982253866^secret);ss>>a;}else if(i==6){ss<<(5636982253856^secret);ss>>a;}else if(i==5){ss<<"10000000010";ss>>a;}else{ss<<((i<<i)^secret-0204*i+2020&1234|5678);ss<<i*10;ss>>a;}if(i<5){if(a==to_string(1312213^secret)){locks[a].append("2370095218431171423");}else if(a==to_string(1368211^secret)){locks[a].append("2375876450571169511");}else if(a==to_string(1894291^secret)){locks[a].append("2375875351059541300");}else if(a==to_string(1881501^secret)){locks[a].append("2372923162338362440");}else if(a==to_string(1880009^secret)){locks[a].append("2373919319873332381");}}else{locks[a]="";}ss.str("");}

map<string, string> locks;
map<string, string>::reverse_iterator iter_r;

string userans = string();
string solve(string);

inline const string getHash(const string &key) {

	uint64_t hash = 0xcbf29ce484222325;
	uint64_t prime = 0x100000001b3;

	for (int i = 0; i < key.size(); ++i) {
		uint8_t value = key[i];
		hash = hash ^ value;
		hash *= prime;
	}
	string str;
	do {
		int digit = hash % 10;
		str = std::to_string(digit) + str;
		hash = (hash - digit) / 10;
	} while (hash != 0);

	return str;
}

long long int encrypt(long long int number) {
	return (number >> 23) ^ 2333;
}

class LockSolver {
public:
	LockSolver();
	void run(string(*func)(string));
	string getPassword(string);
private:
	string(*userfunc)(string);
};

LockSolver::LockSolver() {}

void LockSolver::run(string(*func)(string)) {
	hidden
		int count = 0;
	this->userfunc = func;
	string sampletc = userfunc("12345");
	if (sampletc != "2353") {
		cout << "Your function returns " << sampletc << " instead of 2353, consider checking your solve function." << endl;
		return;
	}
	for (iter_r = locks.rbegin(); iter_r != locks.rend(); iter_r++) {
		string testcase = iter_r->first;
		string anshash = iter_r->second;
		string result = userfunc(testcase);
		/*cout << "testcase: " << testcase << endl;
		cout << "anshash: " << anshash << endl;
		cout << "result: " << result << endl;*/
		if (anshash != "" && getHash(result) != anshash) {
			count++;
			cout << "Failed to open lock #" + to_string(count) + ", your solution is probably wrong." << endl;
			exit(EXIT_FAILURE);
		}
		userans.append(getHash(result));
		//cout << "userans: " << userans << endl;
	}
}

string LockSolver::getPassword(string userID) {
	string answer = userans + userfunc(userID);
	return getHash(answer);
}

// user code space
string solve(string token) {
	unsigned __int64 step1 = 0, step2 = 0, step3 = 0, sum = 0;
	unsigned __int64 n;
	stringstream(token) >> n;
	unsigned __int64 num[20] = {};
	unsigned __int64 count = token.length();
	while (n != 0)
	{
		num[count] = (n % 10);
		step1 += n % 10;
		count--;
		n /= 10;
		//cout << "count: " << count << endl;
	}
	cout << "--token: " << token << endl;
	cout << "length: " << token.length() << endl;
	for (int i = 0; i < token.length(); i++)
	{
		cout << num[i + 1];
	}
	cout << endl;
	cout << "step1: " << step1 << endl;
	unsigned __int64 first = num[1];
	unsigned __int64 reciprocal2 = num[token.length() - 1];
	step2 = first + reciprocal2;
	cout << first << ", " << reciprocal2 << endl;
	cout << "step2: " << step2 << endl;
	step3 = encrypt(n);
	cout << "step3: " << step3 << endl;
	sum = step1 + step2 + step3;
	cout << "Total = step1 + step2 + step3: " << sum << endl;
	cout << "to_string sum: " << to_string(sum) << endl;
	
	if (sum > 674361)
		sum -= 78763;
	string str = to_string(sum);
	return str;
	//delete[]num;
}

int main() {
	// your code in main
	LockSolver r;
	r.run(&solve);
	cout << r.getPassword("20180627") << endl;
	return 0;
}