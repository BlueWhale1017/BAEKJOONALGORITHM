#include "1759_Solve_The_Cipher.h"

void Input() {
	cin >> L >> C; //C�� ���� ������ ����, L�� �ܾ��� �� ����. 
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
				s = s + words[i];//ó���� sort�� ������ �� �־���, �� ���ķ� next_permutation �Լ��� ���� ������ ���ʷ� �ö󰡱⿡ ��Ģ�� ������. 
			}
		}
		int mouem = 0;
		int jauem = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {//�����ϰ��. 
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
	} while (next_permutation(check.begin(), check.end()));//0�� 1 �ۿ� ���⿡ ���������� ����ó�� �ۿ�. 
}


