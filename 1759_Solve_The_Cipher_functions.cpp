#include "1759_Solve_The_Cipher.h"

void Input() {
	cin >> L >> C; //C는 문자 종류의 개수, L은 단어의 총 길이. 
	for (int i = 0; i < C; i++) {
		char x = 0;
		cin >> x;
		words.push_back(x);
		check.push_back(1);
	}
}

void Cipher() {
	do {
		string s = "";
		for (int i = 0; i < C; i++) {
			if (check[i] == 0) {
				s = s + words[i];//처음에 sort로 정렬을 해 주었고, 그 이후로 next_permutation 함수로 작은 수부터 차례로 올라가기에 규칙을 만족함. 
			}
		}
		int mouem = 0;
		int jauem = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {//모음일경우. 
				mouem += 1;
			}
			else {
				jauem += 1;
			}
		}
		if (mouem < 1 || jauem < 2) {
			continue;
		}
		cout << s << '\n';
	} while (next_permutation(check.begin(), check.end()));//0과 1 밖에 없기에 순열이지만 조합처럼 작용. 
}


