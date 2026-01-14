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


priority_queue<ll,vector<ll>,greater<ll>>pq;
signed main(){
 IOS;

 int n;
 cin>>n;
 int x;
 while (n--)
 {
    cin>>x;
    pq.push(x); 
 }

 ll ans=0; // 累计总代价
 while(pq.size()>1){
    ll a=pq.top();
    pq.pop();
    ll b=pq.top();
    pq.pop();
    ans+=a+b;
    pq.push(a+b);
 }
    cout<<ans<<endl;
 return 0;
}