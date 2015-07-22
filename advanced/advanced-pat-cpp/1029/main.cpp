#include <cstdio>
#define MAX_LEN 1000000
using namespace std;

int a1[MAX_LEN];
int a2[MAX_LEN];

int main() {
	int N1, N2, N;
	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%d", &a1[i]);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%d", &a2[i]);
	}
	N = N1 + N2;
	N = N % 2 == 0 ? N/2 : N/2 + 1;
	int i1, i2; i1 = i2 = 0;
	register int res;
	for (int i = 0; i < N; i++) {
		if (i1 >= N1) {
			res = a2[i2++];
		} else if (i2 >= N2) {
			res = a1[i1++];
		} else if (a1[i1] < a2[i2]) {
			res = a1[i1++];
		} else {
			res = a2[i2++];
		}
	}
	printf("%d\n", res);
}