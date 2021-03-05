#include<iostream>
using namespace std;
#define MAX 29
#define endl "\n"

struct pos {
	int y, x;
};

int N = 0;
double dir[4] = { 0, }, Result = 0;
bool Visited[MAX][MAX];
int dy[4] = { 0,0,1,-1 }, dx[4] = { -1,1,0,0 };

void DFS(int y, int x, int depth, double percentage) {
	if (depth == N) {
		Result += percentage;
		return;
	}

	Visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!Visited[ny][nx]) {
			DFS(ny, nx, depth + 1, percentage*dir[i]);
		}
	}
	Visited[y][x] = false;
}
void Input() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		cin >> dir[i];
		dir[i] = dir[i] / 100;
	}
}
int main() {
	Input();
	DFS(15, 15, 0, 1.0);
	cout << fixed;
	cout.precision(10);
	cout << Result << endl;
	return 0;
}
