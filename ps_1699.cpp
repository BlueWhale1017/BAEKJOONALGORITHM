#include <iostream>
#include <algorithm>

using namespace std;
int dp[100001];

int main() {

	int N;
	cin>>N;

	for (int i = 0; i <= N; i++) {
		dp[i] = i; //모두 1^2으로 구성되어 있다고 가정한다. 예시) 7=1^2*7 
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j * j <= i; j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);//i==36일 경우, 36-1, 36-4, 36-9, 36-16, 36-25 다 해보고 가장 작은 것을 출력. 
		}
	}

	cout << dp[N];

	return 0;
}



