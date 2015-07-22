#include <set>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class mstring : public string {
public:
	inline bool operator<(const string &s) const {
		string tmpa(*this);
		tmpa.append(s);
		string tmpb(s);
		tmpb.append(*this);
		return tmpa.compare(tmpb) < 0;
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	cin >> N;
	set<mstring> nums;
	mstring ms;
	while (N--) {
		cin >> ms;
		nums.insert(ms);
	}
	mstring num;
	set<mstring>::iterator it = nums.begin();
	while (it!=nums.end()) {
		num += *(it++);
	}
	while (!num.empty() && *num.begin()=='0') {
		num.erase(num.begin());
	}
	if (num.empty()) {
		num += '0';
	}
	cout << num << endl;
}