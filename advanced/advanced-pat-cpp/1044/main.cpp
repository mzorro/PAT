#include <cstdio>
#include <vector>
using namespace std;
#pragma warning(disable:4996)
s
void get_options(vector<int> &chain, int N, int M,
				 vector<pair<int, int> > &options) {
	int beg = 0, cur = 0, cost = chain[beg], min_cost = -1;
	while (beg < N && cur < N) {
		if (cost >= M) {
			if (min_cost < 0 || cost <= min_cost) {
				if (cost < min_cost) options.clear();
				min_cost = cost;
				options.push_back(pair<int, int>(beg+1, cur+1));
			}
		}
		if (cost == M) {
			cost = cost + chain[++cur] - chain[beg++];
		} else if (cost > M) {
			cost -= chain[beg++];
		} else {
			cost += chain[++cur];
		}
	}
}

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, M;
	scanf("%d%d", &N, &M);
	vector<int> chain(N+1, 0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &chain[i]);
	}
	vector<pair<int, int> > options;
	get_options(chain, N, M, options);
	vector<pair<int, int> >::iterator it = options.begin();
	while (it!=options.end()) {
		printf("%d-%d\n", it->first, it->second);
		++it;
	}
}