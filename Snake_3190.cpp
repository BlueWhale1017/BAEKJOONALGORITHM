//�׳� ����� 0, ���� 1, ����� 2
//���̺귯�� �� ����, ��������, �Լ�, ����
#include<iostream>
#include<vector>
#include<queue>
#define P pair<int,int>
using namespace std;

int n = 0, k = 0, l = 0, dir = 0; //������ ũ��, ����� ����, ������ȯ Ƚ��, �׸��� ����. 
int Board[101][101] = { 0, }; // ����. 0�� �� �Ǵ� �ڱ��ڽ����� ����. �� 0�� ������ ����Ǿ�� ������ �ִ� N���� 100 ���� 1 �� ũ���� ������. 
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<P> snake;
queue<P> q;
int time = 0; //�ð� 

void Turn(char c) {
	if (c == 'L') {
		dir = (dir < 1) ? 3 : dir - 1;
	}
	else {
		dir = (dir > 2) ? 0 : dir + 1;
	}
}
void Input_Apple() { //����� �Է¹޴� �Լ�. 
	cin >> k;
	int r = 0, c = 0;
	while (k--) {
		cin >> r >> c;
		Board[r][c] = 2;
	}
}
void Input_Turn_Snake() {//���� ������ȯ�� �̵�. 
	cin >> l;
	int d=0; char c;
	while (l--) {
		cin >> d >> c;
		q.push(P(d, c));
	}
}
void Move() {//���� 1x1 ���� ����Ͽ� ó������ ���������θ� �����δ�. 
	while (true) {
		if (!q.empty()) {
			if (q.front().first == time) {
				Turn(q.front().second);
				q.pop();
			}
		}
		time++;

		//���������� ��ǥ. 
		int ax = snake[snake.size() - 1].first + dx[dir];
		int ay = snake[snake.size() - 1].second + dy[dir];

		if (ax<1 || ay<1 || ax>n || ay>n) break; //���� ���� �ε����� ��
		if (Board[ax][ay] == 1) break; //���� ���뿡 ����� ��. ��, ���� �κ��� ���� �����϶�(��ǥ�����δ� 1�� ���� ��.) 

		if (Board[ax][ay] == 0) { // ���� ������ ����� ���̸�. ��ǥ�����δ� 0�� ��.  
			Board[snake[0].first][snake[0].second] = 0; // �����κ��� 0����, �� ����. 
			snake.erase(snake.begin()); //���� �����κ� ����. �ٸ� �̹����� ���Ϳ���. 
		}
		//���� ������ ����� ���� �ƴϰ� ����� ���� ���. ��ǥ�����δ� 2 �϶�. 
		snake.push_back(P(ax, ay));
		Board[ax][ay] = 1;
	}
	cout << time << "\n";
}
void Debug(int n) { //Ȯ�ο� ���� ��� 
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Board[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {//�����Լ�. ���� ����ÿ��� Debug(n) �Լ��� �����ϰ� ����. 
	cin >> n;
	Input_Apple();
	Input_Turn_Snake();
	Board[1][1] = 1;
	snake.push_back(P(1, 1));
	dir = 1;
	Debug(n);
	Move();
	return 0;
}

/*
void Input1_Total() {//��ǲ�� �ѹ��� �Ϸ��Ŵ. -> ��ǲ�� ��ɺ��� �ɰ��� �������̶� ������� ����. (��Ÿ ��� ��ɵ鵵 ���� ��ɴ�� �ɰ��� ���� ��ȣ. ) 
	cin >> N;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		apple_location.push(pair<int, int>());
	}
	cin >> L;
	for (int i = 1; i <= L; i++) {
		snake_move.push(pair<int, char>());
	}
}*/
