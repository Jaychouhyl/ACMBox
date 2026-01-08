#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>




signed main(){
 IOS;
    int m,n;
    cin>>m>>n;
    int temp,flag=0;
    int ans=0;
    queue<int> q;
    vector<int> hash(1005,0);// 标记单词是否在内存中，0表示不在，>=1表示在
    for (int i = 1; i <= n; i++)
    {
        cin>>temp;
        hash[temp]++;
        if(hash[temp]==1) flag++;

        if (flag<=m&&hash[temp]==1) 
        {
            q.push(temp);
            ans++;
        }
        if (flag>m&&hash[temp]==1)
        {
            int t=q.front();
            q.pop();
            hash[t]=0;
            q.push(temp);
            ans++;
        }
    }
    
cout<<ans<<endl;

 return 0;
}