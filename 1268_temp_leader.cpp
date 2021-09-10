#include<iostream>
using namespace std;
#define max 1000+1

int n = 0;
int arr[max][6] = { 0, };
bool visited[max][max] = { false, };
int answer = 0;

void input();
void calculate();
bool checked(int i, int r);
int output();

int main() {
	input();//input finished. 
	calculate();
	output();
}
int output() {
	for (int i = 1; i <= n; i++) {
		if (arr[i][0] == answer) {
			cout << i;
			return 0;
		}
	}
}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		arr[i][0] = -1;//모두 +1이 되기에 -1부터 시작함. 그럼 +1이 되어도 0부터 시작. 
	}//for the sum. 
}
void calculate() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int r = 1; r <= n; r++) {
				if (arr[i][j] == arr[r][j] && checked(i, r)) {//자기 자신과는 같으니 무조건 +1은 성립함. 단 모두 동일하게 적용되고 덧셈이기에 괜찮음. 
					arr[i][0] += 1;
					visited[i][r] = true; 
				}
			}
		}
	}
	answer = arr[1][0];
	for (int i = 2; i <= n; i++) {
		answer = answer < arr[i][0] ? arr[i][0] : answer; //같을 경우 전의 값이 들어가게 해아하기에 <를 사용함. 
	}
}

bool checked(int i, int r) { 
	if (visited[i][r] == true) {
		return false;
	}
	else return true;
}


//구현
// 기능별 구분
// 알고리즘 개선
// 전역변수 제거 
// 파일 분리
//효율성 개선
//안정성 개선
//활용성 개선

