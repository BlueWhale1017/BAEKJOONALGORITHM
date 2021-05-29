#include<iostream>
#include<stack>
using namespace std;

//#define MAX 500000

int N = 0;
int height = 0;//int height[MAX]={0, };->timeout
stack<pair<int, int>> s;//index and height

void Tower();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Tower();
	return 0;
}

void Tower() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> height;

		while (!s.empty()) {
			if (s.top().second > height) {
				cout << s.top().first << ' ';
				break;
			}
			s.pop();
		}
		if (s.empty()) {
			cout << "0 ";
		}
		s.push(make_pair(i, height));
	}
}

