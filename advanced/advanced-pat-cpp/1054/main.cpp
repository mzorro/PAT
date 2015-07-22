#include <iostream>
#include <map>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	map<int, int> cnt;
	int M, N, color;
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &color);
			if (cnt.find(color)==cnt.end()) {
				cnt[color] = 1;
			} else {
				cnt[color] += 1;
			}
			if (cnt[color] >= M * N / 2) {
				printf("%d\n", color);
				return 0;
			}
		}
	}
}