#include<iostream>
using namespace std;

int Factorial(int num) {
	if (num <= 1) return 1;

	return num * Factorial(num - 1);
}


int main() {
	int n, m, k;
	cin >> n >> m >> k;

	double res = 0;
	double p = Factorial(n)/(Factorial(n-m)*Factorial(m));

	while (m >= k) {
		if (n - m < m - k) {
			k++;
			continue;
		}
		double c = Factorial(m) / (Factorial(m - k) * Factorial(k)) * Factorial(n - m) / (Factorial(n - m - (m - k)) * Factorial(m - k));
		res += c / p;
		k++;
	}
	cout << fixed;
	cout.precision(9);
	cout << res;
	return 0;
}


