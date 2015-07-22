#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int seq[100005];
bool vst[100005];
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	memset(vst, 0, sizeof(vst));
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> seq[i];
		if (seq[i] == i) vst[i] = true;
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (vst[i]) continue;
		cnt++;
		int j = i;
		while (!vst[j]) {
			vst[j] = true;
			j = seq[j];
			if (j == 0) cnt -= 2;
			cnt++;
		}
	}
	cout << cnt << endl;
}