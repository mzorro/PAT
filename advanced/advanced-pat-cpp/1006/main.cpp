#include <iostream>
#include <string>
#include <set>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

struct Person {
	string id, time;
	Person(string id, string time) : id(id), time(time) {}
	bool operator<(Person const &r) const {
		return time < r.time;
	}
};

int main() {
	// freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N; cin >> N;
	set<Person> signin, signout;
	string id, in, out;
	while (N--) {
		cin >> id >> in >> out;
		signin.insert(Person(id, in));
		signout.insert(Person(id, out));
	}
	cout << signin.begin()->id << ' '
		<< signout.rbegin()->id << endl;
}