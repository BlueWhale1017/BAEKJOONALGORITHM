#include "1359_Lotto(header).h"

double Probability(int n, int m, int k) {
	double nCm = 0;
	double mCk_sigma = 0;

	if (n - m < m - k) {
		return 1; 
	}

	nCm = Factorial(n) / (Factorial(n - m) * Factorial(m));

	for (int i = k; i <= m; i++) {
		mCk_sigma += Factorial(m) / (Factorial(m - i) * Factorial(i));
	}

	return mCk_sigma / nCm;
}

int Factorial(int num) {
	if (num <= 1) return 1;

	return num * Factorial(num - 1);
}


