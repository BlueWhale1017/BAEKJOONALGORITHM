#include<iostream>
#include<cstdlib> // abs ��
#include<algorithm> //min ��
using namespace std;

int Horizontal = 0, Vertical = 0; //����� ���μ���.
int stores = 0; //������ ��. 
int direction[101] = { 0, }; //������ ����
int Distance[101] = { 0, }; //������ ��ġ 
int Dir = 0, Dis = 0; // ������ ����� ��ġ. 
int sum = 0; // �Ÿ��� ���� ���� ����. 

void Input(void) {
	cin >> Horizontal >> Vertical;
	cin >> stores;

	for(int i=1;i<=stores;i++) {
		cin >> direction[i] >> Distance[i];
	}
	cin >> Dir >> Dis;
}
void Least(void) {
	for (int i = 1; i <= stores; i++) {
		if (direction[i] == 1) {
			if (Dir == 1) {
				sum += abs(Distance[i] - Dis);
			}
			else if (Dir == 3) {
				sum += (Dis + Distance[i]);
			}
			else if (Dir == 4) {
				sum += (Horizontal-Distance[i]+Dis);
			}
			else {//���� ���ֺ��� ���� ��. ���⼱ ����. 
				sum += min(Distance[i] + Vertical + Dis, Horizontal - Dis + Vertical + Horizontal - Distance[i]); //������ ������. 
			}
		}
		else if (direction[i] == 2) {
			if (Dir == 2) {
				sum += abs(Dis - Distance[i]);
			}
			else if (Dir == 3) {
				sum += (Vertical - Dis + Distance[i]);
			}
			else if (Dir == 4) {
				sum += (Horizontal - Distance[i] + Vertical - Dis);
			}
			else {// ���ֺ��� ��. ���⼭�� ����. 
				sum += min(Distance[i] + Vertical + Dis, Horizontal - Dis + Vertical + Horizontal - Distance[i]);
			}
		}
		else if (direction[i] == 3) {
			if (Dir == 4) {
				sum += min(Horizontal + Vertical - Dis + Vertical - Distance[i], Horizontal + Dis + Distance[i]);
			}
			else if (Dir == 3) {
				sum += abs(Dis - Distance[i]);
			}
			else if (Dir == 2) {
				sum += (Dis + Vertical - Distance[i]);
			}
			else {//Dir==1
				sum += Dis + Distance[i];
			}
		}
		else {//direction[i]==4 ����. 
			if (Dir == 4) {
				sum += abs(Dis - Distance[i]);
			}
			else if (Dir == 3) {
				sum += min(Horizontal + Vertical - Dis + Vertical - Distance[i], Horizontal + Dis + Distance[i]);
			}
			else if (Dir == 1) {
				sum += (Horizontal - Dis + Distance[i]);
			}
			else {//Dir==2
				sum += (Horizontal - Dis + Vertical - Distance[i]);
			}
		}
	}
	cout << sum << "\n";
}

int main(void) {
	Input();
	Least();
	return 0;
}
//���� ���ֺ��� ��, �Ǵ� �׷��� ���� ���� �����ؼ� ����ϴ� ���� ����Ǯ���� �ٽ�. 
//�� Ǯ�� �� ����� x, y, x1, y2 ���� ���� ���� �� ���ְ� Ǫ�°� �� ���ϴٴ� ���. �ٸ� �̹� ������ ���� �� ������ �ڵ尡 ���ϱ�� �׳� ����. -> ����. 
