#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Station {
	double dist, price;

	Station(double price, double dist)
		: price(price), dist(dist) {}

	inline bool operator<(const Station &s) const {
		return dist < s.dist;
	}
};

template <typename T>
inline T fmin(const T d1, const T d2) {
	return d1 < d2 ? d1 : d2;
}

int main() {
	double cmax, dest, davg;
	int N;
	cin >> cmax >> dest >> davg >> N;
	vector<Station> stations;
	double price, dist;
	while (N--) {
		cin >> price >> dist;
		stations.push_back(Station(price, dist));
	}
	N = stations.size();
	// destination
	stations.push_back(Station(-1, dest));
	sort(stations.begin(), stations.end());
	int cur_stop = 0;
	double cur_gas = 0, cost = 0;
	if (stations[cur_stop].dist > 0) {
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	const double step = cmax * davg; // max step
	while (cur_stop < N) {
		int next_stop = -1;
		const double cur_dist = stations[cur_stop].dist;
		const double cur_price = stations[cur_stop].price;
		bool need_full = true;
		for (int s=cur_stop+1; s<=N; s++) {
			if (stations[s].dist - cur_dist > step) {
				break;
			}
			if (stations[s].price < cur_price) {
				need_full = false;
				next_stop = s;
				break;
			}
			if (next_stop == -1 ||
				stations[s].price < stations[next_stop].price) {
				next_stop = s;
			}
		}
		double need_gas;
		if (next_stop == -1) {
			cout << "The maximum travel distance = "
				<< setprecision(2) << fixed
				<< cur_dist + step << endl;
			return 0;
		}
		need_gas = (stations[next_stop].dist - cur_dist) / davg;
		cost += ((need_full ? cmax : need_gas) - cur_gas) * cur_price;
		cur_gas = need_full ? cmax - need_gas : 0;
		cur_stop = next_stop;
	}
	cout << setprecision(2) << fixed << cost << endl;
}