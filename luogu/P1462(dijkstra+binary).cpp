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

//在 OJ 上写 Dijkstra，永远用：greater<pair<ll,int>>


// 定义一个极大值，表示“不可达”距离
// 1e18 远大于题目中所有可能的血量消耗之和
const ll INF = 1e18;

// n：城市数量
// m：道路数量
// b：最大允许损失的血量
int n, m;
ll b;

// f[i] 表示经过城市 i 需要缴纳的费用
vector<ll> f;

// 邻接表：g[u] 存 (v, w)
// 表示从 u 到 v 的路，掉血 w
vector<vector<pair<int,ll>>> g;//二维数组


//判定在最大城市收费 ≤ mid 时，能否走到终点
bool check(ll mid) {
    // 如果起点或终点收费都超过 mid
    // 那么路径一定不可行，直接返回 false
    if (f[1] > mid || f[n] > mid) return false;

    // dist[i] 表示从 1 到 i 的最小掉血量
    vector<ll> dist(n+1, INF);// 初始化为无穷大

    // 优先队列（小顶堆）
    // pair.first  = 当前累计掉血
    // pair.second = 当前城市编号
    // greater 让最小的掉血优先出队（Dijkstra）

    priority_queue<
        pair<ll,int>,
        vector<pair<ll,int>>,
        greater<pair<ll,int>>
        > pq;

    // 起点距离为 0（还没掉血）
    dist[1] = 0;
    pq.push(make_pair(0, 1));//pair<类型1, 类型2>(a, b)

    // 标准 Dijkstra 主循环
    while (!pq.empty()) {

        // 取出当前掉血最小的状态
        pair<ll,int> cur = pq.top(); 
        pq.pop();

        ll d = cur.first;   // 当前掉血
        int u = cur.second; // 当前城市编号

        // 如果该状态已经不是最优，跳过
        // （Dijkstra 的经典优化）
        if (d > dist[u]) continue;

        // 枚举从 u 出发的所有道路
        for (auto e : g[u]) {
            int v = e.first;  // 下一个城市
            ll w = e.second;  // 这条路的掉血

            // 如果城市 v 的费用 > mid
            // 表示这个城市在当前二分限制下不可用
            // 直接跳过
            if (f[v] > mid) continue;

            // 如果通过 u -> v 可以得到更小的掉血
            // 就更新 dist，并加入优先队列
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    // 最终判断到达 n 城市的最小掉血是否 ≤ b
    return dist[n] <= b;
}



signed main() {
    IOS;

  // 读入城市数、道路数、最大血量
    cin >> n >> m >> b;

    // 读入每个城市的过路费
    f.resize(n+1);//resize(n+1)调整数组大小为 n+1
    for (int i = 1; i <= n; i++) cin >> f[i];

    // 初始化邻接表
    g.assign(n+1, {});//assign(n+1,{})重新初始化，全部清空;{} 能代表“空 vector”

    // 读入道路信息
    // a <-> c，掉血 w
    for (int i = 0; i < m; i++) {
        int a, c;
        ll w;
        cin >> a >> c >> w;
        g[a].push_back({c, w});
        g[c].push_back({a, w});
    }

    // 二分左边界：
    // 起点和终点必须能进
    ll l = max(f[1], f[n]);

    // 二分右边界：
    // 所有城市费用中的最大值
    ll r = *max_element(f.begin()+1, f.end());//max_element(l, r)作用：返回区间 [l, r) 中最大元素的迭代器,注意：它返回的不是值，是“位置”
    //  ll r = 0;
    //   for (int i = 1; i <= n; i++)
    //   r = max(r, f[i]);

    // 如果在最大限制下都无法到达
    // 说明根本无解
    if (!check(r)) {
        cout << "AFK";
        return 0;
    }

    // 二分查找最小可行的最大城市费用
    while (l < r) {
        ll mid = (l + r) >> 1;

        // 如果 mid 可行，尝试更小的最大值
        if (check(mid)) 
            r = mid;
        else 
            l = mid + 1;
    }

    // 输出最小可行的最大城市费用
    cout << l;
}