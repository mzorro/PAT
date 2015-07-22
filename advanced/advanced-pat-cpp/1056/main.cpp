#include <iostream>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

int wet[1000];
int odr[1000];
int rnk[1000];
int grp[1000];
int tmp[1000];
int group_max(int grpcnt) {
	int maxi = 0;
	for (int i = 1; i < grpcnt; i++) {
		if (wet[grp[i]] > wet[grp[maxi]]) {
			maxi = i;
		}
	}
	return grp[maxi];
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int NP, NG;
	scanf("%d%d", &NP, &NG);
	for (int i = 0; i < NP; i++) {
		scanf("%d", &wet[i]);
	}
	for (int i = 0; i < NP; i++) {
		scanf("%d", &odr[i]);
	}
	int grpcnt = 0, N = NP, winner, tmpcnt, rank;
	while (N > 1) {
		tmpcnt = 0;
		rank = (N + NG - 1) / NG + 1;
		for (int i = 0; i < N; i++) {
			if (grpcnt < NG) {
				grp[grpcnt++] = odr[i];
			}
			if (grpcnt == NG || i == N-1) {
				winner = group_max(grpcnt);
				for (int i = 0; i < grpcnt; i++) {
					rnk[grp[i]] = rank;
				}
				tmp[tmpcnt++] = winner;
				grpcnt = 0;
			}
		}
		N = tmpcnt;
		memcpy(odr, tmp, N * sizeof(int));
	}
	rnk[odr[0]] = 1;
	printf("%d", rnk[0]);
	for (int i = 1; i < NP; i++) {
		printf(" %d", rnk[i]);
	}
	printf("\n");
}