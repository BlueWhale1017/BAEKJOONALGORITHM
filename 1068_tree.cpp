#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 50 + 1
// global

vector<vector<int>> child_vec;//vector 안에다가 vector<int>를 넣는것. 즉, 이차원 벡터. 

int answer = 0, del_node = 0;

// 자식 노드를 dfs를 이용하여 센다.
// 자식 노드가 1개 있으면, 해당 노드가 삭제할 노드인지 확인한다.

void how_many_leaf(int now_node) {
    if (del_node == now_node) 
        return;
    
    int ch_size = child_vec[now_node].size();//바깥벡터 안의 첫 번째 벡터의 사이즈를 측정에 ch_size에 대입한다. 

    //이 경우 switch 문이 if-else 문보다 더 효율적. 

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
    //위의 두 가지의 경우, 노드가 없기 때문에 리프노드 하나가 되고 스위치 문을 탈출. answer에 +1을 더한다. 
    default://재귀 구조. 
        for (int ch_idx = 0; ch_idx < ch_size; ch_idx++)
            how_many_leaf(child_vec[now_node][ch_idx]); //노드별로 dfs 로 내려가면서 탐색. 
        break;
    }
}

int main() {
    // input 받아서 루트, 부모, 자식 처리하기 
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








