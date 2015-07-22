#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

int age_min, age_max;
inline bool age_in_range(int age) {
	if (age >= age_min && age <= age_max) {
		return true;
	}
	return false;
}

struct People {
	char name[9];
	int age, worth;

	inline void scan() {
		scanf("%s%d%d", name, &age, &worth);
	}

	inline void print() const {
		printf("%s %d %d\n", name, age, worth);
	}

	inline bool operator<(const People &p) const {
		if (worth != p.worth) {
			return worth > p.worth;
		} else {
			if (age != p.age) {
				return age < p.age;
			} else {
				return strcmp(name, p.name) < 0;
			}
		}
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N, Q;
	scanf("%d%d", &N, &Q);
	vector<People> people(N);
	for (int i = 0; i < N; i++)  {
		people[i].scan();
	}
	sort(people.begin(), people.end());
	int age_cnt[205];
	memset(age_cnt, 0, sizeof(age_cnt));
	int people_index[20005], len = 0;
	for (int i = 0; i < N; i++) {
		if (age_cnt[people[i].age] < 100) {
			people_index[len++] = i;
			age_cnt[people[i].age]++;
		}
	}
	for (int i = 1; i <= Q; i++) {
		printf("Case #%d:\n", i);
		scanf("%d%d%d", &N, &age_min, &age_max);
		int cnt = 0;
		for (int i = 0; i < len && cnt < N; i++) {
			if (age_in_range(people[people_index[i]].age)) {
				people[people_index[i]].print();
				cnt++;
			}
		}
		if (cnt == 0) {
			printf("None\n");
		}
	}
}