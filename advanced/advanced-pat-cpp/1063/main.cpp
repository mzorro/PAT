#include <iostream>
#include <set>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	vector<set<int> > sets(N);
	for (int i = 0; i < N; i++) {
		int n, tmp;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &tmp);
			sets[i].insert(tmp);
		}
	}
	int Q, i, j;
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d", &i, &j);
		i--, j--;
		if (sets[i].size() > sets[j].size()) {
			swap(i, j);
		}
		int Nc = 0;
		for (auto n: sets[i]) {
			if (sets[j].find(n)!=sets[j].end()) {
				Nc++;
			}
		}
		int Nt = sets[i].size() + sets[j].size() - Nc;
		printf("%.1f%%\n", double(Nc)/Nt*100);
	}
}