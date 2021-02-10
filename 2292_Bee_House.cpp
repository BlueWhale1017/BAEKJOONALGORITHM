#include<iostream>
using namespace std;

int N = 0; 

void Input(void){
	cin >> N;
}
void Calculate(void) {//An+1=An+6n, A1=1 이라는 점화식으로 문제를 풀면 된다.
	int a = 1; //횟수
	int cnt = 1; //카운트
	for (int n = 1; n <= N; n++) {
		if (N<=a) {
			cout << cnt << "\n";
			break;
		}
		else {
			a = a + 6 * n;
			cnt++;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Input();
	Calculate();
	return 0;
}