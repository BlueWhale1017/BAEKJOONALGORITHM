#include<iostream>
#include<vector>
using namespace std;

//robot ��ü�� �����. �� ������ ������ ���/�κ����� �浹�ϴ� ��츦 bool ������� �����. 
//�״��� ����� ���� ������ �ùķ��̼��� ������ �ɵ��ϴ�. 

struct Robot {
	int x;//��ǥ
	int y;
	int num;//�� ��° �κ�
	char facing; //���� ���ϰ� �ִ� ����
};

int a = 0, b = 0, n = 0, m = 0;
vector<Robot> Robots;

bool isOutOfWall(int y, int x);
pair<bool, int> isCrushedRobot(int robotNum, int y, int x);

int main() {
	cin >> a >> b;//size of the map
	cin >> n >> m;//number of the robots, number of the orders 

	for (int i = 0; i < n; i++) {//�κ��� �ʱ� ��ǥ
		int robotx=0, roboty=0;
		char face=' '; 

		cin >> robotx >> roboty >> face;

		Robot robot;
		robot.x = robotx, robot.y = roboty, robot.num = i, robot.facing = face;

		Robots.push_back(robot);
	}

	int len = Robots.size();//number of robots. 

	for (int i = 0; i < m; i++) {//�κ����� �������� ���. 
		int number;//which robot?
		char order;//what to do.
		int repeat;//how many times. 

		cin >> number >> order >> repeat; //�迭�� ���� �׳� �޸𸮸� ���� O(n^2) ���� ������ ������. 

		for (int j = 0; j < len; j++) {//�κ��� ���ڸ�ŭ ���ư��鼭 üũ. 
			if (Robots[j].num == number) {//�ش� �κ��̸� �ù� �۵�. 
				for (int r = 0; r < repeat; r++) {
					if (order == 'L') {
						if (Robots[r].facing == 'E') Robots[r].facing = 'N';
						else if (Robots[r].facing == 'W') Robots[r].facing = 'S';
						else if (Robots[r].facing == 'S') Robots[r].facing = 'E';
						else if (Robots[r].facing == 'N') Robots[r].facing = 'W';
						else continue;//wrong input. 
					}
					else if (order == 'R') {
						if (Robots[r].facing == 'E') Robots[r].facing = 'S';
						else if (Robots[r].facing == 'W') Robots[r].facing = 'N';
						else if (Robots[r].facing == 'S') Robots[r].facing = 'W';
						else if (Robots[r].facing == 'N') Robots[r].facing = 'E';
						else continue;//wrong input.
					}
					else if (order == 'F'){
						if (Robots[r].facing == 'E') Robots[r].x++;
						else if (Robots[r].facing == 'W') Robots[r].x--;
						else if (Robots[r].facing == 'N') Robots[r].y--;
						else if (Robots[r].facing == 'S') Robots[r].y++;
						else continue;//wrong input
					}
					if (isOutOfWall(Robots[r].y, Robots[r].x)) {
						cout << "Robot " << Robots[r].num << " crashes into the wall" << endl;
						return 0;
					}

					pair<bool, int> result = isCrushedRobot(Robots[j].num, Robots[j].y, Robots[j].x);

					if (result.first == true) {
						cout << "Robot " << Robots[j].num << " crashes into robot " << result.second << endl;
						return 0;
					}

				}
			}
			else continue;//�ƴ� �н�. 
		}
	}

	return 0;
}

bool isOutOfWall(int y, int x) {//out of map? 
	if (y<1 || y>b || x<1 || x > a) {
		return true;
	}
	else return false;
}

pair<bool, int> isCrushedRobot(int robotNum, int y, int x) {//Does robots crushed each others? 
	int len = Robots.size();//number of robots. 
	for (int i = 0; i < len; i++) {
		if (robotNum == Robots[i].num) continue;
		else {
			if (x == Robots[i].x && y == Robots[i].y) return make_pair(true, Robots[i].num);
		}
	}
	return make_pair(false, 0);
}


//ȿ���� ���� �۾��� ���´°�? 
//������ ����? 



