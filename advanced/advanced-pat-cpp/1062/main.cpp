#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

struct People {
	char id[10];
	int v, t;

	People(char id[10], int v, int t)
		: v(v), t(t) {
		strcpy(this->id, id);
	}

	bool operator<(const People &p) const {
		if (v + t == p.v + p.t) {
			if (v==p.v) {
				return strcmp(id, p.id) < 0;
			} else {
				return v > p.v;
			}
		} else {
			return v + t > p.v + p.t;
		}
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, L, H;
	scanf("%d%d%d", &N, &L, &H);
	char id[10];
	int v, t, cnt = 0;
	vector<People> people[4];
	while (N--) {
		scanf("%s%d%d", id, &v, &t);
		if (v < L || t < L) continue;
		People p = People(id, v, t);
		if (v >= H && t >= H) {
			people[0].push_back(p);
		} else if (v >= H) {
			people[1].push_back(p);
		} else if (t < H && v >= t) {
			people[2].push_back(p);
		} else {
			people[3].push_back(p);
		}
		cnt++;
	}
	printf("%d\n", cnt);
	for (auto &pp: people) {
		sort(pp.begin(), pp.end());
		for (auto &p: pp) {
			printf("%s %d %d\n", p.id, p.v, p.t);
		}
	}
}