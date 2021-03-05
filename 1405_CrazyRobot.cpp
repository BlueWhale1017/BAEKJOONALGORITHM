#include<iostream>
#define MAX 30
#define endl "\n"
using namespace std;

int N = 0;
double Percent[4] = { 0, }; //동서남북. 
double Result = 0.0; //결과값. 

bool Visit[MAX][MAX] = { 0, };//14+1+14

int dy[4] = { 0,0,1,-1 };//동서남북. 
int dx[4] = { -1,1,0,0 };

void Input() {
	cin >> N; //이만큼의 행동을 함.
	int a = 0;
	for (int i = 0; i < 4; i++) {
		cin >> a;
		Percent[i] = a / 100.0; //동서남북. 
	}
}
double Probability(int startY, int startX, int Cnt) {//dfs function
	if (Cnt == N) return 1; 

	Visit[startY][startX] = true;

	for (int i = 0; i < 4; i++) {//동서남북을 각각 방문하고, 단순할 경우 기존의 확률에 새로 발견된 단순한 경우의 확률을 더한다. 덧셈은 N번까지. 
		int nx = startX + dx[i];
		int ny = startY + dy[i];

		if (Visit[ny][nx] == true) continue; //단순한 경우를 찾고 있기에, 이미 방문한 지점의 경우 확률을 더하지 않는다. 

		Result = Result + Percent[i] * Probability(ny, nx, Cnt + 1); //위의 조건문에서 걸러지지 않은 경우, 단순한 경우이기에 확률을 더한다. 
	}
	Visit[startY][startX] = false;
	return Result;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Input();
	cout<<fixed;
	cout.precision(10);
	cout<<Probability(15, 15, 0)<<endl; //(15,15) 초기좌표(0을 포함하기에), 0은 반복횟수. N번만큼 반복하면 종료된다.
	return 0;
}