#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, C;
struct Record {
	char id[7], name[9];
	int score;

	void inline input() {
		cin >> id >> name >> score;
	}

	void inline print() {
		cout << id << ' ' << name << ' ' << score << '\n';
	}

	bool operator<(const Record& record) const {
		switch (C) {
		case 1:
			return strcmp(id, record.id) < 0;
		case 2:
			if (0==strcmp(name, record.name)) {
				return strcmp(id, record.id) < 0;
			} else {
				return strcmp(name, record.name) < 0;
			}
		case 3:
			if (score == record.score) {
				return strcmp(id, record.id) < 0;
			} else {
				return score < record.score;
			} 
		}
	}
};

void apply(vector<Record> &records, void (Record::*func)()) {
	for (int i = 0; i < N; i++) {
		(records[i].*func)();
	}
}

int main() {
	cin >> N >> C;
	vector<Record> records(N);
	apply(records, &Record::input);
	sort(records.begin(), records.end());
	apply(records, &Record::print);
}