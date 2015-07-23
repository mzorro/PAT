#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

typedef long long int LONG;

LONG toInt(char c) {
	if (c >= '0' && c <= '9') return c - '0';
	else return c - 'a' + 10;
}

LONG translate(string &num, LONG radix) {
	LONG res = 0;
	string::iterator it = num.begin();
	for (; it != num.end(); it++) {
		res *= radix;
		res += toInt(*it);
		if (res < 0) return -1; // control overflow
	}
	return res;
}

int main() {
	// freopen("..\\input.txt", "r", stdin);
	string s1, s2;
	LONG tag, radix;
	cin >> s1 >> s2 >> tag >> radix;
	string &num1 = tag == 1 ? s1 : s2;
	string &num2 = tag == 1 ? s2 : s1;
	LONG n1 = translate(num1, radix);
	LONG low = 0;
	string::iterator it = num2.begin();
	for (; it != num2.end(); it++) {
		low = max(toInt(*it)+1, low);
	}
	LONG high = n1 + 1;
	LONG mid, n2;
	while (low <= high) {
		mid = (low + high) / 2;
		n2 = translate(num2, mid);
		if (n2 > n1 || n2 == -1) high = mid - 1;
		else if (n2 < n1) low = mid + 1;
		else break;
	}
	if (low <= high) cout << mid << endl;
	else cout << "Impossible" << endl;
}