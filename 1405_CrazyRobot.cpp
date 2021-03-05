#include<iostream>
#define MAX 30
#define endl "\n"
using namespace std;

int N = 0;
double Percent[4] = { 0, }; //��������. 
double Result = 0.0; //�����. 

bool Visit[MAX][MAX] = { 0, };//14+1+14

int dy[4] = { 0,0,1,-1 };//��������. 
int dx[4] = { -1,1,0,0 };

void Input() {
	cin >> N; //�̸�ŭ�� �ൿ�� ��.
	int a = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		Percent[i] = a / 100.0; //��������. 
	}
}
double Probability(int startY, int startX, int Cnt) {//dfs function
	if (Cnt == N) return 1; 

	Visit[startY][startX] = true;

	for (int i = 0; i < 4; i++) {//���������� ���� �湮�ϰ�, �ܼ��� ��� ������ Ȯ���� ���� �߰ߵ� �ܼ��� ����� Ȯ���� ���Ѵ�. ������ N������. 
		int nx = startX + dx[i];
		int ny = startY + dy[i];

		if (Visit[ny][nx] == true) continue; //�ܼ��� ��츦 ã�� �ֱ⿡, �̹� �湮�� ������ ��� Ȯ���� ������ �ʴ´�. 

		Result = Result + Percent[i] * Probability(ny, nx, Cnt + 1); //���� ���ǹ����� �ɷ����� ���� ���, �ܼ��� ����̱⿡ Ȯ���� ���Ѵ�. 
	}
	Visit[startY][startX] = false;
	return Result;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Input();
	cout<<fixed;
	cout.precision(10);
	cout<<Probability(15, 15, 0)<<endl; //(15,15) �ʱ���ǥ(0�� �����ϱ⿡), 0�� �ݺ�Ƚ��. N����ŭ �ݺ��ϸ� ����ȴ�.
	return 0;
}