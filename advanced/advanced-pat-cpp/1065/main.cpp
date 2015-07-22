#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cout << "Case #" << i << ": ";
		long long A, B, C;
		cin >> A >> B >> C;
		bool res;
		if (A > 0 && B > 0 && A + B < A)
			res = true;
		else if (A < 0 && B < 0 && A + B > A) 
			res = false;
		else res = (A + B) > C;
		if (res) cout << "true";
		else cout << "false";
		cout << endl;
	}
}