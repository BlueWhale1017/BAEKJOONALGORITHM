//라이브러리 및 정의, 전역변수, 함수들, 메인함수 순으로 정렬. 
#include<iostream>
#include<queue>
using namespace std;
#define MAX (3*10^6)+1

int L = 0, Ml = 0, Mk = 0, Cammo = 0; // 기관총 진지 앞쪽 길의 거리, 기관총의 유효 사거리, 데미지, 수평 세열 지향성 지뢰의 개수
int Z[MAX] = { 0, }; //i 지점의 좀비 체력. 

 /*
 멀리 있을 때는 계속 광역 데미지인 기관총을 쏘다가, 가까이 다가와서 거리가 1m 밖에 남지 않았을 때 좀비의 체력>기관총의 파괴력인 경우에 클레이모어를 터트려 끔살시킬 수 있음.
 단, 좀비의 체력<=기관총의 파괴력인 경우 기관총을 쏘는것이 더 나은 선택. L개의 줄에 걸쳐서 정수가 하나씩 주어진다고 함으로 좀비는 겹쳐 서있지 않는다.
 정리하자면,
 1) 거리가 1보다 클 경우->무조건 기관총 사용
 2) 거리가 1일 경우:
 1. 기관총으로 제압이 가능할 경우. Z[1]<=Mk -> 기관총으로 제압
 2. 기관총으로 제압이 안될 경우. Z[1]>Mk
 2-1: Cammo 있음->사용
 2-2: 수류탄 없음->죽음
 끝까지 안죽을 경우-> Yes 출력. 아닐 경우-> No 출력.
 */

void Input() {//초기 설정. 
	cin >> L;
	cin >> Ml >> Mk;
	cin >> Cammo;

	for (int i = 1; i <= L; i++) {
		cin >> Z[i];
	}
}
void Survive() {
//시뮬레이션 시작. Z[i]가 0일 경우 좀비는 없거나 죽은 상태. 양수일 경우 해당 지점에 위치한 좀비의 체력으로 생각하면 됨. 
//기관총 진지가 가만히 있고 좀비가 다가오는 것이나, 좀비가 가만히 있고 기관총 진지가 다가가는 것이나 물리적으로는 같은 현상이다. 상대속도만 같으면 된다. 
//그러므로 포문을 통해 L까지 다가가는 식으로 문제를 풀도록 한다. 
	for (int i = 1; i <= L; i++) {
		if (Z[i] == 0) {//기관총 사용. 
			for (int j = i; j <= Ml + i - 1; j++) {//사정거리안의 모든 좀비들에게 난사. 
				if (Z[j] >= 1) {//좀비가 있을 경우. 
					if (Z[j] >= Mk) { //좀비가 총탄의 데미지보다 체력이 많을 경우. 
						Z[j] = Z[j] - Mk; //총알에 맞아서 체력이 깎임.
					}
					else { // 좀비가 총탄의 데미지보다 체력이 적거나 같을 경우. 
						Z[j] = 0;
					}
				}
				else {//좀비가 없을 경우.
					continue;
				}
			}
		}
		else {//좀비까지의 거리가 1일 경우. 
			if (Z[i] <= Mk) {//가장 앞에 있는 좀비의 체력이 기관총의 데미지보다 낮은 경우에는, 사거리 안의 모든 좀비에게 기관총 사격. -Mk
				for (int j = i; j <= Ml + i - 1; j++) {
					if (Z[j] >= Mk) {
						Z[j] = Z[j] - Mk;
					}
					else {
						Z[j] = 0;
					}
				}
			}
			else {//기관총으로 제압이 불가능할 경우. 
				if (Cammo >= 1) {//수류탄이 있으면 바로 사용. 
					Z[1] = 0;
					Cammo--;
				}
				else {//수류탄도 없는 경우. 
					cout << "NO" << "\n";
					break;
				}
			}
		}
		if (Ml + i - 1 == L) {//맥시멈 사거리 도달시 사거리 감소. 런타임 에러 방지용. 
			Ml--;
		}
	}
	cout << "YES" << "\n";
}
int main(void) {
	Input();
	Survive();
	return 0;
}
