#include <iostream>
#include <vector>
#include <string>
using namespace std;
#pragma warning(disable:4996)

string n2s[] = {
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

string scale[] = {
	"", "", "Shi", "Bai", "Qian"
};

vector<string> res = vector<string>();
bool toChinese(string num) {
	bool changed = false;
	int len = num.length();
	string::iterator it = num.begin();
	bool zero = false;
	for (; it != num.end(); it++, len--) {
		if (*it == '0') {
			zero = true;
			continue;
		} else {
			changed = true;
			if (zero) res.push_back(n2s[0]);
			zero = false;
			res.push_back(n2s[*it-'0']);
			if (scale[len].size() > 0) {
				res.push_back(scale[len]);
			}
		}
	}
	return changed;
}

int main() {
	//freopen("..\\input.txt", "r", stdin);
	string num; cin >> num;
	if (num.front() == '-') {
		res.push_back("Fu");
		num.erase(num.begin());
	}

	int len = num.length();
	if (len > 8) {
		if (toChinese(num.substr(0, len - 8))) res.push_back("Yi");
		if (toChinese(num.substr(len - 8, 4))) res.push_back("Wan");
		toChinese(num.substr(len - 4));
	} else if (len > 4) {
		if (toChinese(num.substr(0, len - 4))) res.push_back("Wan");
		toChinese(num.substr(len - 4));
	} else {
		toChinese(num);
	}

	if (res.empty()) res.push_back(n2s[0]);

	vector<string>::iterator it = res.begin();
	cout << *it;
	for (it++; it != res.end(); it++) {
		cout << ' ' << *it;
	}
	cout << endl;
}