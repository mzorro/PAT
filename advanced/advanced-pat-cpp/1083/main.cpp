#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#pragma warning(disable:4996)

struct Student {
	string name, id;
	int grade;

	bool operator<(const Student &r) const {
		return grade >= r.grade;
	}

	friend istream& operator>>(istream &in, Student &r) {
		return in >> r.name >> r.id >> r.grade;
	}

	friend ostream& operator<<(ostream &out, const Student &r) {
		return out << r.name << ' '  << r.id;
	}
};

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N; cin >> N;
	vector<Student> stus = vector<Student>(N);
	while (N--) {
		cin >> stus[N];
	}
	sort(stus.begin(), stus.end());

	int low, high;
	cin >> low >> high;
	vector<Student>::iterator it = stus.begin();
	bool hasAny = false;
	for (; it != stus.end(); it++) {
		if (it->grade >= low && it->grade <= high) {
			hasAny = true;
			cout << *it << endl;
		}
	}
	if (!hasAny) cout << "NONE" << endl;
}