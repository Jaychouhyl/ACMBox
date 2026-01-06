#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define ll long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;



signed main(){
    IOS;
    int n,m;
    cin>>n>>m;
    list<int> lst;
    for (int i = 1; i <=n; i++)
    {
        lst.push_back(i);
    }
    list<int>::iterator it = lst.begin();
    while (lst.size()>1)
    {
         for ( int i = 1; i < m; i++)
         {
            it++;
            if(it==lst.end())it=lst.begin();;
         }
         cout<<*it<<" ";
         list <int> ::iterator next=++it;
         if(next==lst.end())next=lst.begin();
         it=lst.erase(--it);
        it=next;

    }
    cout<<*it<<endl;
    
 return 0;
}