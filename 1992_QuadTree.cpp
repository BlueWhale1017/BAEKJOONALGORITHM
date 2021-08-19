#include<iostream>
using namespace std;
#define MAX 64+1

char Matrix[MAX][MAX];//1 �Ǵ� 0

void Input(int n);
int check_area(int x, int y, int n);
void solve(int x, int y, int n);

/*
0. Input
1. 4����� �Ѵ�.
2. ��� 0�ϰ�� 0�� ���, ��� 1�ϰ�� 1�� ���, �� ���� ��� �ٽ� �ش� �κ��� 4���.
3. �ݺ�. 
*/
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //speed up code.
    int N = 0;//�������� �Ⱦ��� main ���� ��ǲ? 
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



