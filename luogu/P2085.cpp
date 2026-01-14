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

//多路归并
struct P2085
{
    ll val;//值
    int id;//编号,第几个函数
    int x;//第几个值
    bool operator>(const P2085& a)const{
        return val>a.val;
    }
};
priority_queue<P2085,vector<P2085>,greater<P2085>> pq;

signed main(){
 IOS;
int n,m;
cin>>n>>m;

vector<ll> A(n),B(n),C(n);
for (int i = 0; i < n; i++)
{
    cin>>A[i]>>B[i]>>C[i];
}

for(int i=0;i<n;i++){
    ll v=A[i]*1LL+B[i]*1+C[i];
    pq.push({v,i,1});
}

for (int i = 0; i < m; i++)
{
    P2085 t=pq.top();
    pq.pop();

    cout<<t.val;
    if(i+1<m)cout<<' ';

    int id=t.id;
    int x=t.x+1;

    ll nextval=A[id]*1LL*x*x+B[id]*1LL*x+C[id];
    pq.push({nextval,id,x});
}

 return 0;
}