#include "1759_Solve_The_Cipher.h"

int main() {

	Input();

	sort(words.begin(), words.end()); //sorting. 

	for (int i = 0; i < L; i++) {
		check[i] = 0;
	}//������ ���� �־� �ش��ϴ� ��ŭ 0���� ������ش�. ������ ��� 000011 

	Cipher();

	return 0;
}





