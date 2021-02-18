#include<iostream>
#include<cstdlib> // abs 용
#include<algorithm> //min 용
using namespace std;

int Horizontal = 0, Vertical = 0; //블록의 가로세로.
int stores = 0; //상점의 수. 
int direction[101] = { 0, }; //상점의 방향
int Distance[101] = { 0, }; //상점의 위치 
int Dir = 0, Dis = 0; // 경비원의 방향과 위치. 
int sum = 0; // 거리의 합을 위한 변수. 

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
			else {//서로 마주보는 변일 때. 여기선 남쪽. 
				sum += min(Distance[i] + Vertical + Dis, Horizontal - Dis + Vertical + Horizontal - Distance[i]); //복붙이 가능함. 
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
			else {// 마주보는 변. 여기서는 북쪽. 
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
		else {//direction[i]==4 동쪽. 
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
//서로 마주보는 변, 또는 그렇지 않을 때를 구분해서 계산하는 것이 문제풀이의 핵심. 
//다 풀고 안 사실은 x, y, x1, y2 굳이 따로 선언 안 해주고 푸는게 더 편하다는 사실. 다만 이미 선언해 놓은 것 때문에 코드가 꼬일까봐 그냥 놔둠. -> 지움. 
