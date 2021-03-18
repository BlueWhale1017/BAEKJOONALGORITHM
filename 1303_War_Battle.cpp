#include<iostream>
#include<cmath>
using namespace std;
#define endl '\n'
#define MAX 103

int N = 0, M = 0; char Color; int powerW = 0, powerB = 0; int numW = 0, numB = 0;
bool Check_B[MAX][MAX] = { false, };
bool Check_W[MAX][MAX] = { false, };
char Map[MAX][MAX] = {0, };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void Input();//prototpyes
void DFS_W(int x, int y);
void DFS_B(int x, int y);
void NumB();
void NumW();

int main(void) {
	Input();
	NumB();
	NumW();
	cout<<powerW<<" "<<powerB;
	return 0;
}
void NumW() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			DFS_W(i, j);
			powerW += pow(numW, 2);
			numW = 0;
		}
	}
}
void NumB() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			DFS_B(i, j);
			powerB += pow(numB, 2);
			numB = 0;
		}
	}
}
void Input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Color;
			Map[i][j] = Color;
		}
	}
}
void DFS_W(int y, int x) {
	if (Map[y][x]!='W' || Check_W[y][x]) {
		return;
	}
	numW += 1;
	Check_W[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!Check_W[ny][nx]) {
			DFS_W(ny, nx);
		}
	}
}
void DFS_B(int y, int x) {
	if (Map[y][x] != 'B' || Check_B[y][x]) {
		return;
	}
	numB += 1;
	Check_B[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (!Check_B[ny][nx]) {
			DFS_B(ny, nx);
		}
	}
}

/*
void DFS(int y, int x, int depth, double percentage) {
	if (depth == N) {
		Result += percentage;
		return;
	}

	Visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!Visited[ny][nx]) {
			DFS(ny, nx, depth + 1, percentage * dir[i]);
		}
	}
	Visited[y][x] = false;
}*/