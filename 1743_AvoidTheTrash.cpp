#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 103

int N = 0, M = 0; //세로 가로. 
int K = 0;
int Map[MAX][MAX] = { 0, }; //쓰레기가 있다 or 없다. 
int r = 0, c = 0;
int trash = 0;
bool Check[MAX][MAX] = { false, }; // 방문했다 or 안했다. 
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void Input();
void DFS_Trash(int y, int x);
void Sum();
int Compare(int sum, int trash);

int main() {
	Input();
	Sum();
	return 0;
}
void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		Map[r][c]=1;
	}
}
void DFS_Trash(int y, int x) {
	if (Check[y][x] == true || Map[y][x] == 0) {
		return;
	}
	trash += 1;
	Check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		//DFS_Trash(ny,nx);
		if (!Check[ny][nx]) {
			DFS_Trash(ny, nx);
		}
	}
}
void Sum() {
	int Next = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DFS_Trash(i, j);
			Next = Compare(Next, trash);
			trash = 0;
		}
	}
	cout<<Next;
}
int Compare(int sum, int trash) {
	return max(sum, trash);
}
