#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
const int MAX = 10000; //#define MAX=10000
vector<int> v[MAX]; // 링크드리스트로 동적할당을 하기 위해 선언. 
bool check[101] = { false, }; //dfs 상에서 방문했나 안했나를 체크

int dfs(int u, int count) { 
	check[u] = true;
	int vsize = v[u].size();
	for (int i = 0; i < vsize; i++) {
		int next = v[u][i];
		if (!check[next]) {
			count++;
			count=dfs(next, count);
		}
	}
	return count;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, a, b = 0; cin >> N; cin >> M; // a,b 는 컴퓨터, N은 컴퓨터의 개수, M은 컴퓨터들끼리 연결되어 있는 경우의 수. 
	while (M--) {
		cin >> a >> b; // 연결된 컴퓨터들. 
		v[b].push_back(a); v[a].push_back(b); //쌍방향이기에. 
	}
	cout<<dfs(1, 0);
	return 0;
}



