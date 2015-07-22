#include <iostream>
#include <functional>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	map<int, float> poly;
	set<int, greater<int>> exps;
	int N, exp;
	float coe;
	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		poly[exp] = coe;
		exps.insert(exp);
	}
	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		if (exps.find(exp) != exps.end()) {
			poly[exp] += coe;
			if (abs(poly[exp]) < 5e-3) exps.erase(exp);
		} else {
			poly[exp] = coe;
			exps.insert(exp);
		}
	}
	cout.precision(1);
	cout << fixed;
	cout << exps.size();
	set<int>::iterator it = exps.begin();
	for (; it != exps.end(); it++) {
		cout << ' ' << *it << ' ' << poly[*it];
	}
	cout << endl;
}