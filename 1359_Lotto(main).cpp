#include "1359_Lotto(header).h"

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	cout << fixed;
	cout.precision(9);

	cout<<Probability(N, M, K)<<endl;
	return 0;
}






