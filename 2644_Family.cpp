#include<iostream>
#include<queue>
#define MAX 102
using namespace std;

int n = 0, m = 0; // n: 전체 사람의 수, m:부모 자식들 간의 관계 개수.
int num1=0, num2=0; // 촌수를 고려해야하는 번호. 
int x=0, y=0;//앞이 부모, 뒤가 자식.
int depth[MAX] = {};
int family[MAX][MAX] = {};
bool visit[MAX] = { false, };

queue <int> q;

void bfs(int i);
void Input();

int main() {
	Input();
	bfs(num1);

	if (depth[num2] != 0) cout << depth[num2] << endl;
	else cout << "-1" << endl;

	return 0;
}
void Input() {
	cin >> n; //전체 사람의 수
	cin >> num1 >> num2; // 촌수 계산해야하는 두사람 번호
	cin >> m; // 부모 자식간의 관계 개수

	int a = 0, b = 0;

	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		family[a][b] = 1;
		family[b][a] = 1;
	}
}
void bfs(int i) {
	visit[i] = true;
	q.push(i);
	int temp=0;
	while (!q.empty()) {
		temp = q.front(); q.pop();
		for (int j = 1; j <= n; j++) {
			if (family[temp][j] == 1 && !visit[j]){
				visit[j] = true;
				depth[j] = depth[temp] + 1;
				q.push(j);
			}
		}
	}
}

