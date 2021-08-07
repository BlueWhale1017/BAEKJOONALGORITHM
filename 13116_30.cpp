#include<iostream>
#include<queue>
using namespace std;

void Solve(int a, int b);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T = 0;
	int a=0, b = 0;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		cin >> a; cin >> b;
		Solve(a, b);
	}
	return 0;
}

void Solve(int a, int b) {//�ִ���������� ���ϱ�. �� �� �� ���� 10�� ���ؼ� ��ȯ. 
	int k = 0;

	int a_ori = a; int b_ori = b;//������. 
	// ��������Ʈ���̱⿡, �ڽ� ��忡 ������ 2 �� �ϸ� �ٷ����� �θ��尡 ����. (int������ �����⿡ ���� �Ѵ� ���� 12/2==6,13/2==6)
	queue<int> qa; queue<int> qb; 
	qa.push(a);
	qb.push(b);
	// ��������� �θ������ ���� ���ʴ�� �����ϰ�, �� ������ ���� ���غ��鼭 ���� ���� ������ �θ����� ���� *10 �Ͽ� ������. 
	while (a!=1) {
		a = a / 2;
		qa.push(a);
		//q�� �������� 1 ���� �� ����. 
	}
	while (b != 1) {
		b = b / 2;
		qb.push(b);
		//q�� �������� 1 ���� �� ����. 
	}
	
	if (a_ori <= b_ori) {
		int candidate = qa.front();//vector�� �� ���� queue�� �� ������ �׷��� ū �ͺ��� ���� ���� �� �ֱ� ����. 
		while (1) {
			if (candidate == qb.front()) {//������� �ش� ���� k�� �ְ� �ݺ����� ������. 
				k = candidate;
				break;
			}
			else {
				int cycle = qb.front();
				qb.pop();
				qb.push(cycle);//��� ��ȯ��. 
				if (cycle == 1) {
					qa.pop();
					candidate = qa.front();
				}
			}
		}
	}
	else {//a>b-> �ӵ��� ���ؼ� �̷��� ��. 
		int candidate = qb.front();//vector�� �� ���� queue�� �� ������ �׷��� ū �ͺ��� ���� ���� �� �ֱ� ����. 
		while (1) {
			if (candidate == qa.front()) {//������� �ش� ���� k�� �ְ� �ݺ����� ������. 
				k = candidate;
				break;
			}
			else {
				int cycle = qa.front();
				qa.pop();
				qa.push(cycle);//��� ��ȯ��. 
				if (cycle == 1) {
					qb.pop();
					candidate=qb.front();
				}
			}
		}
	}
	cout<< 10 * k<<'\n';
}






