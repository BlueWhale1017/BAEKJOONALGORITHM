#include<iostream>
using namespace std;

int main() {
	int a=0, b=0, x=0, y=0;
	cin >> a >> b;

	while (true) {
		if (a == 1) {
			y += b - 1;
			break;
		}
		else if (b == 1) {
			x += a - 1;
			break;
		}
		if (a > b) {
			x += a / b;
			a %= b;
		}
		else {
			y += b / a, b %= a;
		}
	}
	cout << x <<' '<< y;
	return 0;
}

