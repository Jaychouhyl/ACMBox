#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int n;

map<char, pair<char, char>> a; // 改为map,存储每个节点的左右孩子
char root; // 记录根节点

void dfs(char l){ // 参数改为char类型
    if(l == '*') return ; // 空节点直接返回
    
    cout<<l; // 输出当前节点
    
    dfs(a[l].first);  // 遍历左子树
    dfs(a[l].second); // 遍历右子树
}

signed main(){
 IOS;
cin>>n;
for (int i = 1; i <= n; i++)
{
    char b,c,d;
    cin>>b>>c>>d;
    a[b] = {c, d}; // 存储b节点的左孩子c和右孩子d
    if(i == 1) root = b; // 第一个节点是根节点
    cin.ignore();
}
dfs(root); // 从根节点开始遍历

 return 0;
}