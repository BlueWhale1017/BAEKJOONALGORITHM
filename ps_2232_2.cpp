#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int range_max(int l, int r, int mines[50001]);//�ش� ���� ������ ���� ū ���߷��� ���� ���ڸ� ã�� �Լ�.
void explosion(int l, int r, int mines[50001]);//��ź�� �翷���� ��Ʈ������ �Լ�. 

vector<int> answer;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int mines[50001];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> mines[i];
	}

	explosion(0, n - 1, mines);
	sort(answer.begin(), answer.end());

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] + 1 << '\n';
	}

	return 0;
}

int range_max(int l, int r, int mines[50001]) {
	int index = l;
	int val = mines[l];
	for (int i = l + 1; i <= r; i++) {
		if (val < mines[i]) {
			index = i;
			val = mines[i];
		}
	}
	return index;
}

void explosion(int l, int r, int mines[50001]) {
	int set_point = range_max(l, r, mines);

	answer.push_back(set_point);

	int curve_left = set_point;
	int curve_right = set_point;

	bool turn = true;

	while (turn) {
		turn = false;
		if (curve_left > l && mines[curve_left] > mines[curve_left - 1]) {
			turn = true;
			curve_left--;
		}
		if (curve_right < r && mines[curve_right] > mines[curve_right + 1]) {
			turn = true;
			curve_right++;
		}
	}
	if (curve_left > l) {
		explosion(l, curve_left-1, mines);
	}
	if (curve_right < r) {
		explosion(curve_right+1,r , mines);
	}
}

