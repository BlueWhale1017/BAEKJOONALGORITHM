//그냥 보드는 0, 뱀은 1, 사과는 2
//라이브러리 및 정의, 전역변수, 함수, 메인
#include<iostream>
#include<vector>
#include<queue>
#define P pair<int,int>
using namespace std;

int n = 0, k = 0, l = 0, dir = 0; //보드의 크기, 사과의 개수, 방향전환 횟수, 그리고 방향. 
int Board[101][101] = { 0, }; // 보드. 0을 벽 또는 자기자신으로 설정. 즉 0을 만나면 종료되어야 함으로 최대 N값인 100 보다 1 더 크도록 설정함. 
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
vector<P> snake;
queue<P> q;
int time = 0; //시간 

void Turn(char c) {
	if (c == 'L') {
		dir = (dir < 1) ? 3 : dir - 1;
	}
	else {
		dir = (dir > 2) ? 0 : dir + 1;
	}
}
void Input_Apple() { //사과를 입력받는 함수. 
	cin >> k;
	int r = 0, c = 0;
	while (k--) {
		cin >> r >> c;
		Board[r][c] = 2;
	}
}
void Input_Turn_Snake() {//뱀의 방향전환과 이동. 
	cin >> l;
	int d=0; char c;
	while (l--) {
		cin >> d >> c;
		q.push(P(d, c));
	}
}
void Move() {//뱀은 1x1 에서 출발하여 처음에는 오른쪽으로만 움직인다. 
	while (true) {
		if (!q.empty()) {
			if (q.front().first == time) {
				Turn(q.front().second);
				q.pop();
			}
		}
		time++;

		//다음지점의 좌표. 
		int ax = snake[snake.size() - 1].first + dx[dir];
		int ay = snake[snake.size() - 1].second + dy[dir];

		if (ax<1 || ay<1 || ax>n || ay>n) break; //맵의 벽에 부딪혔을 때
		if (Board[ax][ay] == 1) break; //뱀의 몸통에 닿았을 때. 즉, 다음 부분이 뱀의 몸통일때(좌표상으로는 1의 값일 때.) 

		if (Board[ax][ay] == 0) { // 다음 지점이 평범한 땅이면. 좌표상으로는 0일 때.  
			Board[snake[0].first][snake[0].second] = 0; // 꼬리부분을 0으로, 즉 삭제. 
			snake.erase(snake.begin()); //역시 꼬리부분 삭제. 다만 이번에는 벡터에서. 
		}
		//다음 지점이 평범한 땅이 아니고 사과가 있을 경우. 좌표상으로는 2 일때. 
		snake.push_back(P(ax, ay));
		Board[ax][ay] = 1;
	}
	cout << time << "\n";
}
void Debug(int n) { //확인용 보드 출력 
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << Board[i][j] << " ";
		}
		cout << "\n";
	}
}
int main() {//메인함수. 백준 제출시에는 Debug(n) 함수를 제거하고 제출. 
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
void Input1_Total() {//인풋을 한번에 완료시킴. -> 인풋을 기능별로 쪼개는 연습중이라 사용하지 않음. (기타 모든 기능들도 개별 기능대로 쪼개는 것을 선호. ) 
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
