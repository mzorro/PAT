#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#pragma warning(disable:4996)

struct Mooncake {
	double lot;
	double price, singleprice;

	Mooncake(double lot, double price)
		: lot(lot)
		, price(price / lot) {}

	bool operator<(const Mooncake &right) const {
		return price > right.price;
	}
};

int main() {
	//freopen("..\\advanced-pat-python\\test.txt", "r", stdin);
	int N;
	double need;
	cin >> N >> need;
	double *lots = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> lots[i];
	}
	vector<Mooncake> cakes;
	double price;
	for (int i = 0; i < N; i++) {
		cin >> price;
		cakes.push_back(Mooncake(lots[i], price));
	}
	delete[] lots;
	sort(cakes.begin(), cakes.end());
	vector<Mooncake>::iterator it = cakes.begin();
	double sum = 0.0;
	while (need > 0 && it!= cakes.end()) {
		if (it->lot >= need) {
			sum += need * it->price;
			need = 0;
		} else {
			sum += it->lot * it->price;
			need -= it->lot;
		}
		it++;
	}
	cout.precision(2);
	cout << fixed << sum << endl;
}
