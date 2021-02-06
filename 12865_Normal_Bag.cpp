#include<iostream>
#include<algorithm>
//#include<vector>
using namespace std;

int N = 0, K = 0;
int W[101] = { 0, }, V[101] = { 0, }; //N의 한계인 100이 최대. 0은 비워놓음. 
int Bag[101][100001] = { 0, };// Bag[N번째 물건까지의, N번째 물건의 무게까지 고려한]== ~의 가치 총합. 
//vector<pair<int, int>> weight_value; W, V를 이런식으로도 표현 가능. 

void Input(void) {//N은 물품의 수, K는 들 수 있는 무게의 합. W는 각 물건의 weight, V는 각 물건의 Value. 
	cin >> N >> K;
	for(int i=1;i <= N;i++) {
		cin >> W[i] >> V[i];
	}//입력 끝. 
}
void DP(void) {
	for (int i = 1; i <= N; i++) {//물체의 수.
		for (int j = 0; j <=K; j++) {//무게. 
			if (i == 1) {
				if (W[i] <= j) {
					Bag[i][j] = V[i];
					continue;
				}
			}
			else if (W[i] <= j) Bag[i][j] = max(Bag[i - 1][j], V[i] + Bag[i - 1][j - W[i]]); //가장 중요한 점화식. 사실상 DP의 핵심. 
			else Bag[i][j] = Bag[i - 1][j];
		}
	}
	cout<< Bag[N][K]<<"\n"; //출력 끝. 
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //시간 절약 
	Input(); // 입
	DP();// 출
	return 0; //끝! 
}
/*브루트 포스를 사용하려고 시도. (실패함) 
int w_sum[1001] = { 0, }, v_sum[1001] = { 0, };
int Product[101][2] = { 0, }; //물건. 무게와 가치. 
int Max = 0;
void Calculate(int i) {
	if (w_sum[i] <= K) {
		if (Max < v_sum[i]) {
			Max = v_sum[i];
		}
	}
}
//조합들의 합. Input 에서 4개의 인자가 들어옴. nCn+...+nC1(무게로 조건먼저 확인, 그다음 가치평가)
int combination(int n, int r) { //재귀로 조합 구현. 
	if (n == r || r == 0) return 1;
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}
*/
