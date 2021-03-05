#include<iostream>
using namespace std;
#define MAX 29
#define endl "\n"

int Visited[MAX][MAX] = { 0, };
int dy[4] = { 0,0,1,-1 }, dx[4] = { 1,-1,0,0 };
int k = 2;

int main() {
	Visited[14][14] = 1;
	for (int i = 0; i < 4; i++) {
		Visited[14 + dy[i]][14+dx[i]] = k;
		k++;
	}

	for (int i = 0; i < 29; i++) {
		for (int j = 0; j < 29; j++) {
			cout << Visited[i][j] << " ";
			if (j == 28) cout << endl;
		}
	}
	return 0;
}
