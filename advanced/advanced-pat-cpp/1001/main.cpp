#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int a, b;
	cin >> a >> b;
	ostringstream sout;
	sout << a+b;
	string s(sout.str());
	for (int i = s.size() - 3; i > 0 && s[i-1] != '-'; i -= 3) {
		s.insert(s.begin()+i, ',');
	}
	cout << s << endl;
}