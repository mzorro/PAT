#include <iostream>
using namespace std;
#pragma warning(disable:4996)

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	long G1, S1, K1, G2, S2, K2;
	char c;
	cin >> G1 >> c >> S1 >> c >> K1;
	cin >> G2 >> c >> S2 >> c >> K2;
	long K = (K1 + K2) % 29;
	long S = (S1 + S2+ (K1 + K2) / 29) % 17 ;
	long G = G1 + G2 + (S1 + S2 + (K1 + K2) / 29) / 17;
	cout << G << '.' << S << '.' << K << endl;
}