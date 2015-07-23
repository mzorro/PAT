#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int N, M, K;
struct Student {
	int GE, GI, id;
	vector<int> preferred;
	Student() : preferred(vector<int>(K)), GE(-1), GI(-1) {}

	bool operator<(const Student &right) const {
		if (GE + GI > right.GE + right.GI) return true;
		else if (GE + GI == right.GE + right.GI) {
			if (GE > right.GE) return true;
			else return false;
		} else return false;
	}

	bool operator==(const Student &right) const {
		return (GE == right.GE) && (GI == right.GI);
	}
};

int main() {
	// freopen("..\\input.txt", "r", stdin);
	scanf("%d%d%d", &N, &M, &K);
	vector<int> capacity = vector<int>(M);
	vector<vector<int> > accepted = vector<vector<int> >(M, vector<int>());
	vector<Student> lastStu = vector<Student>(M);
	vector<Student> stus = vector<Student>(N);
	for (int i = 0; i < M; i++) scanf("%d", &capacity[i]);
	for (int i = 0; i < N; i++) {
		stus[i].id = i;
		scanf("%d%d", &stus[i].GE, &stus[i].GI);
		for (int j = 0; j < K; j++) scanf("%d", &stus[i].preferred[j]);
	}

	sort(stus.begin(), stus.end());

	vector<Student>::iterator last, it;
	last = stus.end(); it = stus.begin();
	for (; it != stus.end(); it++) {
		for (int i = 0; i < K; i++) {
			int s = it->preferred[i];
			if (capacity[s] > 0 || lastStu[s] == *it) {
				accepted[s].push_back(it->id);
				lastStu[s] = *it;
				capacity[s]--;
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		sort(accepted[i].begin(), accepted[i].end());
		vector<int>::iterator it = accepted[i].begin();
		if (it != accepted[i].end()) {
			printf("%d", *it);
			for (it++; it != accepted[i].end(); it++) {
				printf(" %d", *it);
			}
		}
		printf("\n");
	}
}