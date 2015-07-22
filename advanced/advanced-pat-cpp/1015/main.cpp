#include <iostream>
using namespace std;

bool isPrime(int num) {
	if(num==0 || num==1)
		return false;
	for(int i=2;i<num;i++)
		if(num % i == 0)
			return false;
	return true;
}

int main() {
	while(true) {
		int num;
		cin >> num;
		if(num < 0)	break;
		int redix;
		cin >> redix;
		int numr = 0;
		int tmp = num;
		while(tmp > 0) {
			numr *= redix;
			numr += tmp % redix;
			tmp /= redix;
		}
		if(isPrime(num) && isPrime(numr))
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}
}