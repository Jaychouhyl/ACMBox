#include <iostream>
#include <queue>
using namespace std;
int n, m;
int data[100005];
int T;
queue<int> teamQueue;            // 小组顺序队列
queue<int> groupQueue[305];      // 每个小组的元素队列
bool inQueue[305] = {false};     // 小组是否在队列中

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }
    cin >> T;
    while (T--) {
        string op;
        cin >> op;

        if (op == "push") {
            int x;
            cin >> x;
            int g = data[x];

            if (!inQueue[g]) {
                teamQueue.push(g);
                inQueue[g] = true;
            }
            groupQueue[g].push(x);
        }
        else if (op == "pop") {
            int g = teamQueue.front();
            int x = groupQueue[g].front();
            groupQueue[g].pop();

            cout << x << '\n';

            if (groupQueue[g].empty()) {
                teamQueue.pop();
                inQueue[g] = false;
            }
        }
    }

    return 0;
}
