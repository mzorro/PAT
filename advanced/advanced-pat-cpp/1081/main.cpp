#include <iostream>
#include <cmath>
using namespace std;
#pragma warning(disable:4996)

struct Fraction {
	long long n, d;
	
	Fraction(long long n, long long d) : n(n), d(d) {
		simplify();
	}

	void operator+=(const Fraction &r) {
		n *= r.d;
		n += r.n * d;
		d *= r.d;
		simplify();
	}

	friend ostream& operator<<(ostream &o, const Fraction &f) {
		long long n = f.n, d = f.d;
		if (n < 0) {
			o << '-';
			n = -n;
		}
		long long i = n / d;
		n = n % d;
		if (i == 0) {
			if (n == 0) o << 0;
			else o << n << '/' << d;
		} else {
			o << i;
			if (n != 0) o << ' ' << n << '/' << d;
		}
		return o;
	}

	void simplify() {
		for (long long i = 2; i <= d && i <= abs(n); i++) {
			for (; n%i==0 && d%i==0; n/=i, d/=i);
		}
	}
};

int main() {
	//freopen("..\\input.txt", "r", stdin);
	int N;
	cin >> N;
	Fraction f = Fraction(0, 1);
	while (N--) {
		long long n, d;
		char c;
		cin >> n >> c >> d;
		f += Fraction(n, d);
	}
	cout << f << endl;
}