#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

int main() {
	// freopen("..\\input.txt", "r", stdin);
	vector<float> p1(2001, 0), p2(2001, 0);
	set<int, greater<int>> exp1, exp2;
	int N, exp;
	float coe;
	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		p1[exp] = coe;
		exp1.insert(exp);
	}
	cin >> N;
	while (N--) {
		cin >> exp >> coe;
		set<int>::iterator it = exp1.begin();
		for (; it != exp1.end(); it++) {
			p2[*it+exp] += coe * p1[*it];
			exp2.insert(*it+exp);
			if (abs(p2[*it+exp]) < 5e-3) exp2.erase(*it+exp);
		}
	}
	cout << exp2.size();
	cout.precision(1);
	cout << fixed;
	set<int>::iterator it = exp2.begin();
	for (; it != exp2.end(); it++) {
		cout << ' ' << *it << ' ' << p2[*it];
	}
	cout << endl;
}