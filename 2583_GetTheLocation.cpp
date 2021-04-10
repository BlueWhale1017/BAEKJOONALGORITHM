#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

#define MAX 102
vector <int> vec;

int N=0, M=0, K=0; //가로세로개수 
int CNT = 0;
int arr[MAX][MAX] = { 0, };
bool Visited[MAX][MAX] = { false, };
int X_left=0, Y_left=0, X_right=0, Y_right=0;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void Efficiency();
void Input();
void Calculate();
void DFS(int y, int x);
void Output();

int main() {
	Efficiency();
	Input();
	Calculate();
	Output();
	return 0;
}
void DFS(int y, int x) {
	Visited[y][x] = true;
	CNT++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (arr[ny][nx] == 0 && !Visited[ny][nx]) {
			DFS(ny, nx);
		}
	}
}
void Calculate() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 0 && !Visited[i][j]) {
				CNT = 0;
				DFS(i, j);
				vec.push_back(CNT);
			}
		}
	}
}
void Output() {
	sort(vec.begin(), vec.end());
	cout << vec.size() << endl;
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
}
void Input() {
	cin >> M >> N >> K;
	while (K--) {
		cin >> X_left >> Y_left >> X_right >> Y_right;
		for (int i = Y_left; i < Y_right; i++) {
			for (int j = X_left; j < X_right; j++) {
				arr[i][j] = 1;
				Visited[i][j] = true;
			}
		}
	}
}
void Efficiency() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
}




