#include<iostream>
using namespace std;
#define MAX 64+1

char Matrix[MAX][MAX];//1 또는 0

void Input(int n);
int check_area(int x, int y, int n);
void solve(int x, int y, int n);

/*
0. Input
1. 4등분을 한다.
2. 모두 0일경우 0을 출력, 모두 1일경우 1을 출력, 그 외의 경우 다시 해당 부분을 4등분.
3. 반복. 
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //speed up code.
    int N = 0;//전역변수 안쓰고 main 에서 인풋? 
    cin >> N;
	Input(N);
    solve(0, 0, N);
	return 0;
}

void Input(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Matrix[i][j];
        }
    }
}
int check_area(int x, int y, int n) {
    int temp = Matrix[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (temp != Matrix[i][j]) return 0;
        }
    }
    return 1;
}
void solve(int x, int y, int n) {
    if (n == 1) cout << Matrix[x][y];
    else {
        if (check_area(x, y, n) == 1) {
            cout << Matrix[x][y];
        }
        else {
            cout << "(";
            solve(x, y, n / 2);
            solve(x, y + n / 2, n / 2);
            solve(x + n / 2, y, n / 2);
            solve(x + n / 2, y + n / 2, n / 2);
            cout << ")";
        }

    }

}



