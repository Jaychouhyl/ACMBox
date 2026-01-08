#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
const int INF=0x7fffffff;

//贪心法
// signed main(){
//  IOS;
// int t;
// cin>>t;
// for (int i = 1; i <= t; i++)
// {
//     int n;
//     cin>>n;
//     int start=1,end=1,p=1;//p为扫描位置
//     int sum=0;
//     int maxsum=-INF;
//     for (int j = 1; j <= n; j++)
//     {
//         int a;
//         cin>>a;
//         sum+=a;
//         if (sum>maxsum)
//         {
//             maxsum=sum;
//             start=p;
//             end=j;
//         }
//         if (sum<0)
//         {
//             sum=0;
//             p=j+1;
//         }
//     }


//     cout<<"Case "<<i<<":"<<endl;
//     cout<<maxsum<<" "<<start<<" "<<end<<endl;
//     if (i!=t)
//     {
//         cout<<endl;
//     }

// }

//  return 0;
// }


//dp
// int dp[100005];//dp[i]表示以第i个数结尾的最大子段和
// signed main(){
//  IOS;
// int t;
// cin>>t;
// for (int i = 1; i <= t; i++){
//     int n;
//     cin>>n;

//     for (int i = 1; i <= n; i++)cin>>dp[i];

//     int start=1,end=1,p=1;//p为扫描位置
//     int maxsum=dp[1];

//     for (int j = 2; j <= n; j++){
//         if(dp[j-1]+dp[j]>=dp[j])dp[j]=dp[j-1]+dp[j];
//         else p=j;//小于就更新起点

//     if (dp[j]>maxsum)
//     {
//         maxsum=dp[j];
//         start=p;
//         end=j;
//     }
// }


//     cout<<"Case "<<i<<":"<<endl;
//     cout<<maxsum<<" "<<start<<" "<<end<<endl;
//     if (i!=t)cout<<endl;
// }

// }

//dp+单调队列(限制子序列最大长度的最大值)(前缀和)
deque<int> dq;
int pre[100005];//前缀和
signed main(){
 IOS;
int n,m;
cin>>n>>m;
for (int i = 1; i <= n; i++)cin>>pre[i];
for (int i = 1; i <= n; i++)pre[i]+=pre[i-1];

int ans=-1e8;
dq.push_back(0);//存储前缀和下标
for (int i = 1; i <= n; i++){
    while (!dq.empty()&&dq.front()<i-m)dq.pop_front();//维护窗口大小(最大长度为m,前面的下标出队)
    if(dq.empty()) ans=max(ans,pre[i]);//队列空说明子序列长度小于等于m
    else ans=max(ans,pre[i]-pre[dq.front()]);//更新答案,front为最小前缀和下标(注意是最小的值)
    while (!dq.empty()&&pre[dq.back()]>=pre[i])dq.pop_back();//维护单调递增队列(队首最小)
    dq.push_back(i);
}
    cout<<ans<<endl;
    return 0;
}