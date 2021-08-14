#include "1759_Solve_The_Cipher.h"

int main() {

	Input();

	sort(words.begin(), words.end()); //sorting. 

	for (int i = 0; i < L; i++) {
		check[i] = 0;
	}//옆으로 값을 넣어 해당하는 만큼 0으로 만들어준다. 예제의 경우 000011 

	Cipher();

	return 0;
}





