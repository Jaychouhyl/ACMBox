#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include<cstring>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;


char pre[30], post[30];

long long dfs(int pl, int pr, int ql, int qr) {
    if (pl >= pr) return 1;  // 0 或 1 个结点,只有一种结构

    // pre[pl] 是根，pre[pl+1] 是某个子树的根，前序遍历中，根的后面第一个，一定是“某棵子树的根”
    char c = pre[pl + 1];

    int k = ql;
    while (post[k] != c) k++;  // 在后序中找位置

    int leftSize = k - ql + 1;//这个子树到底有多大，别漏掉根结点

    // 只有一个子树，没有左右之分（左右不确定）
    if (k == qr - 1) {
        return 2 * dfs(pl + 1, pl + leftSize, ql, k);//从根开始加leftSize个结点
    }

    // 有左右子树
    long long L = dfs(pl + 1, pl + leftSize, ql, k);
    long long R = dfs(pl + leftSize + 1, pr, k + 1, qr - 1);
    return L * R;//左右是独立的
}



signed main(){
 IOS;
 cin >> pre >> post;

    int n = 0;
    while (pre[n]) n++;  // 手算长度

    cout << dfs(0, n - 1, 0, n - 1);
    return 0;
}