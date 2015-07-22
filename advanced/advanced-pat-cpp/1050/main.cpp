#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	string::iterator it;
	for (it = s1.begin(); it!=s1.end(); it++) {
		if (s2.find(*it)==string::npos) {
			cout << *it;
		}
	}
	cout << endl;
}