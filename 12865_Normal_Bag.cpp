#include<iostream>
#include<algorithm>
//#include<vector>
using namespace std;

int N = 0, K = 0;
int W[101] = { 0, }, V[101] = { 0, }; //N�� �Ѱ��� 100�� �ִ�. 0�� �������. 
int Bag[101][100001] = { 0, };// Bag[N��° ���Ǳ�����, N��° ������ ���Ա��� �����]== ~�� ��ġ ����. 
//vector<pair<int, int>> weight_value; W, V�� �̷������ε� ǥ�� ����. 

void Input(void) {//N�� ��ǰ�� ��, K�� �� �� �ִ� ������ ��. W�� �� ������ weight, V�� �� ������ Value. 
	cin >> N >> K;
	for(int i=1;i <= N;i++) {
		cin >> W[i] >> V[i];
	}//�Է� ��. 
}
void DP(void) {
	for (int i = 1; i <= N; i++) {//��ü�� ��.
		for (int j = 0; j <=K; j++) {//����. 
			if (i == 1) {
				if (W[i] <= j) {
					Bag[i][j] = V[i];
					continue;
				}
			}
			if (W[i] <= j) Bag[i][j] = max(Bag[i - 1][j], V[i] + Bag[i - 1][j - W[i]]); //���� �߿��� ��ȭ��. ��ǻ� DP�� �ٽ�. 
			else Bag[i][j] = Bag[i - 1][j];
		}
	}
	cout<< Bag[N][K]<<"\n"; //��� ��. 
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //�ð� ���� 
	Input(); // ��
	DP();// ��
	return 0; //��! 
}
/*���Ʈ ������ ����Ϸ��� �õ�. (������) 
int w_sum[1001] = { 0, }, v_sum[1001] = { 0, };
int Product[101][2] = { 0, }; //����. ���Կ� ��ġ. 
int Max = 0;
void Calculate(int i) {
	if (w_sum[i] <= K) {
		if (Max < v_sum[i]) {
			Max = v_sum[i];
		}
	}
}
//���յ��� ��. Input ���� 4���� ���ڰ� ����. nCn+...+nC1(���Է� ���Ǹ��� Ȯ��, �״��� ��ġ��)
int combination(int n, int r) { //��ͷ� ���� ����. 
	if (n == r || r == 0) return 1;
	else {
		return combination(n - 1, r - 1) + combination(n - 1, r);
	}
}
*/