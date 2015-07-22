#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int name2int(char name[5]) {
	return (name[0] - 'A') * 26 * 26 * 10
			+ (name[1] - 'A') * 26 * 10
			+ (name[2] - 'A') * 10
			+ (name[3] - '0');
}

vector<int> stu[180000];
vector<int> course[2600];

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, K;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		int C, M;
		scanf("%d%d", &C, &M);
		while (M--) {
			char name[5];
			scanf("%s", name);
			course[C].push_back(name2int(name));
		}
	}
	for (int i = 1; i <= K; i++) {
		vector<int>::iterator it = course[i].begin();
		while (it!=course[i].end()) {
			stu[*(it++)].push_back(i);
		}
	}
	while (N--) {
		char name[5];
		scanf("%s", name);
		printf("%s ", name);
		int index = name2int(name);
		if (stu[index].empty()) {
			printf("0");
		} else {
			printf("%d", stu[index].size());
			vector<int>::iterator it = stu[index].begin();
			while (it!=stu[index].end()) {
				printf(" %d", *(it++));
			}
		}
		printf("\n");
	}
}