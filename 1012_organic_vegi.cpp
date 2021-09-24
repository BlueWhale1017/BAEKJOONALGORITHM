#include<iostream>
#define MAX 50+1
using namespace std;

int T, M, N, K;
bool arr[MAX][MAX] = { false, };

void dfs(int i, int j);
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		//start
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			int y, x; 
			cin >> x >> y;
			arr[y][x]=true;
		}
		int dragon = 0;//지렁이. 
		for (int k = 0; k < N; k++) {//가로가 M, 세로가 N. 
			for (int p = 0; p < M; p++) {
				if (arr[k][p] == true) {
					//연결된 모든 지점을 방문하면서 true로 바꾸고 마지막에 dragon을 +1 한다. 
					dfs(k, p);
					dragon += 1;
				}
			}
		}
		cout << dragon << '\n';
		//end
	}
	return 0;
}

void dfs(int i, int j) {
	if (arr[i][j] == false || (i<0) || (i>=MAX) || (j<0) || (j>=MAX)) return;
	arr[i][j] = false;
	for (int k = 0; k < 4; k++) {
		dfs(i + dy[k], j + dx[k]);
	}
}


