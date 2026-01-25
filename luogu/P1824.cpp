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

//最大化  最近的两头牛之间的距离
//最大化最小距离
int n,m;
int a[100005];

bool check(ll mid){
    int cnt=1,place=0;  
    //先放第一头牛在第 0 个位置
    //当前cnt已放牛数量 = 1
    //place 记录上一次放牛的位置

    for(int i=1;i<n;i++){
        if(a[i]-a[place]>=mid){
            cnt++;
            place=i;
        }
    }
    if(cnt>=m)return true;
    else return false;
}

signed main(){
 IOS;
    cin>>n>>m;
    
    for (int i = 0; i < n; i++)cin>>a[i];

    sort(a,a+n);//把所有牛棚位置从小到大排序

    ll l=0,r=a[n-1]-a[0];//最小距离最小可以是 0,最大距离是最左到最右牛棚的距离

    while(l<r){
        ll mid=(l+r)>>1;
        if(check(mid)) l=mid+1;//","也能当做在括号里面；距离还能更大
        else r=mid;
    }


    cout<<l-1<<endl;// l 指向的是 第一个不满足的值,所以要l-1

 return 0;
}