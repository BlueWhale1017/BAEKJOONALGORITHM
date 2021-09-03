#include<iostream>
#include<vector>
using namespace std;

//robot 객체를 만든다. 맵 밖으로 나가는 경우/로봇끼리 충돌하는 경우를 bool 출력으로 만든다. 
//그다음 경우의 수를 나눠서 시뮬레이션을 돌리면 될듯하다. 

struct Robot {
	int x;//좌표
	int y;
	int num;//몇 번째 로봇
	char facing; //현재 향하고 있는 방향
};

int a = 0, b = 0, n = 0, m = 0;
vector<Robot> Robots;

bool isOutOfWall(int y, int x);
pair<bool, int> isCrushedRobot(int robotNum, int y, int x);

int main() {
	cin >> a >> b;//size of the map
	cin >> n >> m;//number of the robots, number of the orders 

	for (int i = 0; i < n; i++) {//로봇의 초기 좌표
		int robotx=0, roboty=0;
		char face=' '; 

		cin >> robotx >> roboty >> face;

		Robot robot;
		robot.x = robotx, robot.y = roboty, robot.num = i, robot.facing = face;

		Robots.push_back(robot);
	}

	int len = Robots.size();//number of robots. 

	for (int i = 0; i < m; i++) {//로봇에게 내려지는 명령. 
		int number;//which robot?
		char order;//what to do.
		int repeat;//how many times. 

		cin >> number >> order >> repeat; //배열로 만들어서 그냥 메모리를 쓰면 O(n^2) 으로 끝낼수 있을듯. 

		for (int j = 0; j < len; j++) {//로봇의 숫자만큼 돌아가면서 체크. 
			if (Robots[j].num == number) {//해당 로봇이면 시뮬 작동. 
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
			else continue;//아님 패스. 
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


//효율성 개선 작업을 끝냈는가? 
//안전성 검증? 



