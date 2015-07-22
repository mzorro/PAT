#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

int N;
string handle(string &num) {
	while (!num.empty() && *num.begin()=='0') {
		num.erase(num.begin());
	}
	int cnt = num.find('.');
	if (cnt==string::npos) {
		cnt = num.size();
	} else {
		while (*(num.end()-1)=='0') {
			num.erase(num.end()-1);
		}
		num.erase(num.begin()+cnt);
	}
	while (!num.empty() && *num.begin()=='0') {
		num.erase(num.begin());
		cnt--;
	}
	ostringstream sout;
	sout << "0.";
	int len = num.size();
	if (len < N) {
		sout << num;
		for (int i=0; i < N-len; i++) {
			sout << '0';
		}
	} else {
		sout << num.substr(0, N);
	}
	sout << "*10^" << cnt;
	return sout.str();
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	cin >> N;
	string num1, num2;
	cin >> num1 >> num2;
	
	string s1 = handle(num1);
	string s2 = handle(num2);
	bool equal = true;
	if (s1==s2) {
		cout << "YES " << s1;
	} else {
		cout << "NO " << s1 << ' ' << s2;
	}
	cout << endl;
}