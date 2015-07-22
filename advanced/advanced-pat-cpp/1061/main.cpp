#include <iostream>
#include <string>
using namespace std;
#pragma warning(disable:4996)

char * const weekdays[7] = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int weekday, hour, minutes;
	auto it1 = s1.begin(), it2 = s2.begin();
	while (it1 != s1.end() && it2 != s2.end()) {
		if (*it1==*it2 && *it1 >= 'A' && *it1 <='G') {
			weekday = *it1 - 'A';
			break;
		}
		it1++, it2++;
	}
	it1++, it2++;
	while (it1 != s1.end() && it2 != s2.end()) {
		if (*it1==*it2 && *it1 >= 'A' && *it1 <='N') {
			hour = *it1 - 'A' + 10;
			break;
		} else if (*it1==*it2 && isdigit(*it1)) {
			hour = *it1 - '0';
			break;
		}
		it1++, it2++;
	}
	auto it3 = s3.begin(), it4 = s4.begin();
	while (it3 != s3.end() && it4 != s4.end()) {
		if (*it3==*it4 && isalpha(*it3)) {
			minutes = it3 - s3.begin();
			break;
		}
		it3++, it4++;
	}
	cout << weekdays[weekday] << ' ';
	cout.width(2);
	cout.fill('0');
	cout << hour << ':';
	cout.width(2);
	cout.fill('0');
	cout << minutes << endl;
}