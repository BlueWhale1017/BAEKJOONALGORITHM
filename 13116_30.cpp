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

void Solve(int a, int b) {//최대공통조상노드 구하기. 그 후 그 값에 10을 곱해서 반환. 
	int k = 0;

	int a_ori = a; int b_ori = b;//원본값. 
	// 완전이진트리이기에, 자식 노드에 나누기 2 를 하면 바로위의 부모노드가 나옴. (int형으로 나누기에 양쪽 둘다 같음 12/2==6,13/2==6)
	queue<int> qa; queue<int> qb; 
	qa.push(a);
	qb.push(b);
	// 저장공간에 부모노드들의 값을 차례대로 저장하고, 그 값들을 서로 비교해보면서 가장 먼저 나오는 부모노드의 값을 *10 하여 리턴함. 
	while (a!=1) {
		a = a / 2;
		qa.push(a);
		//q의 형식으로 1 까지 다 들어간다. 
	}
	while (b != 1) {
		b = b / 2;
		qb.push(b);
		//q의 형식으로 1 까지 다 들어간다. 
	}
	
	if (a_ori <= b_ori) {
		int candidate = qa.front();//vector를 안 쓰고 queue로 한 이유는 그래야 큰 것부터 들어가고 나올 수 있기 때문. 
		while (1) {
			if (candidate == qb.front()) {//맞을경우 해당 값을 k에 넣고 반복문을 종료함. 
				k = candidate;
				break;
			}
			else {
				int cycle = qb.front();
				qb.pop();
				qb.push(cycle);//계속 순환함. 
				if (cycle == 1) {
					qa.pop();
					candidate = qa.front();
				}
			}
		}
	}
	else {//a>b-> 속도를 위해서 이렇게 함. 
		int candidate = qb.front();//vector를 안 쓰고 queue로 한 이유는 그래야 큰 것부터 들어가고 나올 수 있기 때문. 
		while (1) {
			if (candidate == qa.front()) {//맞을경우 해당 값을 k에 넣고 반복문을 종료함. 
				k = candidate;
				break;
			}
			else {
				int cycle = qa.front();
				qa.pop();
				qa.push(cycle);//계속 순환함. 
				if (cycle == 1) {
					qb.pop();
					candidate=qb.front();
				}
			}
		}
	}
	cout<< 10 * k<<'\n';
}






