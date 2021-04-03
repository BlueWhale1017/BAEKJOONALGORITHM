#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 102
using namespace std;

int N = 0;

int height = 0;
int height_record[MAX][MAX] = { 0, };

bool Visited[MAX][MAX] = { false, };

int rain_height = 0;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int Next = 0;
int Count = 0;
int check = 0;

void Input();
void Safety_Area(int rain_height);
void DFS(int y, int x, int rain_height);
void Rain_UP();
void Clearvis();

int main() {
	Input();
	Rain_UP();
	cout<<Next;
	return 0;
}

void Input() {
	cin >> N; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> height;
			height_record[i][j] = height;
		}
	}
}
void DFS(int y, int x, int rain_height) {
	if (Visited[y][x] == true || height_record[y][x] <= rain_height) {
		return;
	}
	Visited[y][x] = true;
	check++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//DFS(ny, nx); 이걸로 아래 대체해도 될듯함. 
		if (!Visited[ny][nx]) {
			DFS(ny, nx, rain_height);
		}
	}
}
void Safety_Area(int rain_height) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			DFS(i, j, rain_height);
			if (check) {
				Count++;
				check = 0;
			}
		}
	}
}
void Rain_UP() {
	for (int rain_height = 0; rain_height <=100 ; rain_height++) {//height의 값 중 최대치를 받는 게 맞지만 임의로 100을 정했습니다. 
		Safety_Area(rain_height);
		Next=max(Next, Count);
		Count = 0;
		//Visited[MAX][MAX] = { false, };
		Clearvis();
	}
}
void Clearvis() {
	for (int i = 1; i <= N; i++) {
		memset(*(Visited + i) + 1, false, N * sizeof(bool));
	}
}


