#include <iostream>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

int main() {
	// freopen("..\\input.txt", "r", stdin);
	int N; cin >> N;
	int time = N * 5;
	int stop = 0, i;
	while (N--) {
		cin >> i;
		if (i > stop) {
			time += (i - stop) * 6;
		} else {
			time += (stop - i) * 4;
		}
		stop = i;
	}
	cout << time << endl;
}