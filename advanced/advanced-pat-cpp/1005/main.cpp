#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)
#define MAX_INT 0x7fffffff

string word[10] = {
	"zero", "one", "two",
	"three", "four", "five",
	"six", "seven", "eight",
	"nine",
};
int main() {
	// freopen("..\\input.txt", "r", stdin);
	string s;
	cin >> s;
	int sum = 0;
	string::iterator it = s.begin();
	for (; it != s.end(); it++) sum += *it - '0';
	stringstream ss;
	ss << sum;
	s = ss.str();
	it = s.begin();
	cout << word[*it - '0'];
	for (it++; it != s.end(); it++) {
		cout << ' ' << word[*it - '0'];
	}
	cout << endl;
}