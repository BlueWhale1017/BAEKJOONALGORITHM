#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 500000+1
//N은 홀수
int arr[MAX];
int numbers[8001] = { 0, };

double avg = 0; //소수점 처리 아직 안함. 

void Input(int N);
double Average(int n);
void Middle(int n);
void Most(int n);
void Range(int n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	Input(n);

	Average(n);
	cout << Average(n) << '\n';
	Middle(n);
	Most(n);
	Range(n);
	return 0;
}
void Input(int N) {
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		numbers[arr[i] + 4000]++;
	}
	sort(arr, arr + N);
}
double Average(int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	int average = round((double)sum / n);
	return average;
}
void Middle(int n) {
	int mid_point = n / 2;
	cout << arr[mid_point] << endl;
}
void Most(int n) {
	int max = 0, flag = 0;

	for (int i = 0; i < 8001; i++) {
		if (numbers[i] > max) max = numbers[i], flag = i;
	}
	for (int i = flag + 1; i < 8001; i++) {
		if (numbers[i] == max) {
			max = numbers[i];
			flag = i;
			break;
		}
	}
	cout << flag - 4000 << endl;
}
void Range(int n) {
	cout << arr[n - 1] - arr[0] << endl;
}

