#include <cstdio>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<int> circle(N+1, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &circle[i]);
		circle[i] += circle[i-1];
	}
	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a > b) swap(a, b);
		int length = circle[b-1] - circle[a-1];
		printf("%d\n", min(length, circle.back()-length));
	}
}