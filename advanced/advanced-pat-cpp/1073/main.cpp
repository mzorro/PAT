#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)
int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	string num;
	cin >> num;
	if (num[0] == '-') cout << '-';
	num.erase(num.begin());
	unsigned loc = num.find('E');
	string base = num.substr(0, loc);
	string exp = num.substr(loc + 1);
	istringstream sin(exp);
	int move; sin >> move;
	base.erase(base.begin()+1);
	int right = base.length() - 1;
	if (move >= right) {
		move -= right;
		while (move--) base.push_back('0');
	} else if (move > -1) {
		base.insert(base.begin()+1+move, '.');
	} else {
		move = -1 - move;
		while (move--) base.insert(base.begin(), '0');
		base.insert(base.begin(), '.');
	}
	if (base[0] == '.') base.insert(base.begin(), '0');
	cout << base << endl;
}