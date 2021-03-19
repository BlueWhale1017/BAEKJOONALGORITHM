#include<iostream>
#include<cstdlib>
#define MAX 101
using namespace std;

void Input();
void Change();

int N = 0, sum=0;
char num[MAX] = {0, };

int main(void) {
	Input();
	Change();
	cout << sum << endl;
	return 0;
}
void Input() {
	cin >> N;
	cin >> num;
}
void Change() {
	for(int i=0;i<N;i++) {
		sum += num[i]-'0';
	}
}
