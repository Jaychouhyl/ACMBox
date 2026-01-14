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
//“结构 + 权值” 的整体相等性判断,局部性质 + 全局最优

//哈希基数结构哈希中的“扰动常数”，作用是：
//区分左右子树
//放大权值的影响
//避免大量哈希冲突
const unsigned long long BASE1 = 1315423911;//区分左右结构,这是一个经验值
const unsigned long long BASE2 = 11400714819323198485;//让“点权”也产生巨大影响

int n;//节点总数
int val[1000005];//节点权值
int lson[1000005], rson[1000005];//节点 i的左右儿子,-1表示空节点
int sz[1000005];//以i为根的子树大小
unsigned long long H[1000005], RH[1000005];//正向结构哈希 & 镜像结构哈希
int ans = 1;//初始化为 1，因为单节点一定对称



void dfs(int u) {//后序 DFS，左右根
    if (u == -1) return;//空节点直接返回
    // 访问左、右子树
    dfs(lson[u]);
    dfs(rson[u]);


    //当前根的处理
    int L = lson[u];
    int R = rson[u];

    // 子树大小，任何节点至少包含自己
    sz[u] = 1;
    //每次都是加上1个子树的大小
    if (L != -1) sz[u] += sz[L];
    if (R != -1) sz[u] += sz[R];


    // 正向哈希： 根 + 左 + 右
    //左空用 1234567
    //右空用 7654321
    unsigned long long hl = (L == -1 ? 1234567 : H[L]);
    unsigned long long hr = (R == -1 ? 7654321 : H[R]);

    H[u] = (hl ^ (hr * BASE1)) + val[u] * BASE2;//按位异或操作，不同为1
    //因为这样对于顺序敏感，左右子树交换位置后哈希变化
    //不会进位，混合均匀
    //加法有进位 → 低位影响高位
    //XOR 无进位 → 每一位独立
    //把左右子树 + 当前节点的信息，混合成一个不可逆指纹”
    //用 u 的左子树哈希、右子树哈希、以及 u 自身的权值，构造 u 这棵子树的哈希值

    //BASE1:右子树的信息在数值空间中发生“位级扩散”
    //从而保证：(左, 右) ≠ (右, 左)
    //左子树：直接参与哈希计算
    //右子树：先乘一个“大数”，再混进来
    //BASE2让节点权值在哈希中占据高权重，
    //避免：结构一样，权值不同 → 哈希相同

    // 镜像哈希： 根 + 右 + 左
   
    unsigned long long rhl = (R == -1 ? 1234567 : RH[R]);
    unsigned long long rhr = (L == -1 ? 7654321 : RH[L]);
    RH[u] = (rhl ^ (rhr * BASE1)) + val[u] * BASE2;
    

    // 判断是否对称
    if (H[u] == RH[u]) {
        ans = max(ans, sz[u]);
    }
}

signed main(){
 IOS;
 cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> lson[i] >> rson[i];
    }

    dfs(1);

    cout << ans << "\n";


 return 0;
}