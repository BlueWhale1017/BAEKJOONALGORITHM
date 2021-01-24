#include<iostream>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;
const int MAX = 10000; //#define MAX=10000
vector<int> v[MAX]; // ��ũ�帮��Ʈ�� �����Ҵ��� �ϱ� ���� ����. 
bool check[101] = { false, }; //dfs �󿡼� �湮�߳� ���߳��� üũ

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

	int N, M, a, b = 0; cin >> N; cin >> M; // a,b �� ��ǻ��, N�� ��ǻ���� ����, M�� ��ǻ�͵鳢�� ����Ǿ� �ִ� ����� ��. 
	while (M--) {
		cin >> a >> b; // ����� ��ǻ�͵�. 
		v[b].push_back(a); v[a].push_back(b); //�ֹ����̱⿡. 
	}
	cout<<dfs(1, 0);
	return 0;
}



