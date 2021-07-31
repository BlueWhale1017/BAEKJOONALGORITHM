#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 50 + 1
// global

vector<vector<int>> child_vec;//vector �ȿ��ٰ� vector<int>�� �ִ°�. ��, ������ ����. 

int answer = 0, del_node = 0;

// �ڽ� ��带 dfs�� �̿��Ͽ� ����.
// �ڽ� ��尡 1�� ������, �ش� ��尡 ������ ������� Ȯ���Ѵ�.

void how_many_leaf(int now_node) {
    if (del_node == now_node) 
        return;
    
    int ch_size = child_vec[now_node].size();//�ٱ����� ���� ù ��° ������ ����� ������ ch_size�� �����Ѵ�. 

    //�� ��� switch ���� if-else ������ �� ȿ����. 

    switch (ch_size) {
    case 0:
        answer++; 
        return;
        break;
    case 1:
        if (child_vec[now_node][0] == del_node) {
            answer++; 
            break;
        }
    //���� �� ������ ���, ��尡 ���� ������ ������� �ϳ��� �ǰ� ����ġ ���� Ż��. answer�� +1�� ���Ѵ�. 
    default://��� ����. 
        for (int ch_idx = 0; ch_idx < ch_size; ch_idx++)
            how_many_leaf(child_vec[now_node][ch_idx]); //��庰�� dfs �� �������鼭 Ž��. 
        break;
    }
}

int main() {
    // input �޾Ƽ� ��Ʈ, �θ�, �ڽ� ó���ϱ� 
    int N=0, root=0; 
    cin >> N;
    child_vec.resize(N);

    for (int in_idx = 0; in_idx < N; in_idx++) {
        int parent; 
        cin >> parent;
        if (parent != -1) 
            child_vec[parent].push_back(in_idx);
        else 
            root = in_idx;
    }

    cin>>del_node;

    how_many_leaf(root);

    cout << answer;
    return 0;
}








