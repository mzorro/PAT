#include <iostream>
#include <queue>
#include <functional>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int NC, NP;
	priority_queue<int, vector<int>, greater<int> > cneg, pneg;
	priority_queue<int> cpos, ppos;
	int n;
	cin >> NC;
	while (NC--) {
		cin >> n;
		if (n < 0) cneg.push(n);
		else       cpos.push(n);
	}
	cin >> NP;
	while (NP--) {
		cin >> n;
		if (n < 0) pneg.push(n);
		else       ppos.push(n);
	}
	long long sum = 0;
	while (!cpos.empty() && !ppos.empty()) {
		sum += cpos.top() * ppos.top();
		cpos.pop(), ppos.pop();
	}
	while (!cneg.empty() && !pneg.empty()) {
		sum += cneg.top() * pneg.top();
		cneg.pop(), pneg.pop();
	}
	cout << sum << endl;
}
