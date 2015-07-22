#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int coins[10005];
int pack[10005][205];
bool chosed[10005][205];

bool cmp(int a1, int a2) {
	return a1 > a2; 
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> coins[i];
	}
	sort(coins + 1, coins + N + 1, cmp);
	memset(chosed, 0, sizeof(chosed));
	memset(pack, 0, sizeof(pack));
	for (int i = 1; i <= N; i++) {
		for (int v = 1; v <= M; v++) {
			pack[i][v] = pack[i-1][v];
			if (v >= coins[i]) {
				int tmp = pack[i-1][v - coins[i]] + coins[i];
				if (tmp >= pack[i-1][v]) {
					pack[i][v] = tmp;
					chosed[i][v] = true;
				}
			}
		}
	}
	if (pack[N][M] == M) {
		int i = N, j = M;
		while(!chosed[i--][j]);
		cout << coins[++i];
		while (i > 0) {
			j -= coins[i];
			while(i > 0 && !chosed[--i][j]);
			if (i > 0) cout << ' ' << coins[i];
		}
	} else {
		cout << "No Solution" << endl;
	}
}