#include <cstdio>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int cnt[10005];
int nums[100005];
int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	memset(cnt, 0, sizeof(cnt));
	memset(nums, -1, sizeof(nums));
	int N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		nums[i] = n;
		cnt[n] += 1;
	}
	n = -1;
	while (++n < N) {
		if (cnt[nums[n]]==1) {
			printf("%d\n", nums[n]);
			break;
		}
	}
	if (n==N) {
		printf("None\n");
	}
}