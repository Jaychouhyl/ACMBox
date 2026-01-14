#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;


char a[1050];  
int n;

void dfs(int l, int r) {
    int has0 = 0, has1 = 0;// 标记区间内是否有0或1

    // 检查当前区间内是否有0或1
    for (int i = l; i <= r; i++) {
        if (a[i] == '0') has0 = 1;
        else has1 = 1;
    }
    
    //递归构造左右子树（区间继续拆分） 左 右
    if (l < r) {
        int mid = (l + r)>>1;// 取中点
        dfs(l, mid);
        dfs(mid + 1, r);
    }
    
    //输出当前结点类型（后序遍历）cout<<type，根
    if (has0 && has1) cout << 'F';
    else if (has0) cout << 'B';
    else cout << 'I';
}


signed main(){
 IOS;

    cin >> n;
    cin >> a;              
    int len = (1 << n);// 2的n次方
    dfs(0, len - 1);
    return 0;
}