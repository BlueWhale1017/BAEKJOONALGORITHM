#include<iostream>
using namespace std;

int N = 0; 

void Input(void){
	cin >> N;
}
void Calculate(void) {//An+1=An+6n, A1=1 �̶�� ��ȭ������ ������ Ǯ�� �ȴ�.
	int a = 1; //Ƚ��
	int cnt = 1; //ī��Ʈ
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