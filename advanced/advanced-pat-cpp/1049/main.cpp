#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, cnt = 0, base = 1;
	cin >> N;
	int left, right, cur;
	while (N >= base) {
		left = N / (base * 10);
		right = N % base;
		cur = (N / base) % 10;
		if (cur==0) {
			cnt += left * base;
		} else if (cur==1) {
			cnt += left * base + right + 1;
		} else {
			cnt += (left+1) * base;
		}
		base *= 10;
	}
	cout << cnt << endl;
}