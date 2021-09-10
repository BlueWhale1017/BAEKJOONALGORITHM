#include<iostream>
using namespace std;
#define max 1000+1

int n = 0;
int arr[max][6] = { 0, };
bool visited[max][max] = { false, };
int answer = 0;

void input();
void calculate();
bool checked(int i, int r);
int output();

int main() {
	input();//input finished. 
	calculate();
	output();
}
int output() {
	for (int i = 1; i <= n; i++) {
		if (arr[i][0] == answer) {
			cout << i;
			return 0;
		}
	}
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[i][0] = -1;//��� +1�� �Ǳ⿡ -1���� ������. �׷� +1�� �Ǿ 0���� ����. 
	}//for the sum. 
}
void calculate() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int r = 1; r <= n; r++) {
				if (arr[i][j] == arr[r][j] && checked(i, r)) {//�ڱ� �ڽŰ��� ������ ������ +1�� ������. �� ��� �����ϰ� ����ǰ� �����̱⿡ ������. 
					arr[i][0] += 1;
					visited[i][r] = true; 
				}
			}
		}
	}
	answer = arr[1][0];
	for (int i = 2; i <= n; i++) {
		answer = answer < arr[i][0] ? arr[i][0] : answer; //���� ��� ���� ���� ���� �ؾ��ϱ⿡ <�� �����. 
	}
}

bool checked(int i, int r) { 
	if (visited[i][r] == true) {
		return false;
	}
	else return true;
}


//����
// ��ɺ� ����
// �˰��� ����
// �������� ���� 
// ���� �и�
//ȿ���� ����
//������ ����
//Ȱ�뼺 ����

