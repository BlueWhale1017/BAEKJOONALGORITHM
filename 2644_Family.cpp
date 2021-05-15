#include<iostream>
#include<queue>
#define MAX 102
using namespace std;

int n = 0, m = 0; // n: ��ü ����� ��, m:�θ� �ڽĵ� ���� ���� ����.
int num1=0, num2=0; // �̼��� ����ؾ��ϴ� ��ȣ. 
int x=0, y=0;//���� �θ�, �ڰ� �ڽ�.
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
	cin >> n; //��ü ����� ��
	cin >> num1 >> num2; // �̼� ����ؾ��ϴ� �λ�� ��ȣ
	cin >> m; // �θ� �ڽİ��� ���� ����

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

